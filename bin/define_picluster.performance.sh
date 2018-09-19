#!/bin/bash

if [ $# -lt 3 ];then
	echo0 5 "$0 piRNA.bed2 picluster.bed genome"
	exit 1
fi

PATH_PROG=`dirname $0` && PATH_ANNO=${PATH_PROG%/bin}/annotation/$3
GENOME_LENGTH=`awk '{sum+=$2} END{print sum}' ${PATH_ANNO}/$3.chrom.size`
PI_LENGTH=`awk '{sum+=($3-$2)} END{print sum}' $2`
TOTAL_PI=(`awk '{if($3-$2>23 && $3-$2<33 && (substr($7,1,1)=="T" || substr($7,10,1)=="A")){sum1+=$4/$5;if($5==1){sum2+=$4}}else{sum3+=$4/$5;if($5==1){sum4+=$4}}} END{print sum1" "sum2" "sum3" "sum4}' $1`)
CLUSTER_PI=(`bedtools intersect -F 0.5 -a $2 -b $1 -wo | awk '{if($9-$8>23 && $9-$8<33 && (substr($13,1,1)=="T" || substr($13,10,1)=="A")){sum1+=$10/$11;if($11==1){sum2+=$10}}else{sum3+=$10/$11;if($11==1){sum4+=$10}}} END{print sum1" "sum2" "sum3" "sum4}'`)
echo -e "genome_length\t${GENOME_LENGTH}\npicluster_length\t${PI_LENGTH}\nsncRNA_reads\t${TOTAL_PI[2]}\nsncRNA_reads_inCluter\t${CLUSTER_PI[2]}\npiRNA_reads\t${TOTAL_PI[0]}\npiRNA_reads_inCluster\t${CLUSTER_PI[0]}\nuniq_sncRNA_reads\t${TOTAL_PI[3]}\nuniq_sncRNA_reads_inCluster\t${CLUSTER_PI[3]}\nuniq_piRNA_reads\t${TOTAL_PI[1]}\nuniq_piRNA_reads_inCluster\t${CLUSTER_PI[1]}"
