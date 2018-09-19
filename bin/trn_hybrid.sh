#!/bin/bash

if [ $# -lt 4 ];then
	echo0 1 "$0 father.bed7 mother.bed7 child.bed7 transposon.size"
	echo0 4 "this scripts is feed in father, mother and child's TE insertion bed7 file and can give you parent.inherit.bed father.inherit.bed, mother.inherit.bed, father.specific.bed, mother.specifc.bed and child.specifc.bed"
	exit 1
fi

CT_D=50
TRN_SIZE=`dirname $0` && TRN_SIZE=${TRN_SIZE%/bin}/annotation/$4/$4.transposon.size

# function
function bedtools_anti_window(){
	NUM_F=`awk 'BEGIN{FS=OFS="\t"} {if(NR==1){print NF}else{exit}}' $1`
	bedtools window -sm -w ${CT_D} -a $1 -b $2 | \
		awk -v numf=${NUM_F} 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){if($4==$(4+numf)){a[$1";"$2";"$3";"$4";"$6]=1}}else{if(!a[$1";"$2";"$3";"$4";"$6]){print $0}}}' - $1
}

# get prefix names
BN=`basename $1` && PREFIX_FATHER=${BN%.bed7}
BN=`basename $2` && PREFIX_MOTHER=${BN%.bed7}
BN=`basename $3` && PREFIX_CHILD=${BN%.bed7}
# don't regard strand information now; regard strand again but bear 50nt far away
# get parent.inherit and parent.sepcific
bedtools window -sm -w ${CT_D} -a $1 -b $2 | \
	awk 'BEGIN{FS=OFS="\t"} {if($4==$11){if(($3-$2)<($10-$9)){s=$2;e=$3}else{s=$9;e=$10};if(s<e){print $1,s,e,$4,$5,$6,$7,$12,$14}}}' > ${PREFIX_CHILD}.parent.temp
bedtools window -sm -w ${CT_D} -a ${PREFIX_CHILD}.parent.temp -b $3 | \
	awk 'BEGIN{FS=OFS="\t"} {if($4==$13){if(($3-$2)<($12-$11)){s=$2;e=$3}else{s=$11;e=$12};if(s<e){print $1,s,e,$4,$5,$6,$7,$8,$9,$14,$16,"parent.inherit"}}}' > ${PREFIX_CHILD}.parent.inherit.temp
bedtools_anti_window ${PREFIX_CHILD}.parent.temp $3 | \
	awk 'BEGIN{FS=OFS="\t"} {print $0,"none",0,"parent.specific"}' > ${PREFIX_CHILD}.parent.specific.temp

# get father.inherit and father.specific
bedtools_anti_window $1 ${PREFIX_CHILD}.parent.temp > ${PREFIX_CHILD}.father.temp
bedtools window -sm -w ${CT_D} -a ${PREFIX_CHILD}.father.temp -b $3 | \
	awk 'BEGIN{FS=OFS="\t"} {if($4==$11){if(($3-$2)<($10-$9)){s=$2;e=$3}else{s=$9;e=$10};if(s<e){print $1,s,e,$4,$5,$6,$7,"none",0,$12,$14,"father.inherit"}}}' > ${PREFIX_CHILD}.father.inherit.temp
bedtools_anti_window ${PREFIX_CHILD}.father.temp $3 | \
	awk 'BEGIN{FS=OFS="\t"} {print $0,"none",0,"none",0,"father.specific"}' > ${PREFIX_CHILD}.father.specific.temp

# get mother.inherit and mother.specific
bedtools_anti_window $2 ${PREFIX_CHILD}.parent.temp > ${PREFIX_CHILD}.mother.temp
bedtools window -sm -w ${CT_D} -a ${PREFIX_CHILD}.mother.temp -b $3 | \
	awk 'BEGIN{FS=OFS="\t"} {if($4==$11){if(($3-$2)<($10-$9)){s=$2;e=$3}else{s=$9;e=$10};if(s<e){print $1,s,e,$4,"none",$6,0,$5,$7,$12,$14,"mother.inherit"}}}' > ${PREFIX_CHILD}.mother.inherit.temp
bedtools_anti_window ${PREFIX_CHILD}.mother.temp $3 | \
	awk 'BEGIN{FS=OFS="\t"} {print $1,$2,$3,$4,"none",$6,0,$5,$7,"none",0,"mother.specific"}' > ${PREFIX_CHILD}.mother.specific.temp

# get child.specific
bedtools_anti_window $3 $1 > ${PREFIX_CHILD}.child.specific1.temp
bedtools_anti_window ${PREFIX_CHILD}.child.specific1.temp $2 | \
	awk 'BEGIN{FS=OFS="\t"} {print $1,$2,$3,$4,"none",$6,0,"none",0,$5,$7,"child.specific"}' > ${PREFIX_CHILD}.child.specific.temp
awk 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){a[$5"_"$4]+=$7;a["all_"$4]+=$7}else if(ARGIND==2){b[$10"_"$4]+=$11;b["all_"$4]+=$11}else{print $1,a["all_"$1]/1,a["1p1_"$1]/1,a["2p_"$1]/1,a["singleton_"$1]/1,b["all_"$1]/1,b["1p1_"$1]/1,b["2p_"$1]/1,b["singleton_"$1]/1}}' $3 ${PREFIX_CHILD}.child.specific.temp ${TRN_SIZE} > ${PREFIX_CHILD}.result

# merge all types of TE insertion
cat ${PREFIX_CHILD}.parent.inherit.temp ${PREFIX_CHILD}.parent.specific.temp ${PREFIX_CHILD}.father.inherit.temp ${PREFIX_CHILD}.father.specific.temp ${PREFIX_CHILD}.mother.inherit.temp ${PREFIX_CHILD}.mother.specific.temp ${PREFIX_CHILD}.child.specific.temp > ${PREFIX_CHILD}.bed12

rm ${PREFIX_CHILD}.*.temp
