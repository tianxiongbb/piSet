#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import re
import bb_basic as bb


def main():
    print_help()
    file_bed = bb.fun_open_file(sys.argv[2], "w")
    dict_exons = {}
    for l in bb.fun_open_file(sys.argv[1], "r"):
        line = l.strip().split("\t")
        if line[0] == "":
            break
        if line[0][0] == "#":
            continue
        gn = re.findall(r'%s \"([\w\.\-\_\(\)\[\]\'\:]+)\"'%sys.argv[3], line[8])
        gi = re.findall(r'gene_id \"([\w\.\-\_\(\)\[\]\'\:]+)\"', line[8])
        if len(gn) == 0:
            gn = gi
        if (line[2] == "exon" or re.search("utr", line[2])) and len(gi) > 0:
            try:
                dict_exons[gn[0]].append([line[0],int(line[3]),int(line[4]),line[6],gi[0]])
            except KeyError:
                dict_exons[gn[0]] = [[line[0],int(line[3]),int(line[4]),line[6],gi[0]]]
    for i in dict_exons:
        dict_exons[i].sort()
    for i in dict_exons:
        s = -1 # s: start; e: end; c: chromosome; st: strand
        e = -1
        for j in dict_exons[i]:
            if e == -1:
                s = j[1]-1
                e = j[2]
                c = j[0]
                st = j[3]
            if j[1] > e+1:
                file_bed.write("%s\t%s\t%s\t%s\t%s\t%s\n"%(c,s,e,i,j[4],st))
                s = j[1]-1
                e = j[2]
                c = j[0]
                st = j[3]
            else:
                e = max(e, j[2])
        file_bed.write("%s\t%s\t%s\t%s\t%s\t%s\n"%(c,s,e,i,j[4],st))
    file_bed.close()


# --------functions--------
def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--version", action="version", version="%(prog)s 1.0")
    parser.add_argument("args", help="", nargs="*")
    args = parser.parse_args()
    return args


def print_help():
    if len(sys.argv) < 2:
        bb.fun_print_help("in.gtf", "out.exon.bed", "gene_name|gene_id|transcript_id|...")

# --------process--------
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        bb.fun_print_error("user interrupted, abort!")
        sys.exit(0)
