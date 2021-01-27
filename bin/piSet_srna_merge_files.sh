#!/bin/bash

if [ $# -lt 1 ];then
	echo0 5 "$0 in.dir(directory of bed2_summary)"
	exit 1
fi

cd $1
[ ! -d ../master_matrix ] && mkdir ../master_matrix 
merge_files.sh ".24-32nt.transposon.summary" 4 ../master_matrix/master.te.sense.rpm 1
merge_files.sh ".24-32nt.transposon.summary" 5 ../master_matrix/master.te.anti.rpm 1
merge_files.sh ".24-32nt.picluster.summary" 4 ../master_matrix/master.piC.sense.rpm 1
merge_files.sh ".24-32nt.picluster.summary" 5 ../master_matrix/master.piC.anti.rpm 1
merge_files.sh ".24-32nt.picluster.summary" 10 ../master_matrix/master.piC.anti.zscore 1
merge_files.sh ".24-32nt.picluster.summary" 11 ../master_matrix/master.piC.anti.ppscore 1
merge_files.sh ".24-32nt.transposon.summary" 10 ../master_matrix/master.te.sense.zscore 1
merge_files.sh ".24-32nt.transposon.summary" 11 ../master_matrix/master.te.sense.ppscore 1
