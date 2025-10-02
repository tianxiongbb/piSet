#! /usr/bin/env python
# -*- coding: utf-8 -*-

#########module##############

import os, sys, time, re, copy
import bb_basic as bb

#########functions################
def main():
	#help info
	if len(sys.argv)<2:
		fun_help()
	global RPM
	global SEQNUM
	RPM=float(sys.argv[5])
	SEQNUM=float(sys.argv[6])
	DICT_PI_CLUSTER_EXON=fun_read_picluster_into_dict(sys.argv[1])
	DICT_PI_CLUSTER_INTRON=fun_read_picluster_into_dict(sys.argv[2])
	DICT_SJ=fun_read_sj_into_dict(sys.argv[3])
	DICT_MAJOR_EXON=fun_find_major_exon(DICT_PI_CLUSTER_EXON)
	DICT_OUT=fun_find_exon_and_intron(DICT_PI_CLUSTER_EXON,DICT_PI_CLUSTER_INTRON,DICT_MAJOR_EXON,DICT_SJ)
	fun_write_result(DICT_OUT,sys.argv[4])

def fun_read_sj_into_dict(PATH):
	try:
		FILE_IN=open(PATH,"r")
	except IOError:
		print "Cannot create %s"%PATH
		os._exit(0)
	DICT_SJ_TYPE={"1":"GT/AG","2":"CT/AC","3":"GC/AG","4":"CT/GC","5":"AT/AC","6":"GT/AT"}
	DICT_OUT={"+":{},"-":{}}
	for L in FILE_IN.readlines():
		LINE=L.split()
		PI_NAME=LINE[0]
		LINE=map(int,LINE)
		if LINE[3]==1:
			STRAND="+"
		else:
			STRAND="-"
		LINE[4]=DICT_SJ_TYPE[str(LINE[4])]
		LINE=LINE[1:3]+LINE[4:]
		try:
			DICT_OUT[STRAND][PI_NAME].append(LINE)
		except KeyError:
			DICT_OUT[STRAND][PI_NAME]=[]
			DICT_OUT[STRAND][PI_NAME].append(LINE)
	return DICT_OUT

def fun_read_picluster_into_dict(PATH):
	try:
		FILE_IN=open(PATH,"r")
	except IOError:
		print "Cannot create %s"%PATH
		os._exit(0)
	DICT_OUT={"+":{},"-":{}}
	for L in FILE_IN:
		LINE=L.split()
		STRAND=LINE[5]
		PI_NAME=LINE[3]
		if STRAND=="+":
			try:
				DICT_OUT["+"][PI_NAME].append([int(LINE[1]),int(LINE[2]),float(LINE[6]),float(LINE[7]),float(LINE[8]),float(LINE[9])])
			except KeyError:
				DICT_OUT["+"][PI_NAME]=[]
				DICT_OUT["+"][PI_NAME].append([int(LINE[1]),int(LINE[2]),float(LINE[6]),float(LINE[7]),float(LINE[8]),float(LINE[9])])
		else:
			try:
				DICT_OUT["-"][PI_NAME].append([int(LINE[1]),int(LINE[2]),float(LINE[8]),float(LINE[9]),float(LINE[6]),float(LINE[7])])
			except KeyError:
				DICT_OUT["-"][PI_NAME]=[]
				DICT_OUT["-"][PI_NAME].append([int(LINE[1]),int(LINE[2]),float(LINE[8]),float(LINE[9]),float(LINE[6]),float(LINE[7])])
	return DICT_OUT

def fun_find_major_exon(DICT_PI_CLUSTER):
	DICT_MAJOR_EXON={"+":{},"-":{}}
	global SEQNUM
	global RPM
	for STRAND in ["+","-"]:
		for PI_NAME in DICT_PI_CLUSTER[STRAND].keys():
			DICT_MAJOR_EXON[STRAND][PI_NAME]=[]
			N=0
			MID=0
			for i in range(len(DICT_PI_CLUSTER[STRAND][PI_NAME])):
				if DICT_PI_CLUSTER[STRAND][PI_NAME][i][2]>DICT_PI_CLUSTER[STRAND][PI_NAME][MID][2]:
					MID=i
				if DICT_PI_CLUSTER[STRAND][PI_NAME][i][2]>RPM and DICT_PI_CLUSTER[STRAND][PI_NAME][i][3]>SEQNUM:
					DICT_MAJOR_EXON[STRAND][PI_NAME].append(i)
					N=1
			if N==0:
				DICT_MAJOR_EXON[STRAND][PI_NAME].append(MID)
	return DICT_MAJOR_EXON

