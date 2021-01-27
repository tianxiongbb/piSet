#!/bin/bash

if [ $# -lt 2 ];then
	echo0 1 "$0 in1.bed in2.bed"
	echo0 4 "this scripts is feed in two bed file and gives in1.specific.bed"
	exit 1
fi

CT_D=50

# function
function bedtools_anti_window(){
	NUM_F=`awk 'BEGIN{FS=OFS="\t"} {if(NR==1){print NF}else{exit}}' $1`
	bedtools window -w ${CT_D} -a $1 -b $2 | \
		awk -v numf=${NUM_F} 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){if($4==$(4+numf)){a[$1";"$2";"$3";"$4";"$6]=1}}else{if(!a[$1";"$2";"$3";"$4";"$6]){print $0}}}' - $1
}

# run
bedtools_anti_window $1 $2
