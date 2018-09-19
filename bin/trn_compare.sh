#!/bin/bash

if [ $# -lt 2 ];then
	echo0 1 "$0 in1.bed9 in2.bed9"
	echo0 4 "this scripts is feed in two bed9 file and gives in1.specific.bed, in2.specific.bed and in1.in2.shared.bed"
	exit 1
fi

CT_D=50

# function
function bedtools_anti_window(){
	NUM_F=`awk 'BEGIN{FS=OFS="\t"} {if(NR==1){print NF}else{exit}}' $1`
	bedtools window -w ${CT_D} -a $1 -b $2 | \
		awk -v numf=${NUM_F} 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){if($4==$(4+numf)){a[$1";"$2";"$3";"$4";"$6]=1}}else{if(!a[$1";"$2";"$3";"$4";"$6]){print $0}}}' - $1
}

# get prefix names
BN=`basename $1` && PREFIX1=${BN%.bed9}
BN=`basename $2` && PREFIX2=${BN%.bed9}
# run
bedtools_anti_window $1 $2 > ${PREFIX1}.specific.bed
bedtools_anti_window $2 $1 > ${PREFIX2}.specific.bed
bedtools window -w ${CT_D} -a $1 -b $2 | \
	awk 'BEGIN{FS=OFS="\t"} {if($4==$13){if(($3-$2)<($12-$11)){s=$2;e=$3}else{s=$11;e=$12};if(s<=e){print $1,s,e,$4,$5,$6,$7,$14,$16}}}' > ${PREFIX1}.${PREFIX2}.shared.bed
