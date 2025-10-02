#! /usr/bin/env python
# -*- coding: utf-8 -*-
import os
import sys
import re

def main():
    if len(sys.argv) < 2:
        print "piFnder_fetchSJ.py" + " in.gtf" + " out.SJ.bed" + " biotype(eg: protein_coding,miRNA  |  not set if you want to use all the biotype)"
        sys.exit(0)
    if len(sys.argv) < 4:
        type_out = []
    else:
        type_out = sys.argv[3].split(",")
    dict_gtf = read_gtf(sys.argv[1], type_out)
    fetch_SJ(dict_gtf, sys.argv[2])

# --------functions--------
def fetch_SJ(dict_gtf, path):
    try:
        file_SJ = open(path, "w")
    except IOError:
        print "can not create file in " + path
        sys.exit(0)
    for transcript_id in dict_gtf:
        exons = dict_gtf[transcript_id]
        exons.sort()
        for exons_id in range(1, len(dict_gtf[transcript_id])):
            this_exon = exons[exons_id]
            pre_exon = exons[exons_id - 1]
            file_SJ.write("%s\t%s\t%s\t%s\t0\t%s\n"%(this_exon[0], pre_exon[2] + 1,
                this_exon[1] - 1, transcript_id, this_exon[3]))
    file_SJ.close()


def read_gtf(path, type_out):
    dict_gtf = {}
    try:
        file_gtf = open(path, "r")
    except IOError:
        print "there is no file in " + path
        sys.exit(0)
    for l in file_gtf:
        line = l.strip().split("\t")
        if line[0][0] == "#":
            continue
        if line[2] == "exon":
            biotype = re.findall(r"biotype \"([\w\.\-\_]+)\"", line[8])[0]
            if len(type_out) == 0 or biotype in type_out:
                transcript_id = re.findall(r"transcript_id \"([\w\.\-\_]+)\"", line[8])[0]
                if transcript_id not in dict_gtf:
                    dict_gtf[transcript_id] = []
                dict_gtf[transcript_id].append([line[0], int(line[3]), int(line[4]), line[6]])
    return dict_gtf

# --------process--------
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        bb.fun_print_error("user interrupted, abort!")
        sys.exit(0)
