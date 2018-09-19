#! /usr/bin/env python
# -*- coding: utf-8 -*-
# author: Tianxiong (Bear) Yu
# credit: Yu Fu, who came up with the EM ideal for multiMappers assignment
# EM (Expectation-maximization) takes two steps.
# E step: calculate the probability for each multiple mapped read in different
# loci according to the signal of window around each loci
# M step: re-calculate the signal of each window
import subprocess
from multiprocessing import Pool
from copy import copy
import argparse
import sys
import bb_basic as bb


# --------functions and classes--------
def write_output(bed2_out):
    for s in dict_read_mult:
        for i in dict_read_mult[s]:
            i = map(str, i[0:len(i)-2])
            bed2_out.write("\t".join(i) + "\t" + s + "\n")
    bed2_out.close()


def assign_read(seq):
    winds1 = [s[-2] for s in dict_read_mult[seq]] # windows1 this sequence mapped
    summ1 = sum([sum(dict_wind[i]) for i in winds1]) # signal in mapped windows1 
    winds2 = [s[-1] for s in dict_read_mult[seq]] # windows2 this sequence mapped
    summ2 = sum([sum(dict_wind[i]) for i in winds2]) # signal in mapped windows2
    summ = summ1 + summ2 # overall signal in mapped windows
    # re-calculate probability and window signal
    for i in range(len(dict_read_mult[seq])):
        dict_read_mult[seq][i][4] = float(summ) / (sum(dict_wind[dict_read_mult[seq][i][-2]]) + sum(dict_wind[dict_read_mult[seq][i][-1]]))
        tmp_dict_wind[dict_read_mult[seq][i][-1]][1] += dict_read_mult[seq][i][3] / dict_read_mult[seq][i][4]
        tmp_dict_wind[dict_read_mult[seq][i][-2]][1] += dict_read_mult[seq][i][3] / dict_read_mult[seq][i][4]


def init_dict(bed2_in, window_size, shift_size):
    for l in bed2_in:
        li = l.strip().split("\t")
        seq = li[6]
        li[1:5] = map(int, li[1:5])
        info = li[0:]
        wind_name1 = "_".join([li[0],str(li[1]/shift_size),li[5]])
        wind_name2 = "_".join([li[0],str(max(0,li[1]/shift_size-1)),li[5]])
        info += [wind_name1, wind_name2]
        if li[4] == 1:
            try:
                dict_wind[wind_name1][0] += li[3]
            except KeyError:
                dict_wind[wind_name1] = [li[3], 0]
            try:
                dict_wind[wind_name2][0] += li[3]
            except KeyError:
                dict_wind[wind_name2] = [li[3], 0]
            args.bed2_out.write(l) # write uniqMappers first
        else:
            try:
                dict_wind[wind_name1][1] += li[3]/float(li[4])
            except KeyError:
                dict_wind[wind_name1] = [0, li[3]/float(li[4])]
            try:
                dict_wind[wind_name2][1] += li[3]/float(li[4])
            except KeyError:
                dict_wind[wind_name2] = [0, li[3]/float(li[4])]
            try:
                dict_read_mult[seq].append(info)
            except KeyError:
                dict_read_mult[seq] = [info]

    
def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--bed2_in", help="input.bed2 file", type=open, required=True)
    parser.add_argument("-o", "--bed2_out", help="output.bed3 file; bed3 replace the 5th column of bed2 from mapped loci to mapping probability", type=argparse.FileType("w"), required=True)
    parser.add_argument("-w", "--window_size", help="window size for EM algorithm to assign multiMappers. deafult: 10000", default=10000, type=int)
    parser.add_argument("-s", "--shift_size", help="shift size for EM algorithm to assign multiMappers. deafult: 5000", default=5000, type=int)
    parser.add_argument("-m", "--max_iter_num", help="maxinum iteration number for EM algorithm. deafult: 100", default=100, type=int)
    parser.add_argument("-c", "--cut_off", help="Manhattan distance cutoff to finish EM iteration. deafult: 0.05", default=0.05, type=float)
    parser.add_argument("-v", "--version", action="version", version="%(prog)s 1.01")
    args = parser.parse_args()
    return args


# --------process--------
if __name__ == '__main__':
    args = get_args()
    # initiaize parameters
    dict_wind = {} # wind_name as key, [uniq_signal, mult_signal] as value
    dict_read_mult = {} # init dict_read_multi, seq as key, [chr, start, end, read_num, map_num, strand, wind_name] as value
    iter_num = 1
    bb.fun_print("Initialize the probability of multiMappers", "green", "black", 0)
    init_dict(args.bed2_in, args.window_size, args.shift_size)
    summ = sum([dict_wind[k][1] for k in dict_wind]) # overall signal of multiMappers
    bb.fun_print("multiMapped reads: %s"%summ, "green", "black", 0)
    bb.fun_print("Start apply EM to assign multiMappers......",
            "green", "black", 0)
    #pool = Pool(args.threads)
    while True:
        tmp_dict_wind = {}
        for k in dict_wind:
            tmp_dict_wind[k] = [dict_wind[k][0], 0]
        #seqs = [s for s in dict_read_mult]
        #pool.map(assign_read, seqs) # enable multiple cores
        for i in dict_read_mult:
            assign_read(i)
        delta = sum([abs(dict_wind[k][1] - tmp_dict_wind[k][1]) for k in dict_wind])
        md = float(delta) / summ # Manhatten distance
        bb.fun_print("\tIteration %s; Manhattan distance: %s, %s"%(iter_num, md, delta), "green", "black", 0)
        if float(delta) / summ < args.cut_off:
            write_output(args.bed2_out) # write multiMappers
            bb.fun_print("Reached convergence! Congras!🍺🍺🍺", "green", "black", 0)
            sys.exit(0)
        if iter_num >= args.max_iter_num:
            write_output(args.bed2_out) # write multiMappers
            bb.fun_print("Reaching maximum iteration number: %s"%args.max_iter_num, "green", "black", 0)
            sys.exit(0)
        dict_wind = tmp_dict_wind
        iter_num += 1
