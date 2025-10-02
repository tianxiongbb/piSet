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
		os._exit(0)
	DICT_SIGNAL=fun_read_signal_into_dict(sys.argv[1],sys.argv[2])
	LIST_SIGNAL=fun_dict_to_list(DICT_SIGNAL)
	bb.fun_write_list(LIST_SIGNAL,sys.argv[3])
	print "Done!!!"

def fun_read_signal_into_dict(PATH_PLUS,PATH_MINUS):
	try:
		FILE_IN_PLUS=open(PATH_PLUS,"r")
		FILE_IN_MINUS=open(PATH_MINUS,"r")
	except IOError:
		print "There is no file in %s"%PATH
		os._exit(0)
	DICT_SIGNAL={}
	while True:
		LINE=FILE_IN_PLUS.readline().split()
		if not LINE:
			break
		KEY=":".join(LINE[:2])
		DICT_SIGNAL[KEY]=LINE[2:]+["0","0"]
	while True:
		LINE=FILE_IN_MINUS.readline().split()
		if not LINE:
			break
		KEY=":".join(LINE[:2])
		if DICT_SIGNAL.has_key(KEY):
			DICT_SIGNAL[KEY][-2:]=LINE[6:]
		else:
			DICT_SIGNAL[KEY]=LINE[2:6]+["0","0"]+LINE[6:]
	return DICT_SIGNAL

def fun_dict_to_list(DICT_SIGNAL):
	LIST_SIGNAL=[]
	for KEY in DICT_SIGNAL.keys():
		L=[KEY.split(":")[0],KEY.split(":")[1]]+DICT_SIGNAL[KEY]
		LIST_SIGNAL.append(L)
	return LIST_SIGNAL

def fun_help():
	print "\033[40;32m"
	print "usage:"
	print "piFinder_MergePlusMinusSignal in.plus.signal in.minus.signal out.signal"
	print "\033[0m"
	os._exit(0)

#########process################
main()



