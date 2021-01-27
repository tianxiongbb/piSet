#!/bin/bash

if [ $# -lt 2 ];then
	echo0 4 "$0 SJ_detected_by_hisat2 genome prefix fr|rf|f|r in.1.fq [in.2.fq]"
	echo0 4 "default CPU is 48"
	exit 1
fi

cpu=48
GENOME=$2
# remove genome mapping reads
if [ $# -gt 5 ];then
	bowtie2 -x /data/tusers/yutianx/tongji2/GitHuB/piSet/annotation/${GENOME}/Bowtie2Index/genome -1 $5 -2 $6 --sensitive -p ${cpu} --no-mixed --no-discordant --un-conc ${3}.-genome.fq > /dev/null
else
	bowtie2 -x /data/tusers/yutianx/tongji2/GitHuB/piSet/annotation/${GENOME}/Bowtie2Index/genome -U $5 --sensitive -p ${cpu} --un $3.-genome.fq > /dev/null
fi

# map to transposons
if [ $# -gt 5 ];then
	hisat2 -x /data/tusers/yutianx/tongji2/GitHuB/piSet/annotation/${GENOME}/Hisat2Index/transposon -1 $3.-genome.1.fq -2 $3.-genome.2.fq -S $3.-genome.sam -p ${cpu} --no-mixed --no-discordant --novel-splicesite-infile $1
	hisat2 -x /data/tusers/yutianx/tongji2/GitHuB/piSet/annotation/${GENOME}/Hisat2Index/transposon -1 $5 -2 $6 -S $3.sam -p ${cpu} --no-mixed --no-discordant --novel-splicesite-infile $1
else
	hisat2 -x /data/tusers/yutianx/tongji2/GitHuB/piSet/annotation/${GENOME}/Hisat2Index/transposon -U $3.-genome.fq -S $3.-genome.sam -p ${cpu} --novel-splicesite-infile $1
	hisat2 -x /data/tusers/yutianx/tongji2/GitHuB/piSet/annotation/${GENOME}/Hisat2Index/transposon -U $5 -S $3.sam -p ${cpu} --novel-splicesite-infile $1
fi

# sam to bam and then bed12
BB_SamToSortedBam.sh $3.sam ${cpu}
BB_SamToSortedBam.sh $3.-genome.sam ${cpu}
bedtools bamtobed -i $3.sort.bam -tag NH -bed12 -split > $3.bed12.tmp
bedtools bamtobed -i $3.-genome.sort.bam -tag NH -bed12 -split > $3.-genome.bed12.tmp
bed12Strand.sh $3.bed12.tmp $4 > $3.bed12
bed12Strand.sh $3.-genome.bed12.tmp $4 > $3.-genome.bed12
rm $3.bed12.tmp $3.-genome.bed12.tmp 

# get splicing efficiency
avl=`head -100 $3.bed12 | awk 'BEGIN{FS=OFS="\t"} {split($11,a,",");for(i=1;i<=length(a);i++){k[NR]+=a[i]}} END{for(i=1;i<=100;i++){l+=k[i]};print int(l/100)}'`
if [ $avl -lt 33 ];then
	bed12ToSj2.sh $3.-genome.bed12 3 1 $3.-genome $1
	bed12ToSj2.sh $3.bed12 3 1 $3 $1
else
	bed12ToSj2.sh $3.-genome.bed12 7 0 $3.-genome $1
	bed12ToSj2.sh $3.bed12 7 0 $3 $1
fi
awk 'BEGIN{FS=OFS="\t"} {p=$1":"$2"-"$3":"$4;if(ARGIND==1){a1[p]=$5}else{a2[p]=$8}} END{for(i in a1){print i,a1[i],a2[i]}}' $3.-genome.EEJ $3.EEJ > $3.final.EEJ


