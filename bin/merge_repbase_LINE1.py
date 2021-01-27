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
    dict_fa = read_fa(sys.argv[1])
    dict_merged_fa = merge_fa(dict_fa)
    write_fa(dict_merged_fa, sys.argv[2])

# --------functions--------
def write_fa(di, fo):
    f = bb.fun_open_file(fo, "w")
    for i in di:
        f.write(">" + i + "\n")
        f.write(di[i] + "\n")
    f.close()


def merge_fa(di):
    dmo = {}
    d_trn = {}
    for k in di.keys():
        if re.search("_3end", k):
            n = k.split("_3end")[0]
            if n not in d_trn.keys():
                d_trn[n] = []
            d_trn[n].append(k)
        elif re.search("_orf2", k):
            n = k.split("_orf2")[0]
            if n not in d_trn.keys():
                d_trn[n] = []
            d_trn[n] = [k] + d_trn[n]
        else:
            n = k
            if n not in d_trn.keys():
                d_trn[n] = []
            d_trn[n] = [k] + d_trn[n]
    for k in di.keys():
        if re.search("_5end", k):
            n = k.split("_5end")[0]
            if n not in d_trn.keys():
                d_trn[n] = []
            d_trn[n] = [k] + d_trn[n]
        elif re.search("_3end", k):
            n = k.split("_3end")[0]
        elif re.search("_orf2", k):
            n = k.split("_orf2")[0]
        else:
            n = k
        i = n
        if len(d_trn[i]) == 1:
            dmo[i] = di[d_trn[i][0]]
        elif len(d_trn[i]) == 2:
            dmo[i] = di[d_trn[i][0]] + di[d_trn[i][1]]
        else:
            dmo[i] = di[d_trn[i][0]] + di[d_trn[i][1]] + di[d_trn[i][2]] 
    return dmo
    

def read_fa(f_in):
    do = {}
    for l in bb.fun_open_file(f_in):
        li = l.strip()
        if(li[0]==">"):
            trn = li[1:]
        else:
            try:
                do[trn] += li
            except KeyError:
                do[trn] = li
    return do

    
def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--version", action="version", version="%(prog)s 1.0")
    parser.add_argument("args", help="", nargs="*")
    args = parser.parse_args()
    return args


def print_help():
    if len(sys.argv) < 2:
        bb.fun_print_help("in.fa", "out.fa")

# --------process--------
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        bb.fun_print_error("user interrupted, abort!")
        sys.exit(0)
