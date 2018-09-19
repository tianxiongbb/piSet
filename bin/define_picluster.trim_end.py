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
    file_rpm = bb.fun_open_file(sys.argv[1], "r")
    file_end = bb.fun_open_file(sys.argv[2], "w")
    global cover_rate; cover_rate = float(sys.argv[3])
    global bin_seq; bin_seq = float(sys.argv[4])
    global max_bin_rpm; max_bin_rpm = float(sys.argv[5])
    global min_distance; min_distance = float(sys.argv[6])
    dict_rpm = read_rpm(file_rpm)
    dict_cutoff = determine_cutoff(dict_rpm)
    dict_bin = filter_bin(dict_rpm, dict_cutoff)
    dict_end = judge_ends(dict_bin)
    write_ends(dict_end, file_end)


# --------functions--------
def write_ends(di, fo):
    for pi in di:
        fo.write("%s\t%s\t%s\n"%(pi, di[pi][0], di[pi][1]))
    fo.close()


def judge_ends(di):
    do = {}
    for pi in di:
        do[pi] = [0, 0]
        for i in range(1,len(di[pi])):
            if (di[pi][i] - di[pi][i-1]) < int(min_distance/100):
                do[pi][0] = di[pi][i-1]*100 - 100
                break
        for i in range(1,len(di[pi]))[::-1]:
            if (di[pi][i] - di[pi][i-1]) < int(min_distance/100):
                do[pi][1] = di[pi][i]*100
                break
    return do


def filter_bin(di, dc):
    do = {}
    for pi in di:
        do[pi] = []
        for i in range(1,len(di[pi])+1):
            n = str(i)
            if sum(di[pi][n][:2]) >= dc[pi] and sum(di[pi][n][2:]) >= bin_seq:
                do[pi].append(int(n))
    return do

            
def determine_cutoff(di):
    do = {}
    for pi in di:
        ct = []
        for n in di[pi]:
            ct.append(sum(di[pi][n][:2])) # add bin rpm in a picluster into list
        # set cutoff to cover $cover_rate reads
        ct.sort(); ct = ct[::-1]
        num_rpm = sum(ct)
        for i in range(len(ct)):
            if sum(ct[:i]) > cover_rate * num_rpm:
                break
        do[pi] = min(max_bin_rpm, ct[i]) # set max cutoff
    return do


def read_rpm(fi):
    do = {}
    for l in fi:
        li = l.strip().split("\t")
        key = li[0].split("-")[0]
        subkey = li[0].split("-")[1]
        try:
            do[key][subkey] = map(float, li[1:])
        except KeyError:
            do[key] = {}
            do[key][subkey] = map(float, li[1:])
    return do


def print_help():
    if len(sys.argv) < 2:
        bb.fun_print("1. judge rpm cutoff for each piclusters to cover $cover_rate reads\n2. filter bins via rpm and seq cutoff\n3. determine both ends if there are at least 2 bins within 1kb in both ends", "blue", "black", 1)
        bb.fun_print_help("in.rpm", "out.end", "cover_rate", "cutoff_seq_for_bin", "max_cutoff_rpm_for_bin")

# --------process--------
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        bb.fun_print_error("user interrupted, abort!")
        sys.exit(0)
