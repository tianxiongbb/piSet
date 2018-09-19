#!/bin/bash

if [ $# -lt 2 ];then
	echo0 1 "$0 \"common_suffix\" column_number_your_want_to_merge out.file [how_many_rows_to_skip_in_the_begin. default: 0]"
	echo0 4 "example1: to merge the 2nd column of all the files with suffix .rpkm, use"
	echo0 4 "merge_files.sh \".rpkm\" 2"
	echo0 6 "please make sure the files you want to merge is in the same order and same format"
	exit 1
fi

# file informations
if [ $# -lt 4 ];then
	SKIP_ROW=0
else
	SKIP_ROW=$4
fi
FILE1=`ls *$1 | head -1`
NUM_FILE=(`ls *$1 | wc -l`)

# judge NF
NUM_FIELD=`awk -v sr=${SKIP_ROW} 'BEGIN{FS=OFS="\t"} {if(NR>sr){if($1!~/^#/){print NF;exit}}}' ${FILE1}`

# judge FIELD needed for pasted file
FIELD=`awk -v nfield=${NUM_FIELD} -v nfile=${NUM_FILE} -v ncol=${2} 'BEGIN{OFS="\t";printf 1;for(i=1;i<=nfile;i++){printf ","(ncol+(i-1)*nfield)};print ""}'`

# make head of merged files
HEAD=${RANDOM}.${RANDOM}.${RANDOM}.${RANDOM}.head
for i in *$1;do
	echo -en "\t${i%${1}}" >> ${HEAD}
done
echo -e "" >> ${HEAD}

# merge files
paste *$1 | awk -v sr=${SKIP_ROW} 'NR>sr' | cut -f ${FIELD} | cat ${HEAD} - > $3.temp && mv $3.temp $3
rm ${HEAD}
