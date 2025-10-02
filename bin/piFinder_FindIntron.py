#! /usr/bin/env python
# -*- coding: utf-8 -*-

#########module##############

import os, sys, time, re, copy

from math import *
import bb_basic as bb

#########function##############
def main():
	#help info
	if len(sys.argv)<2:
		fun_help()
	DICT_PI_CLUSTER=bb.fun_read(sys.argv[1], format="bed", type="dict", key_number=4)
	DICT_SJ=fun_read_sj(sys.argv[2])
	DICT_SJ_OUT={}
	for PI_NAME in DICT_PI_CLUSTER.keys():
		print "processing piRNA cluster %s......"%PI_NAME
		if not DICT_SJ.has_key(PI_NAME):
			DICT_SJ_OUT[PI_NAME]=[]
			print "\033[31mSJ information --- no splicing junction\033[0m"
		else:
			DICT_SJ_OUT[PI_NAME]=fun_find_intron_for_one_picluster(DICT_PI_CLUSTER[PI_NAME][0], DICT_SJ[PI_NAME], int(sys.argv[4]))
	LIST_SJ_OUT=[]
	for KEY in DICT_SJ_OUT.keys():
		for i in DICT_SJ_OUT[KEY]:
			LIST_SJ_OUT.append(i[:3]+[KEY]+i[3:])
	bb.fun_write_list(LIST_SJ_OUT,sys.argv[3])

def fun_find_intron_for_one_picluster(LIST_PI_CLUSTER, LIST_SJ, DEPTH):
	WHOLE_RPM=float(LIST_PI_CLUSTER[5])
	WHOLE_SEQNUM=float(LIST_PI_CLUSTER[6])
	LIST_OUT=copy.deepcopy(LIST_SJ)
	N=0
	for i in LIST_SJ:
		SJ_LENGTH=float(i[2])-float(i[1])
		SJ_RPM_PRE=float(i[9])
		SJ_SEQNUM_PRE=float(i[10])
		SJ_RPM_THIS=float(i[11])
		SJ_SEQNUM_THIS=float(i[12])
		SJ_RPM_NEXT=float(i[13])
		SJ_SEQNUM_NEXT=float(i[14])
		SJ_UNIQ_READS=float(i[5])
                SJ_MULTI_READS=float(i[6])
                SJ_READS=SJ_UNIQ_READS+(SJ_MULTI_READS/2)
                if SJ_RPM_THIS==0:
                        continue
		elif SJ_RPM_THIS>SJ_READS/DEPTH*5 and SJ_SEQNUM_THIS>SJ_READS/DEPTH*10:
			LIST_OUT.remove(i)
			N+=1
		elif (SJ_RPM_THIS*500/SJ_LENGTH<SJ_RPM_PRE*SJ_READS/DEPTH/20 and SJ_SEQNUM_THIS*500/SJ_LENGTH<SJ_SEQNUM_PRE*SJ_READS/DEPTH/20 and SJ_RPM_NEXT>0) or (SJ_RPM_THIS*500/SJ_LENGTH<SJ_RPM_NEXT*SJ_READS/DEPTH/20 and SJ_SEQNUM_THIS*500/SJ_LENGTH<SJ_SEQNUM_NEXT*SJ_READS/DEPTH/20 and SJ_RPM_PRE>0):
			continue
		else:
			LIST_OUT.remove(i)
			N+=1
	print "\033[31mSJ information --- total: %s, removed: %s, left: %s\033[0m"%(len(LIST_SJ),N,len(LIST_SJ)-N)
	return LIST_OUT

def fun_read_sj(PATH):
	try:
		FILE_IN=open(PATH,"r")
	except IOError:
		print "There is no file in %s"%PATH
		os._exit(0)
	DICT_OUT={}
	for L in FILE_IN:
		LINE=L.split()
		if not DICT_OUT.has_key(LINE[3]):
			DICT_OUT[LINE[3]]=[]
		DICT_OUT[LINE[3]].append(LINE[0:3]+LINE[4:])
	return DICT_OUT

def fun_help():
	print "\033[40;32m"
	print "usage:"
	print "piFinder_FindIntron picluster.bed sj.tab pigene.bed"
	print "\033[0m"
	os._exit(0)

#########process################
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.stderr.write("-----------User interrupted!!!-----------")
        sys.exit(0)


