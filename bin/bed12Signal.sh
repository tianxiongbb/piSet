#!/bin/bash

if [ $# -lt 2 ];then
	echo0 5 "$0 in.bed12 in.exon.bed factor(1M/reads) in.gene.size out.preifx(will output prefix.readCount and prefix.rpkm)"
	echo0 5 "this script is not usable for stranded data"
	exit 1
fi

intersectBed -a $1 -b $2 -wo -nonamecheck -f 0.5 -split | awk -v f=$3 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){a[$16]+=1/$5}else{print $1,a[$1]}}' - $4 > $5.readCount
awk -v f=$3 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){a[$1]=$2}else{print a[$1]*f*1000/$2}}' $5.readCount $4 > $5.rpkm
