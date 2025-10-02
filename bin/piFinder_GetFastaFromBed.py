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
	#read parameters
	PATH_FASTA_IN=sys.argv[2]
	PATH_FASTA_OUT=sys.argv[3]
	PATH_BED=sys.argv[1]
	#process
	LIST_BED=bb.fun_read(PATH_BED, "bed")
	WINDOW_5P=0
	WINDOW_3P=0
	if len(sys.argv)>3:
		WINDOW_5P=int(sys.argv[4])
		WINDOW_3P=int(sys.argv[5])
		PATH_CHROM_SIZE=sys.argv[6]
		PATH_BED_OUT=sys.argv[7]
		DICT_CHROM_SIZE=bb.fun_read(PATH_CHROM_SIZE, "chrom_size", "dict")
		LIST_BED=fun_extend(LIST_BED,WINDOW_5P,WINDOW_3P,DICT_CHROM_SIZE)
	if len(sys.argv)<4:
		bb.fun_write_list(LIST_BED,"temp_getfasta.bed")
		fun_get_fasta("temp_getfasta.bed",PATH_FASTA_IN,PATH_FASTA_OUT)
		os.system("rm temp_getfasta.bed")
	else:
		bb.fun_write_list(LIST_BED,PATH_BED_OUT)
		fun_get_fasta(PATH_BED_OUT,PATH_FASTA_IN,PATH_FASTA_OUT)

def fun_extend(LIST_BED,WINDOW_5P,WINDOW_3P,DICT_CHROM_SIZE):
	LIST_EXTEND=[]
	for i in LIST_BED:
		if i[5]=="+":
			i[1]=max(i[1]-WINDOW_5P,1)
			i[2]=min(i[2]+WINDOW_3P,DICT_CHROM_SIZE[i[0]])
		else:
			i[2]=min(i[2]+WINDOW_5P,DICT_CHROM_SIZE[i[0]])
			i[1]=max(i[1]-WINDOW_3P,1)
		LIST_EXTEND.append(i)
	return LIST_EXTEND

def fun_get_fasta(PATH_BED,PATH_FASTA_IN,PATH_FASTA_OUT):
	R=os.system("bedtools getfasta -s -fi %s -fo %s -name -bed %s"%(PATH_FASTA_IN,PATH_FASTA_OUT,PATH_BED))
	if R!=0:
		print "bedtools getfasta error"

def fun_help():
	print "\033[40;32m"
	print "usage:"
	print "piFinder_GetFastaFromBed in.bed in.fa out.fa <window to extend for 5' and 3': eg 2000 5000> <chrom.size>"
	print "\033[0m"
	os._exit(0)

#########process################
main()

