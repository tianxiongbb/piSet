#!/usr/bin/env python
# -*- coding: utf-8 -*-
#########readme##############


#########module##############

import os,sys,time,re

#########code################
file_signal=open(sys.argv[1],"r")
file_piRNA_gtf=open(sys.argv[2],"w")
seq_cutoff=float(sys.argv[3])
read_cutoff=float(sys.argv[4])
#open files
file_unmerged_gene=open("temp_unmerged_gene.bed","w")
file_unmerged_exon=open("temp_unmerged_exon.bed","w")
file_unmerged_exon_gtf=open("temp_unmerged_exon.gtf","w")
#preset args for signal filtering (rs: rpm sum; ss: seqnum sum; ln: exon length sum; gn:gene name; efw:exons for write; rs1: rpm sum for non-1U reads; ss1: seqsum sum for non-1U reads)
rs=0
ss=0
rs1=0
ss1=0
ln=0
gn=file_signal.readline().split()[3]
file_signal.seek(0)
efw=[]
while True:
	l=file_signal.readline().split()
	if not l:
		break
	#calculated rpm, seqnum, length for gene gn
	if l[3]==gn:
		rs+=float(l[7])
		ss+=float(l[6])
		rs1+=float(l[9])
		ss1+=float(l[8])
		ln+=(float(l[2])-float(l[1])+1)
		efw.append(l)
	#after calculation, filter gene gn if it has low piRNA abundance or piRNA complexity or with low 1U reads percentage
	else:
		if (rs*1000/ln>read_cutoff and rs>read_cutoff) and (ss>seq_cutoff or ss>0.5*rs) and ln>1000 and rs>rs1 and ss>0.33*ss1:
			#write each exon in gene gn after filtering
			for i in efw:
				#filter exons with low piRNA abundance or piRNA complexity compared to average level
				if float(i[7])*1000/(float(i[2])-float(i[1])+1)>float(rs*1000/ln/10) and float(i[6])*1000/(float(i[2])-float(i[1])+1)>float(ss*1000/ln/10):
					#add two column to file_unmerged_exon: average rpm and average seqnum; for downstream analysis: intergenic piRNA gene extend
					file_unmerged_exon.write("\t".join(i[0:8])+"\t"+str(rs*1000/ln)+"\t"+str(ss*1000/ln)+"\n")
					file_unmerged_exon_gtf.write("%s\tpiGcall\texon\t%s\t%s\t.\t%s\t.\tgene_id \"%s\";\n"%(i[0],i[1],i[2],i[5],i[3]))
		#reset the args
		rs=float(l[7])
		ss=float(l[6])
		rs1=float(l[9])
		ss1=float(l[8])
		ln=(float(l[2])-float(l[1])+1)
		gn=l[3]
		efw=[l]
file_unmerged_exon.close()
file_unmerged_exon_gtf.close()

#open file
file_unmerged_exon=open("temp_unmerged_exon.bed","r")
#merge exons to one record by genename
d={}
while True:
	l=file_unmerged_exon.readline().split()
	if not l:
		break
	if l[3] not in d.keys():
		d[l[3]]=[l[0],int(l[1]),int(l[2]),l[4],l[5]]
	else:
		d[l[3]][1]=min(d[l[3]][1],int(l[1]))
		d[l[3]][2]=max(d[l[3]][2],int(l[2]))
for key in d.keys():
	file_unmerged_gene.write("%s\t%s\t%s\t%s\t%s\t%s\n"%(d[key][0],d[key][1],d[key][2],key,d[key][3],d[key][4]))

file_unmerged_gene.close()
#sort temp_unmerged_gene.bed
os.system("sort -k6,6 -k1,1 -k2,2n temp_unmerged_gene.bed > temp_unmerged_sorted.bed")
#overlap piRNA genes with reference
os.system("bedtools intersect -F 0.5 -f 0.5 -e -s -wo -a temp_unmerged_sorted.bed -b Protein.bed > temp_unmerged_sorted_intersect.bed")
file_unmerged_sorted=open("temp_unmerged_sorted.bed","r")
file_unmerged_sorted_intersect=open("temp_unmerged_sorted_intersect.bed","r")
#make list for temp_unmerged_gene_sorted.bed
list_unmerged_sorted=[]
while True:
	l=file_unmerged_sorted.readline().split()
	if not l:
		break
	list_unmerged_sorted.append(l)
#make dict for piRNA genes overlapped with protein_coding genes
map_id={}
while True:
	l=file_unmerged_sorted_intersect.readline().split("\t")
	if not l[0]:
		break
	gene_id=re.findall(r'gene_id \"([\w\.\-\_]+)\"',l[9])
	gene_name=re.findall(r'gene_name \"([\w\.\-\_]+)\"',l[9])
	if len(gene_name)==0:
		gene_name=gene_id
	if l[3] not in map_id.keys():
		map_id[l[3]]=[gene_name[0],int(l[12])]
	elif int(l[12])>map_id[l[3]][1]:
		map_id[l[3]]=[gene_name[0],int(l[12])]

for i in range(len(list_unmerged_sorted)):
	if list_unmerged_sorted[i][3] in map_id.keys():
		list_unmerged_sorted[i][4]=map_id[list_unmerged_sorted[i][3]][0]

#make map dict for piRNA gene names
#preset args (ch: chromosome; gn: intergenic piRNA name; eds: end site)
ch="NULL"
dict_pimap={}
gn=0
eds=0
for i in list_unmerged_sorted:
	if i[4]=="255":
		if i[0]!=ch:
			gn+=1
		elif (float(i[1])-int(sys.argv[6]))>eds:
			gn+=1
		ch=i[0]
		eds=float(i[2])
		dict_pimap[i[3]]="inter"+str(gn)
	else:
		dict_pimap[i[3]]=i[4]

#reread file_unmerged_exon
file_unmerged_exon.seek(0)
#write gtf file for merged piRNA genes
while True:
	l=file_unmerged_exon.readline().split()
	if not l:
		break
	gi=dict_pimap[l[3]]
	#pt: piRNA type
	if gi[0:2]=="in":
		pt="intergenic"
	else:
		pt="protein_coding"
	file_piRNA_gtf.write("%s\tpiGcall\texon\t%s\t%s\t.\t%s\t.\tgene_id \"pi-%s_%s\"; transcript_id \"TRANS-%s\"; piG_type \"%s\"; rpm \"%s\"; complexity \"%s\";\n"%(l[0],l[1],l[2],l[5],sys.argv[5],gi,gi,pt,l[8],l[9]))

file_piRNA_gtf.close()








