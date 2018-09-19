#!/bin/bash

if [ $# -lt 4 ];then
	echo0 5 "$0 out.file in1.bed9 in2.bed9..."
	echo0 4 "merge all in files and make a comprehensive trn insertion set (remove those are singleton and not overlapped with others)."
	exit 1
fi

n=1
cp $2 $1.temp1
for i in $@
do
	if [ $n -gt 2 ];then
		cp $i $1.temp2
		trn_compare.sh $1.temp1 $1.temp2
		awk 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){print $1,$2,$3,$4,"1p1",$6,$7,$8,$9}else{if($5!="singleton"){print $1,$2,$3,$4,$5,$6,$7,$8,$9}}}' $1.temp1.$1.temp2.shared.bed $1.temp1.specific.bed $1.temp2.specific.bed > $1.temp1
	fi
	n=`expr $n + 1`
done
awk 'BEGIN{FS=OFS="\t"} {print $1,$2,$3,$4,0,$6}' $1.temp1 > $1
rm $1.temp*
