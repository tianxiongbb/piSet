#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import re
import bb_basic as bb


def main():
    print_help()
    file_bed12 = bb.fun_open_file(sys.argv[2], "w")
    dict_exons = {}
    for l in bb.fun_open_file(sys.argv[1], "r"):
        line = l.strip().split("\t")
        if line[0] == "":
            break
        if line[0][0] == "#":
            continue
        gn = re.findall(r'gene_name \"([\w\.\-\_\(\)\[\]\'\:]+)\"', line[8])
        gi = re.findall(r'gene_id \"([\w\.\-\_\(\)\[\]\'\:]+)\"', line[8])
        if len(gn) == 0:
            gn = gi
        if (line[2] == "exon" or re.search("utr", line[2])) and len(gi) > 0:
            try:
                dict_exons[gi[0]].append([line[0],int(line[3]),int(line[4]),line[6],gn[0]])
            except KeyError:
                dict_exons[gi[0]] = [[line[0],int(line[3]),int(line[4]),line[6],gn[0]]]
    for i in dict_exons:
        dict_exons[i].sort()
    for i in dict_exons:
        s = -1 # ss: start; s: block start; e: end; c: chromosome; st: strand; ct: block numbers; bsize: block size; bstart: block start
        e = -1
        bstart = [0]
        bsize = []
        for j in dict_exons[i]:
            if e == -1:
                ct = 1
                ss = j[1]
                s = j[1]
                e = j[2]
                c = j[0]
                st = j[3]
            if j[1] > e+1:
                bsize.append(e-s)
                s = j[1]
                e = j[2]
                bstart.append(s)
                ct += 1
            else:
                e = max(e, j[2])
        bsize.append(e-s)
        file_bed12.write("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{1}\t{2}\t255,0,0\t{6}\t".format(c,ss,e,i,j[4],st,ct))
        for bs in bsize:
            file_bed12.write(str(bs) + ",")
        file_bed12.write("\t")
        for bs in bstart:
            file_bed12.write(str(bs) + ",")
        file_bed12.write("\n")
    file_bed12.close()


# --------functions--------
def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--version", action="version", version="%(prog)s 1.0")
    parser.add_argument("args", help="", nargs="*")
    args = parser.parse_args()
    return args


def print_help():
    if len(sys.argv) < 2:
        bb.fun_print_help("in.gtf", "out.bed12")

# --------process--------
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        bb.fun_print_error("user interrupted, abort!")
        sys.exit(0)
