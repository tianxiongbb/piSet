#!/bin/bash

if [ $# -lt 2 ];then
	echo0 1 "piFinder_ExonToGene.sh in.bed out.bed"
	exit 1
fi

sort -k4,4 -k1,1 -k2,2n $1 | awk 'BEIGN{FS=OFS="\t"} {if(NR==1){chrom=$1;start=$2;ender=$3;name=$4;score=$5;strand=$6}else if($4==name){ender=$3}else{print chrom,start,ender,name,score,strand;chrom=$1;start=$2;ender=$3;name=$4;score=$5;strand=$6}} END{print chrom,start,ender,name,score,strand}' > $2

