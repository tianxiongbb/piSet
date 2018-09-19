#!/bin/bash

if [ $# -lt 1 ];then
	echo0 1 "$0 \"pattern_of_bed12\""
	exit 1
fi

for i in $1
do
	echo -e ${i%.bed12}
	awk 'BEGIN{FS=OFS="\t"} {a[$12]++;b[$12]+=$11;c[$12]+=$9;d[$12]+=$7} END{print "#type\tnumber\tfather_population\tmother_population\tchild_population";for(i in a){print i,a[i],d[i],c[i],b[i]}}' $i
	echo -e ""
done
