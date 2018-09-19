#! /usr/bin/env python
# -*- coding: utf-8 -*-
import subprocess
import sys
import re
import os
import argparse
import bb_basic as bb


def main():
    print_help()
    global dict_trn
    dict_trn = {}
    read_trn(sys.argv[2])
    read_unpair(sys.argv[1]+".unpair.uniq.transposons.filtered.bed")
    write_bucket(sys.argv[1] + ".temp2")
    dict_trn = {}
    read_trn(sys.argv[2])
    read_unpair(sys.argv[1]+".unpair.uniq.transposons.bed")
    write_bucket(sys.argv[1] + ".temp1")
    subprocess.check_call("paste {0}.temp1 {0}.temp2 | cut -f 1,2,3,6 > {0}.temp".format(sys.argv[1]), shell=True)
    subprocess.check_call("trn_plot_bucket.R " + sys.argv[1] + ".temp " + sys.argv[2] + " " + sys.argv[3] + " 1", shell=True)
    subprocess.check_call("rm " + sys.argv[1] + ".temp*", shell=True)

# --------functions--------
def write_bucket(fo):
    file_o = bb.fun_open_file(fo, "w")
    for trn in dict_trn:
        for posit in range(200):
            file_o.write("%s\t%s\t%s\n"%(trn, posit, dict_trn[trn][posit]))
    file_o.close()


def read_trn(fi):
    for li in bb.fun_open_file(fi):
        l = li.strip().split("\t")
        dict_trn[l[0]] = {"step": (float(l[1])+0.1)/200}
        for i in range(200):
            dict_trn[l[0]][i] = 0


def read_unpair(fi):
    for li in bb.fun_open_file(fi):
        l = li.strip().split("\t")
        record = l[4].split(";")
        for i in range(len(record)-1):
            trn = record[i].split(",")[0]
            posit = int(record[i].split(",")[1][1:])
            try:
                dict_trn[trn][int(posit/dict_trn[trn]["step"])] += 1
            except KeyError:
                print "Warning: %s:%s exceed length"%(trn, posit/dict_trn[trn]["step"])

            
def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--version", action="version", version="%(prog)s 1.0")
    parser.add_argument("args", help="", nargs="*")
    args = parser.parse_args()
    return args


def print_help():
    if len(sys.argv) < 2:
        bb.fun_print_help("in.prefix (should have in.unpair.uniq.transposons.filtered.bed and in.unpair.uniq.transposons.bed)", "trn.size", "out.pdf")

# --------process--------
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        bb.fun_print_error("user interrupted, abort!")
        sys.exit(0)
