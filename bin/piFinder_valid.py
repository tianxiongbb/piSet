#! /usr/bin/env python
# -*- coding: utf-8 -*-
import os
import sys
import re
import bb_basic as bb


def main():
    if len(sys.argv) < 2:
        bb.fun_print_help("your.bed", "compared.bed", "result.out.prefix")
    dict_exon_yours = read_exons(sys.argv[1])
    dict_exon_compared = read_exons(sys.argv[2])
    dict_intron_yours = extract_intron(dict_exon_yours)
    dict_intron_compared = extract_intron(dict_exon_compared)
    dict_gene_yours = extract_gene(dict_exon_yours)
    dict_gene_compared = extract_gene(dict_exon_compared)
    dict_over = identify_overlap(dict_gene_yours, dict_gene_compared)
    dict_over_intron = calculate_overed_intron(dict_over, dict_intron_yours, dict_intron_compared)
    dict_tss_distance = calculate_tss_distance(dict_over, dict_gene_yours, dict_gene_compared)
    dict_tes_distance = calculate_tes_distance(dict_over, dict_gene_yours, dict_gene_compared)
    write_result(dict_gene_yours, dict_gene_compared, dict_over, dict_tss_distance, dict_tes_distance, dict_over_intron, sys.argv[3])

# --------functions--------
def write_result(dict_gene_yours, dict_gene_compared, dict_over, dict_tss_distance, dict_tes_distance, dict_over_intron, path):
    file_over = bb.fun_open_file(path + ".over", "w")
    file_new = bb.fun_open_file(path + ".new", "w")
    for pi in LIST_NEW:
        file_new.write(pi + "\n")
    file_new.close()
    file_over.write("pi_name\toverlapped_pi_name\ttss_distance\ttes_distance\tintron_number\trecalled_intron_number\tnew_intron_number\n")
    for pi in dict_gene_compared:
        file_over.write(pi + "\t") # pi_name
        if dict_over[pi] == []:
            file_over.write("-1\t")
        else:
            file_over.write(",".join(dict_over[pi]) + "\t") # ovverlapped pi_name
        file_over.write(str(dict_tss_distance[pi]) + "\t") # tss distance
        file_over.write(str(dict_tes_distance[pi]) + "\t") # tss distance
        file_over.write("%s\t%s\t%s\t%s\n"%(dict_over_intron[pi][0], dict_over_intron[pi][1], dict_over_intron[pi][2], dict_over_intron[pi][3])) # intron recall
    file_over.close()


def calculate_tes_distance(dict_over, dict_gene_yours, dict_gene_compared):
    dict_tes_distance = {}
    for pi in dict_gene_compared:
        dict_tes_distance[pi] = -1
        if pi in dict_over:
            if dict_gene_compared[pi][3] == "+":
                tes1 = dict_gene_compared[pi][2] 
            else:
                tes1 = dict_gene_compared[pi][1] 
            distance = 1000000
            for pi2s in dict_over[pi]:
                if dict_gene_yours[pi2s][3] == "+":
                    tes2 = dict_gene_yours[pi2s][2] 
                else:
                    tes2 = dict_gene_yours[pi2s][1] 
                if abs(tes2 - tes1) < distance:
                    dict_tes_distance[pi] = abs(tes2 - tes1)
    return dict_tes_distance


def calculate_tss_distance(dict_over, dict_gene_yours, dict_gene_compared):
    dict_tss_distance = {}
    for pi in dict_gene_compared:
        dict_tss_distance[pi] = -1
        if pi in dict_over:
            if dict_gene_compared[pi][3] == "+":
                tss1 = dict_gene_compared[pi][1] 
            else:
                tss1 = dict_gene_compared[pi][2] 
            distance = 1000000
            for pi2s in dict_over[pi]:
                if dict_gene_yours[pi2s][3] == "+":
                    tss2 = dict_gene_yours[pi2s][1] 
                else:
                    tss2 = dict_gene_yours[pi2s][2] 
                if abs(tss2 - tss1) < distance:
                    dict_tss_distance[pi] = abs(tss2 - tss1)
    return dict_tss_distance


def calculate_overed_intron(dict_over, dict_intron_yours, dict_intron_compared):
    dict_over_intron = {}
    for pi in dict_intron_compared:
        dict_over_intron[pi] = [len(dict_intron_compared[pi]), 0, 0, 0]
        if pi in dict_over:
            len1 = 0
            for introns1 in dict_intron_compared[pi]:
                len1 += (introns1[1] - introns1[0] + 1)
                for pi2s in dict_over[pi]:
                    for introns2 in dict_intron_yours[pi2s]:
                        if introns1[0] >= introns2[0] and introns1[1] <= introns2[1]:
                            dict_over_intron[pi][1] += 1
        len2 = 0
        for pi2s in dict_over[pi]:
            for intron2 in dict_intron_yours[pi2s]:
                len2 += (intron2[1] - intron2[0])
        dict_over_intron[pi][2] = len1
        dict_over_intron[pi][3] = len2
    return dict_over_intron


def identify_overlap(dict_gene_yours, dict_gene_compared):
    dict_over = {}
    for pi in dict_gene_compared:
        dict_over[pi] = []
    global LIST_NEW
    LIST_NEW = []
    for pi1 in dict_gene_yours:
        chrom1 = dict_gene_yours[pi1][0]
        start1 = dict_gene_yours[pi1][1]
        end1 = dict_gene_yours[pi1][2]
        strand1 = dict_gene_yours[pi1][3]
        is_new = 1
        for pi2 in dict_gene_compared:
            chrom2 = dict_gene_compared[pi2][0]
            start2 = dict_gene_compared[pi2][1]
            end2 = dict_gene_compared[pi2][2]
            strand2 = dict_gene_compared[pi2][3]
            if chrom1 == chrom2 and strand1 == strand2:
                if not (start1 > end2 or end1 < start2):
                    dict_over[pi2].append(pi1)
                    is_new = 0
        if is_new == 1:
            LIST_NEW.append(pi1)
    return dict_over

                    
def extract_gene(dict_exon):
    dict_gene = {}
    for pi in dict_exon:
        start = dict_exon[pi][0][1]
        end = dict_exon[pi][-1][2]
        chrom = dict_exon[pi][0][0]
        strand = dict_exon[pi][0][4]
        dict_gene[pi] = [chrom, start, end, strand]
    return dict_gene


def extract_intron(dict_exon):
    dict_intron = {}
    for pi in dict_exon:
        if pi not in dict_intron:
            dict_intron[pi] = []
        start = dict_exon[pi][0][2] + 1
        for exons_id in range(1,len(dict_exon[pi])):
            if dict_exon[pi][exons_id][1] > start:
                dict_intron[pi].append([start, dict_exon[pi][exons_id][1] - 1])
            start = dict_exon[pi][exons_id][2] + 1
    return dict_intron


def read_exons(path):
    file_exon = bb.fun_open_file(path)
    dict_exon= {}
    for l in file_exon:
        line = l.strip().split()
        line[1:3] = map(int, line[1:3])
        if line[3] not in dict_exon:
            dict_exon[line[3]] = []
        dict_exon[line[3]].append(line[0:3] + line[4:])
    for pi in dict_exon:
        dict_exon[pi].sort()
    return dict_exon

# --------process--------
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        bb.fun_print_error("user interrupted, abort!")
        sys.exit(0)
