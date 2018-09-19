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
    # parameters
    form = "fa"
    if len(sys.argv)>3: form = sys.argv[3]
    fi = bb.fun_open_file(sys.argv[1], "r")
    fo = bb.fun_open_file(sys.argv[2], "w")
    # input format is fasta
    if form == "fa":
        for l in fi:
            if not re.search("^>", l):
                l = l.replace("U", "T")
                l = l.replace("u", "t")
            fo.write(l)
        fo.close()
    else:
        n = 0
        for l in fi:
            n += 1
            if n % 4 == 2:
                l = l.replace("U", "T")
                l = l.replace("u", "t")
            fo.write(l)
        fo.close()
                

# --------functions--------
def print_help():
    if len(sys.argv) < 2:
        bb.fun_print_help("in.fa/fq", "out.fa/fq", "[fa|fq]; default: fa")

# --------process--------
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        bb.fun_print_error("user interrupted, abort!")
        sys.exit(0)
