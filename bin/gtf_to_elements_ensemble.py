#! /usr/bin/env python
# -*- coding: utf-8 -*-
'''
This script is written to make exon, intron, 5'URT and 3'URT sets for each gene.
'''
import subprocess
import sys
import re
import os
import argparse
import bb_basic as bb


def main():
    print_help()
    dict_gff = read_gtf(bb.fun_open_file(sys.argv[1], "r"))
    dict_gff = process_gff(dict_gff)
    write_gff(dict_gff, sys.argv[2])


# --------functions--------
def write_gff(di, p):
    # write noncoding smallRNAs
    fo = bb.fun_open_file(p+".sncRNA.bed", "w")
    for g in di["ncRNA"]:
        fo.write("\t".join(map(str,g)) + "\n")
    fo.close()
    # write otherRNAs
    foe = bb.fun_open_file(p+".otherRNA.exon.bed", "w") # write exons
    foi = bb.fun_open_file(p+".otherRNA.intron.bed", "w") # write introns
    for g in di["otherRNA"]:
        gi = di["otherRNA"][g] # gene information
        for i in di["otherRNA"][g]["exon"]:
            try:
                foe.write("%s\t%s\t%s\t%s\t%s\t%s\n"%(gi["chr"],i[0],i[1],g,gi["type"],gi["strand"]))
            except KeyError:
                print gi
        for i in di["otherRNA"][g]["intron"]:
            foi.write("%s\t%s\t%s\t%s\t%s\t%s\n"%(gi["chr"],i[0],i[1],g,gi["type"],gi["strand"]))
    foe.close()
    foi.close()
    # write mRNAs
    foe = bb.fun_open_file(p+".mRNA.exon.bed", "w") # write exons
    foc = bb.fun_open_file(p+".mRNA.CDS.bed", "w") # write cds
    foi = bb.fun_open_file(p+".mRNA.intron.bed", "w") # write introns
    fo5 = bb.fun_open_file(p+".mRNA.5UTR.bed", "w") # write 5UTR
    fo3 = bb.fun_open_file(p+".mRNA.3UTR.bed", "w") # write 3UTR
    for g in di["mRNA"]:
        gi = di["mRNA"][g] # gene information
        for i in di["mRNA"][g]["exon"]:
            foe.write("%s\t%s\t%s\t%s\t0\t%s\n"%(gi["chr"],i[0],i[1],g,gi["strand"]))
        for i in di["mRNA"][g]["intron"]:
            foi.write("%s\t%s\t%s\t%s\t0\t%s\n"%(gi["chr"],i[0],i[1],g,gi["strand"]))
        for i in di["mRNA"][g]["5utr"]:
            fo5.write("%s\t%s\t%s\t%s\t0\t%s\n"%(gi["chr"],i[0],i[1],g,gi["strand"]))
        for i in di["mRNA"][g]["3utr"]:
            fo3.write("%s\t%s\t%s\t%s\t0\t%s\n"%(gi["chr"],i[0],i[1],g,gi["strand"]))
        for i in di["mRNA"][g]["cds"]:
            foc.write("%s\t%s\t%s\t%s\t0\t%s\n"%(gi["chr"],i[0],i[1],g,gi["strand"]))
    foe.close()
    foi.close()
    fo5.close()
    fo3.close()
    foc.close()
    

def process_gff(di): # merge exons, get introns and utrs
    # process otherRNAs
    for g in di["otherRNA"]:
        if len(di["otherRNA"][g]["exon"]) > 0:
            di["otherRNA"][g]["exon"] = merge_exon_cds(di["otherRNA"][g]["exon"])
            di["otherRNA"][g]["intron"] = get_intron(di["otherRNA"][g]["exon"])
    # process mRNAs
    for g in di["mRNA"]:
        if len(di["mRNA"][g]["exon"]) > 0:
            di["mRNA"][g]["exon"] = merge_exon_cds(di["mRNA"][g]["exon"])
            di["mRNA"][g]["intron"] = get_intron(di["mRNA"][g]["exon"])
        if len(di["mRNA"][g]["cds"]) > 0:
            di["mRNA"][g]["cds"] = merge_exon_cds(di["mRNA"][g]["cds"])
            di["mRNA"][g] = get_utr(di["mRNA"][g])
    return di

        
