#! /usr/bin/env python
# -*- coding: utf-8 -*-
#########readme##############


#########module##############

import os,sys,time,re

#########information#########

pro_name=sys.argv[0]
pro_author="Tianxiong Yu"
pro_date="Oct 22, 2015"
pro_purpose=""
pro_begin_time=time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))
begin_time=time.clock()

# print "\033[1;31;38m"
# print "*"*50
# print "ProgramName:\t"+pro_name
# print "Author:\t"+pro_author
# print "ProgramDate:\t"+pro_date
# print "Purpose:\t"+pro_purpose
# print "Begin time:\t"+pro_begin_time
# print "="*50
# print "\033[0m"

#########prepare#############

#os.chdir("/Users/duan/Desktop")
	##set your work dir

#########function############
def input_file(input,n):
	file_list=[]
	if len(input)!=n+1:
		print "The input file's number is wrong!!!"
		return
	else:
		for i in range(1,len(input)):
			file_list.append(open("%s"%input[i],"r"))
		return file_list
		
def delete(li,index):
	li=li[:index]+li[index+1:]
	return li

def unique_list(li):
	new_li=list(set(li))
	new_li.sort(li.index)
	return new_li

def read_file_into_list(file_in):
	l=[]
	while True:
		line=file_in.readline().split()
		if not line:
			break
		l.append(line)
	return l

def read_file_into_list_split_tab(file_in):
	l=[]
	while True:
		line=file_in.readline().split("\t")
		if line==[""]:
			break
		l.append(line)
	return l

def read_file_into_dict(file_in,key_num):
	###key_num is start with 0
	d={}
	while True:
		line=file_in.readline().split()
		if not line:
			break
		key=line[key_num]
		value=delete(line,key_num)
		d[key]=value
	return d

def write_list_into_file(li,file_out):
	###the value in li must be string not number
	if len(li)==1:
		content=li[0]
		file_out.write(content)
	if len(li)>1:
		if isinstance(li[0],list):
			for i in range(len(li)):
				li[i]="\t".join(li[i])
			content="\n".join(li)
			file_out.write(content)
		else:
			content="\n".join(li)
			file_out.write(content)
	file_out.close()

#########code################

#help document##
if len(sys.argv)<2:
	print "usage:"
	print "BB_Bed2Length.py in.bed2 out.nuldis"
	print "\033[1;31;38m"
	print "="*50
	print "\033[0m"
	os._exit(0)

##run##
f_in=open(sys.argv[1],"r")
f_out=open(sys.argv[2],"w")

d_out={}

for i in ["T","C","G","A","N"]:
	d_out[i]=[]
	for j in range(35):
		d_out[i].append(0)

while True:
	line=f_in.readline().split()
	if not line:
		break
	if len(line[0])>35:
		n=35
	else:
		n=len(line[0])
	for i in range(n):
		d_out[line[0][i]][i]+=float(line[1])

for i in ["T","C","G","A","N"]:
	f_out.write("%s"%(i))
	for j in range(35):
		f_out.write("\t%s"%d_out[i][j])
	f_out.write("\n")

f_out.close()

#########end#################

pro_end_time=time.strftime('%Y-%m-%d %H:%M:%S',\
	time.localtime(time.time()))
end_time=time.clock()
pro_time=end_time-begin_time

# print "\033[1;31;38m"
# print "="*50
# print "End time:\t"+pro_end_time
# print "Program run time:\t%.03f seconds"%pro_time
# print "*"*50
# print "\033[0m"
