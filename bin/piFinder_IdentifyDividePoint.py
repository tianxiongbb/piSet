#! /usr/bin/env python
# -*- coding: utf-8 -*-

#########module##############

import os,sys,time,re
import bb_basic as bb

#########functions################
def main():
	#help info
	if len(sys.argv)<2:
		fun_help()
	LIST_BED_IN=bb.fun_read(sys.argv[1], "bed")
	print "bed file readed"
	DICT_BED=bed_to_dict(LIST_BED_IN)
	LIST_OUT=dict_to_list_out(DICT_BED)
	bb.fun_write_list(LIST_OUT,sys.argv[2])

def bed_to_dict(LIST_BED_IN):
	DICT_BED={}
	for i in LIST_BED_IN:
                if i[3] not in DICT_BED:
			if i[5]=="+":
				START_COL=1
			else:
				START_COL=2
			DICT_BED[i[3]]=[[],i[5],i[0]]
		DICT_BED[i[3]][0].append([i[START_COL],i[6],i[7]])
	print "bed list converted to dict"
	M=0
	print "%s picluster to be processed"%len(DICT_BED.keys())
	for i in range(2,len(DICT_BED.keys())+1):
		M+=1
		THIS=DICT_BED[str(i)][0]
		THIS_STRAND=DICT_BED[str(i)][1]
		PRE=DICT_BED[str(i-1)][0]
		if THIS[0][0]<PRE[-1][0] and DICT_BED[str(i)][2]==DICT_BED[str(i-1)][2]:
			print "find break point of the %sth and %sth piclusters"%(M-1,M)
			FASLE_NUMBER=[]
			for j in range(THIS[0][0],PRE[-1][0],100):
				FASLE_NUMBER.append(0)
				for m in range(len(THIS)):
					if THIS[m][0]<j and THIS_STRAND=="+":
						FASLE_NUMBER[-1]+=1
					elif THIS[m][0]<=j and THIS_STRAND=="-":
						FASLE_NUMBER[-1]+=1
					else:
						break
				for m in range(len(PRE)):
					if PRE[-(m+1)][0]>j:
						FASLE_NUMBER[-1]+=1
					else:
						break
			BREAK_POINT_INDEX=FASLE_NUMBER.index(min(FASLE_NUMBER))
			BREAK_POINT=THIS[0][0]+100*BREAK_POINT_INDEX
			for m in range(len(THIS)):
				THIS_START_INDEX=m
				if THIS[m][0]>=BREAK_POINT:
					break
			DICT_BED[str(i)][0]=DICT_BED[str(i)][0][THIS_START_INDEX:]
			for m in range(len(PRE)):
				PRE_START_INDEX=m
				if PRE[-(m+1)][0]<BREAK_POINT:
					break
			DICT_BED[str(i-1)][0]=DICT_BED[str(i-1)][0][:-PRE_START_INDEX]
			print "Break Point: %s"%BREAK_POINT
	return DICT_BED

def dict_to_list_out(DICT_BED):
	LIST_OUT=[]
	for i in range(1,len(DICT_BED.keys())+1):
		CHR=DICT_BED[str(i)][2]
		STRAND=DICT_BED[str(i)][1]
		for j in range(len(DICT_BED[str(i)][0])):
			RPM=DICT_BED[str(i)][0][j][1]
			SEQNUM=DICT_BED[str(i)][0][j][2]
			if STRAND=="+":
				START=DICT_BED[str(i)][0][j][0]
				END=DICT_BED[str(i)][0][j][0]+99
			else:
				START=DICT_BED[str(i)][0][j][0]-99
				END=DICT_BED[str(i)][0][j][0]
			LIST_OUT.append([CHR,START,END,str(i),0,STRAND,RPM,SEQNUM])
	return LIST_OUT

def fun_help():
	print "\033[40;32m"
	print "usage:"
	print "piFinder_IdentifyDividePoint in.bed out.bed"
	print "\033[0m"
	os._exit(0)

#########process################
main()




