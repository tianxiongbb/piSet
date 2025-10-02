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
	DICT_SIGNAL=fun_make_signal_dict(sys.argv[2])
	DICT_SIGNAL=fun_calculate_signal(DICT_SIGNAL,sys.argv[1])
	fun_write_result(DICT_SIGNAL,sys.argv[2],sys.argv[3])

def fun_make_signal_dict(PATH):
	DICT_SIGNAL={}
	try:
		FILE_IN=open(PATH,"r")
	except IOError:
		print "Cannot create %s"%PATH
		os._exit(0)
	for L in FILE_IN:
		LINE=L.split()
		DICT_SIGNAL[":".join(LINE[0:2])]=[0,0]
	return DICT_SIGNAL

def fun_calculate_signal(DICT_SIGNAL,PATH):
	try:
		FILE_IN=open(PATH,"r")
	except IOError:
		print "Cannot create %s"%PATH
		os._exit(0)
	while True:
		LINE=FILE_IN.readline().split()
		if not LINE:
			break
		DICT_SIGNAL[":".join(LINE[0:2])][0]+=(float(LINE[9])/float(LINE[10]))
		DICT_SIGNAL[":".join(LINE[0:2])][1]+=1
	return DICT_SIGNAL

def fun_write_result(DICT_SIGNAL,PATH1,PATH2):
	try:
		FILE_OUT=open(PATH2,"w")
	except IOError:
		print "Cannot create %s"%PATH1
		os._exit(0)
	FILE_IN=open(PATH1,"r")
	for L in FILE_IN:
		LINE=L.split()
		if LINE[-1]=="+":
			FILE_OUT.write(L[0:-1])
			FILE_OUT.write("\t%s\t%s\t0\t0\n"%(DICT_SIGNAL[":".join(LINE[0:2])][0],DICT_SIGNAL[":".join(LINE[0:2])][1]))
		else:
			FILE_OUT.write(L[0:-1])
			FILE_OUT.write("\t0\t0\t%s\t%s\n"%(DICT_SIGNAL[":".join(LINE[0:2])][0],DICT_SIGNAL[":".join(LINE[0:2])][1]))
	FILE_OUT.close()

def fun_help():
	print "\033[40;32m"
	print "usage:"
	print "piFinder_IntersectSignal intered.bed primary.bed out.bed"
	print "\033[0m"
	os._exit(0)

#########process################
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.stderr.write("-----------User interrupted!!!-----------")
        sys.exit(0)




