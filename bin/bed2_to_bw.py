#! /usr/bin/env python
# -*- coding: utf-8 -*-
import subprocess
import sys
import bb_basic as bb
from multiprocessing import Pool


# --------functions--------
def run(dict_bed2, chrom_size, dict_chrom, prefix):
    bdg = open(prefix + ".bdg", "w")
    # write signals to bedGraph
    write_bdg(dict_bed2, dict_chrom, bdg)
    # sort bedGraph
    subprocess.check_call("sort -k1,1 -k2,2n {0}.bdg > {0}.sort.bdg".format(prefix), shell=True)
    # bedGraph to bigWig
    subprocess.check_call("bedGraphToBigWig {0}.sort.bdg {1} {0}.bw".format(prefix, sys.argv[2]), shell=True)
    # remove bedGraph and sort.bedGraph
    #subprocess.check_call("rm {0}.sort.bdg {0}.bdg".format(prefix), shell=True)


def read_bed2_sepe(fi, factor):
    '''
    need all dict to be global
    seperate reads to uniqWatson allWatson uniqCrick allCrick
    '''
    n = [0,0,0,0]
    for l in fi:
        li = l.strip().split("\t")
        li[3] = float(li[3]) / factor
        if li[5] == "+" and li[4] == "1":
            n[0] += 1
            p5 = int(li[1]) # 5 prime end
            try:
                dict_bed2_watson_uniq[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] += float(li[3])/float(li[4])
            except KeyError:
                dict_bed2_watson_uniq[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] = float(li[3])/float(li[4])
            try:
                dict_bed2_watson_all[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] += float(li[3])/float(li[4])
            except KeyError:
                dict_bed2_watson_all[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] = float(li[3])/float(li[4])
        elif li[5] == "+" and li[4] != "1":
            n[1] += 1
            p5 = int(li[1]) # 5 prime end
            try:
                dict_bed2_watson_all[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] += float(li[3])/float(li[4])
            except KeyError:
                dict_bed2_watson_all[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] = float(li[3])/float(li[4])
        elif li[5] == "-" and li[4] == "1":
            n[2] += 1
            p5 = int(li[2]) - 1
            try:
                dict_bed2_crick_uniq[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] += float(li[3])/float(li[4])
            except KeyError:
                dict_bed2_crick_uniq[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] = float(li[3])/float(li[4])
            try:
                dict_bed2_crick_all[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] += float(li[3])/float(li[4])
            except KeyError:
                dict_bed2_crick_all[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] = float(li[3])/float(li[4])
        else:
            n[3] += 1
            p5 = int(li[2]) - 1
            try:
                dict_bed2_crick_all[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] += float(li[3])/float(li[4])
            except KeyError:
                dict_bed2_crick_all[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] = float(li[3])/float(li[4])
    print "watson uniq record: %s; watson all record %s; crick uniq record: %s; crick all record: %s"%(n[0], n[1], n[2], n[3])


def write_bdg(d, dict_chrom, bdg):
    for k in d:
        chrom = k.split("\t")[0]
        p5 = int(k.split("\t")[1])
        if p5 < dict_chrom[chrom]:
            bdg.write(k + "\t" + str(d[k]) + "\n")
    bdg.close()


def read_bed2(fi, factor):
    dict_bed2 = {}
    for l in fi:
        li = l.strip().split("\t")
        li[3] = float(li[3]) / factor
        if li[5] == "+":
            p5 = int(li[1]) # 5 prime end
        else:
            p5 = int(li[2]) - 1
        try:
            dict_bed2[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] += float(li[3])/float(li[4])
        except KeyError:
            dict_bed2[li[0]+"\t"+str(p5)+"\t"+str(p5+1)] = float(li[3])/float(li[4])
    return dict_bed2


def read_chrom(fi):
    dict_chrom = {}
    for l in fi:
        li = l.strip().split("\t")
        dict_chrom[li[0]] = int(li[1])
    return dict_chrom


