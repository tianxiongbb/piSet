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
    file_strand = bb.fun_open_file(sys.argv[2], "w")
    dict_rpm = read_rpm(file_rpm)
    dict_strand = judge_strand(dict_rpm)
    write_strand(dict_strand, file_strand)


# --------functions--------
def write_strand(di, fi):
    for key in di:
        fi.write("%s\t%s\t%s\n"%(key, di[key][0], di[key][1]))
    fi.close()


def judge_strand(di):
    do = {}
    bb.fun_print("divergence picluster", "blue", "white", 1)
    for key in di: # for each picluster
        # initiate strand mode
        num_bin = len(di[key].keys())
        mode = []
        mode_all = []
        for i in range(1,len(di[key].keys())+1): # for each bin
            subkey = str(i)
            # remove bin with rpm less than 1
            if sum(di[key][subkey]) < 1:
                continue
            # bin strand
            if di[key][subkey][0] > 10*di[key][subkey][1]:
                mode_all.append(subkey)
                mode.append("+")
            elif 10*di[key][subkey][0] < di[key][subkey][1]:
                mode_all.append(subkey)
                mode.append("-")
            else:
                mode_all.append(subkey)
                mode.append(".")
        if mode[:min(10,len(mode))].count("-") > 5 and mode[max(0,len(mode)-10):len(mode)].count("+") > 5: # divergence strand: -+
            num_error = []
            for dp in range(len(mode)): # breakpoint as bp
                num_error.append(abs(mode[:dp].count("+") + mode[dp:-1].count("-")))
            bp = num_error.index(min(num_error)) # set bp to minimize entropy
            if mode[:bp].count("-") > bp/1.5 and mode[bp:-1].count("+") > (len(mode)-bp)/1.5: # confirm this is divergence picluster
                seq_mode = "".join(mode[:bp]) + "|" + "".join (mode[bp:-1])
                bb.fun_print(key + ":" + seq_mode, "blue", "white", 1)
                do[key] = ["-+", int(mode_all[bp])*100] # bp*100 as break distance
                continue
        if mode.count(".") > len(mode)/2: # no strand: .
            do[key] = [".", 0]
        elif mode.count("+") > len(mode)/1.5: # watson strand: +
            do[key] = ["+", 0]
        elif mode.count("-") > len(mode)/1.5: # crick strand: -
            do[key] = ["-", 0]
        else: # cann't judge, set to no strand: .
            do[key] = [".", 0]
    return do


def read_rpm(fi):
    do = {}
    for l in fi:
        li = l.strip().split("\t")
        key = li[0].split("-")[0]
        subkey = li[0].split("-")[1]
        try:
            do[key][subkey] = [float(li[1]), float(li[2])]
        except KeyError:
            do[key] = {}
            do[key][subkey] = [float(li[1]), float(li[2])]
    return do


def print_help():
    if len(sys.argv) < 2:
        bb.fun_print_help("in.rpm", "out.strand")

# --------process--------
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        bb.fun_print_error("user interrupted, abort!")
        sys.exit(0)