def get_utr(dict_mRNA): # put regions in exons but not in CDSs into UTR
    se = dict_mRNA["exon"][0][0]
    ee = dict_mRNA["exon"][-1][1]
    sc = dict_mRNA["cds"][0][0]
    ec = dict_mRNA["cds"][-1][1]
    if dict_mRNA["strand"] == "+":
        left_utr = "5utr"; right_utr = "3utr"
    else:
        left_utr = "3utr"; right_utr = "5utr"
    if se < sc:
        for ex in dict_mRNA["exon"]:
            if ex[0] >= sc:
                break
            dict_mRNA[left_utr].append([ex[0], min(ex[1], sc)])
    if ee > ec:
        for ex in dict_mRNA["exon"][::-1]:
            if ex[1] <= ec:
                break
            dict_mRNA[right_utr].append([max(ex[0], ec), ex[1]])
    return dict_mRNA


def get_intron(li): # li: merged exon coordinate list, eg: [[100,110],[120,125]]
    lo = []
    for i in range(1,len(li)):
        lo.append([li[i-1][1], li[i][0]])
    return lo


def merge_exon_cds(li): # li: exon coordinate list, eg: [[100,110],[105,125]]
    li.sort() # sort exons based on the exon start coordinate
    lo = []
    s = li[0][0]; e = li[0][1] # initiate start and end
    for ex in li[1:]:
        if ex[0] > e + 1:
            lo.append([s,e])
            s,e = ex
        else:
            e = max(e, ex[1])
    lo.append([s,e])
    return lo

        
def read_gtf(fi):
    do = {"ncRNA": [], "mRNA": {}, "otherRNA": {}}
    for l in fi:
        if l[0] == "#":
            continue
        li = l.strip().split("\t")
        li[3:5] = map(int, li[3:5])
        d = {}
        for kv in li[8].split("\";")[:-1]:
            if kv[0] == " ":
                d[kv.split(" \"")[0][1:]] = kv.split(" \"")[1]
            else:
                d[kv.split(" \"")[0]] = kv.split(" \"")[1]
        if "gene_name" not in d.keys() and "gene_id" in d.keys():
            d["gene_name"] = d["gene_id"]
        if "gene_name" not in d.keys() and "gene_id" not in d.keys():
            d["gene_name"] = "none"
        if "gene_biotype" not in d.keys() and "gene_type" in d.keys():
            d["gene_biotype"] = d["gene_type"]
        if "transcript_biotype" not in d.keys() and "transcript_type" in d.keys():
            d["transcript_biotype"] = d["transcript_type"]
        if "transcript_biotype" not in d.keys() and "gene_biotype" in d.keys():
            d["transcript_biotype"] = d["gene_biotype"]
        if "gene_biotype" not in d.keys() and "transcript_biotype" in d.keys():
            d["gene_biotype"] = d["transcript_biotype"]
        if li[2] == "exon":
            if d["gene_biotype"] == "protein_coding":
                try:
                    do["mRNA"][d["gene_name"]]["exon"].append([li[3],li[4]])
                except KeyError:
                    do["mRNA"][d["gene_name"]] = {"exon":[], "cds":[], "intron":[], "5utr":[], "3utr":[], "chr":li[0], "strand":li[6]}
                    do["mRNA"][d["gene_name"]]["exon"].append([li[3],li[4]])
            elif d["gene_biotype"] == "processed_pseudogene" or d["gene_biotype"] == "pseudogene" or d["gene_biotype"] == "lincRNA" or d["gene_biotype"] == "misc_RNA":
                try:
                    do["otherRNA"][d["gene_name"]]["exon"].append([li[3],li[4]])
                except KeyError:
                    do["otherRNA"][d["gene_name"]] = {"exon":[], "intron":[], "type":d["gene_biotype"], "chr":li[0], "strand":li[6]}
                    do["otherRNA"][d["gene_name"]]["exon"].append([li[3],li[4]])
        elif li[2] == "transcript" and d["transcript_biotype"] in ["snoRNA", "pre_miRNA", "rRNA", "snRNA", "tRNA"]:
            try:
                do["ncRNA"].append([li[0], li[3], li[4], d["gene_name"], d["transcript_biotype"], li[6]])
            except KeyError:
                print "cannot find gene name in record below, skip......"
                print l
                print d
        # store CDS into related protein_coding genes
        elif li[2] == "CDS":
            try:
                do["mRNA"][d["gene_name"]]["cds"].append([li[3],li[4]])
                do["mRNA"][d["gene_name"]]["exon"].append([li[3],li[4]])
            except KeyError:
                continue
    return do

            
def print_help():
    if len(sys.argv) < 2:
        bb.fun_print_help("in.gtf", "out.prefix")

# --------process--------
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        bb.fun_print_error("user interrupted, abort!")
        sys.exit(0)
