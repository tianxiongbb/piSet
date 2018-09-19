#!/bin/bash

if [ $# -lt 1 ];then
	echo0 5 "$0 in.bed9"
	echo0 5 "directly merge TE insertions in different strand"
	exit 1
fi

function bedtools_anti_window(){
	NUM_F=`awk 'BEGIN{FS=OFS="\t"} {if(NR==1){print NF}else{exit}}' $1`
	bedtools intersect -wo -a $1 -b $2 | \
		awk -v numf=${NUM_F} 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){if($4==$(4+numf)){a[$1";"$2";"$3";"$4";"$6]=1}}else{if(!a[$1";"$2";"$3";"$4";"$6]){print $0}}}' - $1
}

TEMP=${RANDOM}.${RANDOM}.${RANDOM}.${RANDOM}
bedtools intersect -S -wo -a $1 -b $1 | awk '$6=="+" && $4==$13' | awk 'BEGIN{FS=OFS="\t"} {if($2<$11){st=$11}else{st=$2};if($3<$12){ed=$3}else{ed=$12};if($5=="1p1" || $14=="1p1"){tp="1p1"}else if($5=="2p" || $14=="2p"){tp="2p"}else{tp="singleton"};print $1,st,ed,$4,tp,".",($8+$17)/($9+$18),$8+$17,$9+$18}' > ${TEMP}.merged
bedtools_anti_window $1 ${TEMP}.merged > ${TEMP}.notMerged
cat ${TEMP}.merged ${TEMP}.notMerged > $1
rm ${TEMP}.merged ${TEMP}.notMerged 
