#! /usr/bin/env python
# -*- coding: utf-8 -*-
import subprocess
import sys
import re
import os
import bb_basic as bb


def main():
    print_help()
    # dict for three type of summaries
    dict_subfamily = {}
    dict_family = {}
    dict_divergence = {}
    sl = float(sys.argv[3])
    for l in bb.fun_open_file(sys.argv[1], "r"):
        li = l.strip().split("\t")
        subfamily = li[3]
        family = "/".join(li[6:8])
        tl = int(li[2]) - int(li[1]) # rmsk copy length
        li[4] = float(li[4])
        # for dict_subfamily
        try:
            dict_subfamily[subfamily][0] += tl
            dict_subfamily[subfamily][1] += 1
            dict_subfamily[subfamily][2] += li[4]/100*tl
        except KeyError:
            dict_subfamily[subfamily] = [tl, 1, li[4]/100*tl, family.split("/")[0], family] # [length, copy, mismatches]
        # for dict_family
        try:
            dict_family[family][0] += tl
            dict_family[family][1] += 1
            dict_family[family][2] += li[4]/100*tl
        except KeyError:
            dict_family[family] = [tl, 1, li[4]/100*tl, family.split("/")[0]] # [length, copy, mismatches]
        # for dict_divergence
        if li[4] < 40: # need divergence smaller than 40
            try:
                dict_divergence[family][int(li[4])] += tl
            except KeyError:
                dict_divergence[family] = [0 for i in range(40)]
                dict_divergence[family][int(li[4])] += tl
    # open output files
    fo_family = bb.fun_open_file(sys.argv[2] + ".family.summ", "w")
    fo_subfamily = bb.fun_open_file(sys.argv[2] + ".subfamily.summ", "w")
    fo_divergence = bb.fun_open_file(sys.argv[2] + ".divergence.summ", "w")
    # write files
    for k in dict_family:
        fo_family.write("%s\t%s\t%s\t%s\t%s\n"%(k, dict_family[k][0], dict_family[k][1], dict_family[k][2]/dict_family[k][0]*100, dict_family[k][3]))
    for k in dict_subfamily:
        fo_subfamily.write("%s\t%s\t%s\t%s\t%s\t%s\n"%(k, dict_subfamily[k][0], dict_subfamily[k][1], dict_subfamily[k][2]/dict_subfamily[k][0]*100, dict_subfamily[k][3], dict_subfamily[k][4]))
    for k in dict_divergence:
        fo_divergence.write("%s\t%s"%(k, k.split("/")[0]))
        for i in range(40):
            fo_divergence.write("\t%f"%float(dict_divergence[k][i]*100/sl))
        fo_divergence.write("\n")
    # close files
    fo_family.close()
    fo_subfamily.close()
    fo_divergence.close()
    subprocess.check_call(["summary_rmsk.bed9.R", sys.argv[2]])


# --------functions--------
def print_help():
    if len(sys.argv) < 2:
        bb.fun_print_help("rmsk.bed9", "prefix", "genome_length, eg: 3000000000 or 3e9")

# --------process--------
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        bb.fun_print_error("user interrupted, abort!")
        sys.exit(0)
