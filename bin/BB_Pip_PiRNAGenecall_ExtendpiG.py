#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os,sys,time,re

file_primary_piG=open(sys.argv[1],"r")
#preset extend dict
dict_extend={}
n=0
previous_gene="NULL"
while True:
	l=file_primary_piG.readline().split()
	n+=1
	if not l:
		dict_extend[previous_gene][3]=previous_end
		break
	if l[3]!=previous_gene:
		#dict: {left_extend, right_extend, start, end, strand, rpm, complexity}
		dict_extend[l[3]]=[0,0,int(l[1]),int(l[2]),l[5],float(l[6]),float(l[7]),l[0]]
		if n>1:
			dict_extend[previous_gene][3]=previous_end
		previous_gene=l[3]
	previous_end=int(l[2])

#iterate for each gene and confirm the extend length
n=0
step=int(sys.argv[2])
factor=float(sys.argv[3])
file_rpm_comp=open(sys.argv[6],"r")
dict_rpm_comp={}
dict_genome_size={}
while True:
	l=file_rpm_comp.readline().split()
	if not l:
		break
	if l[0] not in dict_rpm_comp.keys():
		dict_rpm_comp[l[0]]={}
		dict_genome_size[l[0]]=0
	dict_rpm_comp[l[0]][l[1]]=[float(l[6]),float(l[7]),float(l[8]),float(l[9])]
	dict_genome_size[l[0]]=int(l[1])
for piG in dict_extend.keys():
	n+=1
	if n%50==0:
		print "%s piNRA genes have been finished..."%n
	m=0
	while True:
		#if start coordinate < 1, stop iteration
		if dict_extend[piG][2]-step<1:
			break
		if m==0:
			key=dict_extend[piG][2]-dict_extend[piG][2]%step-step+1
		else:
			key=dict_extend[piG][2]-step
		m+=1
		#if not pass the cutoff, stop iteration
		if dict_extend[piG][4]=="+" and (dict_rpm_comp[dict_extend[piG][7]][str(key)][0]*step/1000/factor<dict_extend[piG][5]/2 or dict_rpm_comp[dict_extend[piG][7]][str(key)][1]*step/1000/factor<dict_extend[piG][6]/3):
			break
		if dict_extend[piG][4]=="-" and (dict_rpm_comp[dict_extend[piG][7]][str(key)][2]*step/1000/factor<dict_extend[piG][5]/2 or dict_rpm_comp[dict_extend[piG][7]][str(key)][3]*step/1000/factor<dict_extend[piG][6]/3):
			break
		dict_extend[piG][2]=key
	m=0
	while True:
		#if end coordinate > chromosome size, stop iteration
		if dict_extend[piG][3]+step>=dict_genome_size[dict_extend[piG][7]]:
			break
		if m==0:
			key=dict_extend[piG][3]-dict_extend[piG][3]%step+step+1
		else:
			key=dict_extend[piG][3]
		m+=1
		#if not pass the cutoff, stop iteration
		if dict_extend[piG][4]=="+" and dict_rpm_comp[dict_extend[piG][7]][str(key)][0]*step/1000/factor<dict_extend[piG][5]/3 or dict_rpm_comp[dict_extend[piG][7]][str(key)][1]*step/1000/factor<dict_extend[piG][6]/5:
			break
		if dict_extend[piG][4]=="-" and dict_rpm_comp[dict_extend[piG][7]][str(key)][2]*step/1000/factor<dict_extend[piG][5]/3 or dict_rpm_comp[dict_extend[piG][7]][str(key)][3]*step/1000/factor<dict_extend[piG][6]/5:
			break
		dict_extend[piG][3]=key+step

#make output list
n=0
previous_gene="NULL"
list_output=[]
file_primary_piG.seek(0)
while True:
	l=file_primary_piG.readline().split()
	n+=1
	if not l:
		list_output[-1][2]=dict_extend[previous_gene][3]
		break
	if l[3]!=previous_gene:		
		l[1]=dict_extend[l[3]][2]
		if n>1:
			list_output[-1][2]=dict_extend[previous_gene][3]
		previous_gene=l[3]
	list_output.append(l)
	previous_end=int(l[2])

#write piRNA gene bed file and gtf file
file_final_piRNA_bed=open("%s.piRNA.gene.final.bed"%sys.argv[5],"w")
file_final_piRNA_gtf=open("%s.piRNA.gene.final.gtf"%sys.argv[5],"w")
for i in list_output:
	file_final_piRNA_bed.write("%s\t%s\t%s\t%s\t%s\t%s\n"%(i[0],i[1],i[2],i[3],i[6],i[5]))
file_final_piRNA_bed.close()
for i in list_output:
	if i[3][0:2]=="in":
		pt="intergenic"
	else:
		pt="protein_coding"
	file_final_piRNA_gtf.write("%s\tpiGcall\texon\t%s\t%s\t.\t%s\t.\tgene_id \"pi-%s_%s\"; transcript_id \"TRANS-%s\"; piG_type \"%s\"; rpm \"%s\"; complexity \"%s\";\n"%(i[0],i[1],i[2],i[5],sys.argv[4],i[3],i[3],pt,i[6],i[7]))
file_final_piRNA_gtf.close()



