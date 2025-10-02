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
	DICT_BED=bb.fun_read(sys.argv[2], "bed", "dict", 4)
	LIST_IN=fun_read_file(sys.argv[1])
	LIST_OUT=fun_trans_coord(LIST_IN,DICT_BED,sys.argv[4])
	bb.fun_write_list(LIST_OUT,sys.argv[3])

def fun_read_file(PATH):
	try:
		FILE_IN=open(PATH,"r")
	except IOError:
		print "There is no file in %s"%PATH
		os._exit(0)
	LIST_IN=[]
	while True:
		LINE=FILE_IN.readline().split("\t")
		if not LINE[0]:
			break
		LIST_IN.append(LINE)
	return LIST_IN

def fun_trans_coord(LIST_IN,DICT_BED,FORMAT):
	LIST_OUT=[]
	DICT_SJ_TYPE={"1":"GT/AG","2":"CT/AC","3":"GC/AG","4":"CT/GC","5":"AT/AC","6":"GT/AT"}
	if FORMAT=="gtf":
		for i in LIST_IN:
			try:
				i[3]=DICT_BED[i[0]][1]+int(i[3])-1
				i[4]=DICT_BED[i[0]][1]+int(i[4])-1
				i[0]=DICT_BED[i[0]][0]
				LIST_OUT.append(i)
			except KeyError:
				print "no name %s in bed file"%i[0]
	elif FORMAT=="bed":
		for i in LIST_IN:
			try:
				i[1]=DICT_BED[i[0]][1]+int(i[1])-1
				i[2]=DICT_BED[i[0]][1]+int(i[2])-1
				i[0]=DICT_BED[i[0]][0]
				LIST_OUT.append(i)
			except KeyError:
				print "no name %s in bed file"%i[0]
	elif FORMAT=="sj":
		for i in LIST_IN:
			try:
				i[1]=DICT_BED[i[0]][1]+int(i[1])-1
				i[2]=DICT_BED[i[0]][1]+int(i[2])-1
				CHR=DICT_BED[i[0]][0]
				if i[3]=="1":
					i[3]="+"
				else:
					i[3]="-"
				i[4]=DICT_SJ_TYPE[i[4]]
				LIST_OUT.append([CHR,i[1],i[2],i[0],i[4],i[3],i[6],i[7],i[8]])
			except KeyError:
				print "no name %s in bed file"%i[0]
	else:
		print "unrecognized format: %s"%FORMAT
		os._exit(0)
	return LIST_OUT

def fun_write_list(LIST,PATH):
	try:
		FILE_OUT=open(PATH,"w")
	except IOError:
		print "Cannot create %s"%PATH
		os._exit(0)
	for i in LIST:
		for j in range(len(i)-1):
			FILE_OUT.write("%s\t"%i[j])
		FILE_OUT.write("%s"%i[len(i)-1])

def fun_help():
	print "\033[40;32m"
	print "usage:"
	print "piFinder_TransGenomeCoord in.file in.bed out.file file_format"
	print "\033[0m"
	os._exit(0)

#########process################
main()



