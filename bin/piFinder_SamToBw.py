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
	PATH=sys.argv[1]
	global PREFIX
	PREFIX=PATH.split(".")[0]
	global GENOME
	GENOME=sys.argv[3]
	if not os.path.isfile(GENOME):
		print "Cannot open genome file %s"%GENOME
		os._exit(0)
	global PATH_OUT
	PATH_OUT=sys.argv[2]
	global DICT_BED
	DICT_BED=fun_read_bed_into_dict(PATH)
	fun_get_bw(DICT_BED)
	fun_merge_bw()
	print "Done!!!"

def fun_read_bed_into_dict(PATH):
	try:
		FILE_IN=open(PATH,"r")
	except IOError:
		print "There is no file in %s"%PATH
		os._exit(0)
	DICT_BED={}
	while True:
		LINE=FILE_IN.readline().split()
		if not LINE:
			break
		if not DICT_BED.has_key(LINE[4]):
			DICT_BED[LINE[4]]=[]
		DICT_BED[LINE[4]].append(LINE)
	return DICT_BED

def fun_get_bw(DICT_BED):
	for MAP_NUM in DICT_BED.keys():
		global PREFIX
		global GENOME
		#write bed file
		fun_write_list(DICT_BED[MAP_NUM],"%s_%s.bed"%(PREFIX,MAP_NUM))
		#bedtools genomecov
		os.system("bedtools genomecov -bg -i %s_%s.bed -g %s > %s_%s.bedGraph"%(PREFIX,MAP_NUM,GENOME,PREFIX,MAP_NUM))
		#bedGraph to bigWig
		os.system("sort -k1,1 -k2,2n %s_%s.bedGraph > %s_%s_sorted.bedGraph"%(PREFIX,MAP_NUM,PREFIX,MAP_NUM))
		os.system("awk -v F=%s 'BEGIN{FS=OFS=\"\\t\"} {print $1,$2,$3,$4/F}' %s_%s_sorted.bedGraph > %s_%s_sorted.nor.bedGraph"%(MAP_NUM,PREFIX,MAP_NUM,PREFIX,MAP_NUM))
		os.system("bedGraphToBigWig %s_%s_sorted.nor.bedGraph %s %s_%s.bw"%(PREFIX,MAP_NUM,GENOME,PREFIX,MAP_NUM))
		os.system("rm {0}_{1}.bed {0}_{1}.bedGraph {0}_{1}_sorted.bedGraph {0}_{1}_sorted.nor.bedGraph".format(PREFIX,MAP_NUM))
		print "map_num %s processed..."%MAP_NUM

def fun_merge_bw():
	global DICT_BED
	global PREFIX
	global PATH_OUT
	global GENOME
	COMMAND="bigWigMerge"
	for MAP_NUM in DICT_BED.keys():
		COMMAND=COMMAND+" %s_%s.bw"%(PREFIX,MAP_NUM)
	COMMAND=COMMAND+" %s.bedGraph"%PREFIX
	os.system(COMMAND)
	os.system("sort -k1,1 -k2,2n %s.bedGraph > %s.sorted.bedGraph"%(PREFIX,PREFIX))
	os.system("bedGraphToBigWig %s.sorted.bedGraph %s %s"%(PREFIX,GENOME,PATH_OUT))
	os.system("rm %s.bedGraph %s.sorted.bedGraph"%(PREFIX,PREFIX))
	for MAP_NUM in DICT_BED.keys():
		os.system("rm %s_%s.bw"%(PREFIX,MAP_NUM))

def fun_help():
	print "\033[40;32m"
	print "usage:"
	print "piFinder_SamToBw in.bed out.bw picluster.size"
	print "\033[0m"
	os._exit(0)

#########process################
main()