def print_help():
    if len(sys.argv) < 4:
        bb.fun_print_help("in.bed2", "chrom.size", "out.prefix", "factor", "CPU", "\nGenerally, bed2_to_bw.py will seperate uniqMappers and allMappers in Watson and Crick strand.\nYou can set CPU to 0 to suppress seperation.", "\nbed2_to_bw.py will only calculate 5' end of a smallRNA read")

# --------process--------
if __name__ == '__main__':
    print_help()
    bed2_in = open(sys.argv[1], "r")
    chrom_size = open(sys.argv[2], "r")
    prefix = sys.argv[3]
    factor = float(sys.argv[4])
    cpu = int(sys.argv[5])
    dict_chrom = read_chrom(chrom_size)
    if cpu >= 1:
        global dict_bed2_watson_uniq
        dict_bed2_watson_uniq = {}
        global dict_bed2_watson_all
        dict_bed2_watson_all = {}
        global dict_bed2_crick_uniq
        dict_bed2_crick_uniq = {}
        global dict_bed2_crick_all
        dict_bed2_crick_all = {}
        read_bed2_sepe(bed2_in, factor)
        run(dict_bed2_watson_uniq, chrom_size, dict_chrom, prefix + ".watson.uniq")
        run(dict_bed2_watson_all, chrom_size, dict_chrom, prefix + ".watson.all")
        run(dict_bed2_crick_uniq, chrom_size, dict_chrom, prefix + ".crick.uniq")
        run(dict_bed2_crick_all, chrom_size, dict_chrom, prefix + ".crick.all")
        #pool = Pool(cpu)
        #res.append(pool.apply_async(run, args=(dict_bed2_watson_uniq, chrom_size, dict_chrom, prefix + ".watson.uniq")))
        #res.append(pool.apply_async(run, args=(dict_bed2_watson_all, chrom_size, dict_chrom, prefix + ".watson.all")))
        #res.append(pool.apply_async(run, args=(dict_bed2_crick_uniq, chrom_size, dict_chrom, prefix + ".crick.uniq")))
        #res.append(pool.apply_async(run, args=(dict_bed2_crick_all, chrom_size, dict_chrom, prefix + ".crick.all")))
        #pool.close()
        #pool.join()
        trackHub = open(prefix + ".trackHub", "w")
        text = "track {0}\ncontainer multiWig\nshortLabel {0}\nlongLabel \
long label for {0}, modify yourself\ntype bigWig\nvisibility full\n\
autoScale on\nmaxHeightPixels 40,20,1\n\n\
track {0}.watson.uniq\nparent {0}\nshortLabel {0}.watson.uniq\n\
longLabel {0}, watson strand, uniqMappers\n\
type bigWig\nbigDataUrl {0}.watson.uniq.bw\ncolor 239,59,44\n\n\
track {0}.watson.all\nparent {0}\nshortLabel {0}.watson.all\n\
longLabel {0}, watson strand, allMappers\n\
type bigWig\nbigDataUrl {0}.watson.all.bw\ncolor 252,187,161\n\n\
track {0}.crick.uniq\nparent {0}\nshortLabel {0}.crick.uniq\n\
longLabel {0}, crick strand, uniqMappers\nnegateValues on\n\
type bigWig\nbigDataUrl {0}.crick.uniq.bw\ncolor 239,59,44\n\n\
track {0}.crick.all\nparent {0}\nshortLabel {0}.crick.all\n\
longLabel {0}, crick strand, allMappers\nnegateValues on\n\
type bigWig\nbigDataUrl {0}.crick.all.bw\ncolor 252,187,161\n".format(prefix)
        trackHub.write(text)
        trackHub.close()
    else:
        dict_bed2 = read_bed2(bed2_in, factor)
        run(dict_bed2, chrom_size, dict_chrom, prefix)