def fun_find_exon_and_intron(DICT_PI_CLUSTER_EXON,DICT_PI_CLUSTER_INTRON,DICT_MAJOR_EXON,DICT_SJ):
	DICT_MAJOR_EXON_COPY=copy.deepcopy(DICT_MAJOR_EXON)
	DICT_OUT={"+":{},"-":{}}
	for STRAND in ["+","-"]:
		for PI_NAME in DICT_MAJOR_EXON_COPY[STRAND].keys():
			DICT_OUT[STRAND][PI_NAME]=[]
			while DICT_MAJOR_EXON_COPY[STRAND][PI_NAME]:
				INI=DICT_MAJOR_EXON_COPY[STRAND][PI_NAME][0]
				INITIAL=INI
				DICT_OUT[STRAND][PI_NAME].append(DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][INITIAL][0:2])
				DICT_MAJOR_EXON_COPY[STRAND][PI_NAME].remove(INITIAL)
				for i in range(INITIAL+1,len(DICT_PI_CLUSTER_EXON[STRAND][PI_NAME])):
					K=0
					try:
						for j in range(len(DICT_SJ[STRAND][PI_NAME])):
							if fun_judge_sj(DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][INITIAL],DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][i],DICT_SJ[STRAND][PI_NAME][j]):
								print DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][INITIAL],DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][i],DICT_SJ[STRAND][PI_NAME][j]
								DICT_OUT[STRAND][PI_NAME][-1][-1]=DICT_SJ[STRAND][PI_NAME][j][0]
								DICT_OUT[STRAND][PI_NAME][-1]=DICT_OUT[STRAND][PI_NAME][-1]+[DICT_SJ[STRAND][PI_NAME][j][1],DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][i][1]]
								INITIAL=i
								if i in DICT_MAJOR_EXON_COPY[STRAND][PI_NAME]:
									DICT_MAJOR_EXON_COPY[STRAND][PI_NAME].remove(i)
								K=1
								break
						if K==0:
							INTRON_RPM=0
							for m in range(INITIAL,i):
								INTRON_RPM+=float(DICT_PI_CLUSTER_INTRON[STRAND][PI_NAME][m][2])
							INTRON_RPM_MINUS=0
							for m in range(INITIAL,i):
								INTRON_RPM_MINUS+=float(DICT_PI_CLUSTER_INTRON[STRAND][PI_NAME][m][4])
							INTRON_SEQNUM=0
							for m in range(INITIAL,i):
								INTRON_SEQNUM+=float(DICT_PI_CLUSTER_INTRON[STRAND][PI_NAME][m][3])
							INTRON_SEQNUM_MINUS=0
							for m in range(INITIAL,i):
								INTRON_SEQNUM_MINUS+=float(DICT_PI_CLUSTER_INTRON[STRAND][PI_NAME][m][5])
							INTRON_LENGTH=DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][i][0]-DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][INITIAL][1]
							EXON_RPM=float(DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][i][2])
							if ((INTRON_RPM/INTRON_LENGTH>0.005 and INTRON_SEQNUM/INTRON_LENGTH>0.02 and INTRON_LENGTH<10000) or INTRON_LENGTH<min(10000,100*EXON_RPM)) and INTRON_RPM_MINUS<INTRON_RPM:
								DICT_OUT[STRAND][PI_NAME][-1][-1]=DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][i][1]
								INITIAL=i
								if i in DICT_MAJOR_EXON_COPY[STRAND][PI_NAME]:
									DICT_MAJOR_EXON_COPY[STRAND][PI_NAME].remove(i)
					except KeyError:
						print "picluster %s in strand %s has no splicing junction"%(PI_NAME,STRAND)
						break
				INITIAL=INI
				for i in range(INITIAL-1,-1,-1):
					K=0
					try:
						for j in range(len(DICT_SJ[STRAND][PI_NAME])):
							if fun_judge_sj(DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][i],DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][INITIAL],DICT_SJ[STRAND][PI_NAME][j]):
								DICT_OUT[STRAND][PI_NAME][-1][0]=DICT_SJ[STRAND][PI_NAME][j][1]
								DICT_OUT[STRAND][PI_NAME][-1]=[DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][i][0],DICT_SJ[STRAND][PI_NAME][j][0]]+DICT_OUT[STRAND][PI_NAME][-1]
								INITIAL=i
								if i in DICT_MAJOR_EXON_COPY[STRAND][PI_NAME]:
									DICT_MAJOR_EXON_COPY[STRAND][PI_NAME].remove(i)
								K=1
								break
							if K==0:
								INTRON_RPM=0
								for m in range(i,INITIAL):
									INTRON_RPM+=float(DICT_PI_CLUSTER_INTRON[STRAND][PI_NAME][m][2])
								INTRON_RPM_MINUS=0
								for m in range(i,INITIAL):
									INTRON_RPM_MINUS+=float(DICT_PI_CLUSTER_INTRON[STRAND][PI_NAME][m][4])
								INTRON_SEQNUM=0
								for m in range(i,INITIAL):
									INTRON_RPM+=float(DICT_PI_CLUSTER_INTRON[STRAND][PI_NAME][m][3])
								INTRON_SEQNUM_MINUS=0
								for m in range(i,INITIAL):
									INTRON_SEQNUM_MINUS+=float(DICT_PI_CLUSTER_INTRON[STRAND][PI_NAME][m][5])
								INTRON_LENGTH=DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][INITIAL][0]-DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][i][1]
								EXON_RPM=float(DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][i][2])
								if ((INTRON_RPM/INTRON_LENGTH>0.005 and INTRON_SEQNUM/INTRON_LENGTH>0.02 and INTRON_LENGTH<10000) or INTRON_LENGTH<min(10000,100*EXON_RPM)) and and INTRON_RPM_MINUS<INTRON_RPM:
									DICT_OUT[STRAND][PI_NAME][-1][0]=DICT_PI_CLUSTER_EXON[STRAND][PI_NAME][i][0]
									INITIAL=i
									if i in DICT_MAJOR_EXON_COPY[STRAND][PI_NAME]:
										DICT_MAJOR_EXON_COPY[STRAND][PI_NAME].remove(i)
					except KeyError:
						print "picluster %s in strand %s has no splicing junction"%(PI_NAME,STRAND)
						break
	return DICT_OUT

def fun_judge_sj(LIST_EXON1,LIST_EXON2,LIST_SJ):
	L1=max(LIST_EXON1[1]-LIST_EXON1[0],2000)
	L2=max(LIST_EXON2[1]-LIST_EXON2[0],2000)
	if (LIST_SJ[0]-LIST_EXON1[1]<500 and (LIST_SJ[0]-LIST_EXON1[1]>(-500) or LIST_SJ[0]-LIST_EXON1[1]>L1/2) and LIST_SJ[0]-LIST_EXON1[1]>L1) and (LIST_SJ[1]-LIST_EXON2[0]>(-500) and (LIST_SJ[1]-LIST_EXON2[0]<500 or LIST_SJ[1]-LIST_EXON2[0]<L2/2) and LIST_SJ[1]-LIST_EXON2[0]<L2):
		return 1
	else:
		return 0

def fun_write_result(DICT_OUT,PATH):
	try:
		FILE_OUT=open(PATH,"w")
	except IOError:
		print "Cannot create %s"%PATH
		os._exit(0)
	N=0
	for STRAND in ["+","-"]:
		for PI_NAME in DICT_OUT[STRAND].keys():
			for PI_NAME_NUM in range(len(DICT_OUT[STRAND][PI_NAME])):
				for EXON_NUM in range(len(DICT_OUT[STRAND][PI_NAME][PI_NAME_NUM])/2):
					N+=1
					FILE_OUT.write("{0}\t{1}\t{2}\t{0}\t{3}\t{4}\n".format(PI_NAME,DICT_OUT[STRAND][PI_NAME][PI_NAME_NUM][EXON_NUM*2],DICT_OUT[STRAND][PI_NAME][PI_NAME_NUM][EXON_NUM]*2+1,N,STRAND))
	FILE_OUT.close()

def fun_help():
	print "\033[40;32m"
	print "usage:"
	print "piFinder_PiClusterToPiGene picluster_exon.bed picluster_intron.bed sj pigene.bed rpm_cutoff seqnum_cutoff"
	print "\033[0m"
	os._exit(0)

#########process################
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.stderr.write("-----------User interrupted!!!-----------")
        sys.exit(0)









