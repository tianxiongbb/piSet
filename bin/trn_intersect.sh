#!/bin/bash

if [ $# -lt 2 ];then
	echo0 1 "$0 insertion.bed genome"
	exit 1
fi

# variables
PREFIX=`basename $1` && PREFIX=${PREFIX%.bed*}
PATH_ANNO=`dirname $0` && PATH_ANNO=${PATH_ANNO%bin}annotation/$2
PICLUSTER=`readlink -f ${PATH_ANNO}/$2.picluster.bed`
MRNA_CDS=`readlink -f ${PATH_ANNO}/$2.mRNA.CDS.bed`
MRNA_5UTR=`readlink -f ${PATH_ANNO}/$2.mRNA.5UTR.bed`
MRNA_3UTR=`readlink -f ${PATH_ANNO}/$2.mRNA.3UTR.bed`
MRNA_INTRON=`readlink -f ${PATH_ANNO}/$2.mRNA.intron.bed`
ORNA_EXON=`readlink -f ${PATH_ANNO}/$2.otherRNA.exon.bed`
ORNA_INTRON=`readlink -f ${PATH_ANNO}/$2.otherRNA.intron.bed`
SNCRNA=`readlink -f ${PATH_ANNO}/$2.sncRNA.bed`
CHROM_SIZE=`readlink -f ${PATH_ANNO}/$2.chrom.size`
GENOME_LENGTH=`awk '{sum+=$2} END{print sum}' ${CHROM_SIZE}`

# intersect with elements
# intersect_with_feature in.bed in.feature.bed out
function intersect_with_feature(){
	LENGTH=`awk '{sum+=$3-$2} END{print sum}' $2`
	echo -e "genome_length\t${GENOME_LENGTH}\nfeature_length\t${LENGTH}" > $3
	echo -e "feature_insertion\t"$((`bedtools intersect -nonamecheck -a $1 -b $2 | wc -l`)) >> $3
	for i in {1..1000}
	do
		bedtools shuffle -i $2 -g ${CHROM_SIZE} > ${PREFIX}.shuffle.temp 
		echo -e "shuffle_insertion_"$i"\t"$((`bedtools intersect -nonamecheck -a $1 -b ${PREFIX}.shuffle.temp | wc -l`)) >> $3
	done
}

intersect_with_feature $1 ${PICLUSTER} ${PREFIX}.1.temp
intersect_with_feature $1 ${MRNA_CDS} ${PREFIX}.2.temp
intersect_with_feature $1 ${MRNA_3UTR} ${PREFIX}.3.temp
intersect_with_feature $1 ${MRNA_5UTR} ${PREFIX}.4.temp
intersect_with_feature $1 ${MRNA_INTRON} ${PREFIX}.5.temp
intersect_with_feature $1 ${ORNA_EXON} ${PREFIX}.6.temp
intersect_with_feature $1 ${ORNA_INTRON} ${PREFIX}.7.temp
intersect_with_feature $1 ${SNCRNA} ${PREFIX}.8.temp

echo -e "\tpicluster\tmRNA.CDS\tmRNA.3UTR\tmRNA.5UTR\tmRNA.intron\totherRNA.exon\totherRNA.intron\tsncRNA" > ${PREFIX}.head.temp
paste ${PREFIX}.1.temp ${PREFIX}.2.temp ${PREFIX}.3.temp ${PREFIX}.4.temp ${PREFIX}.5.temp ${PREFIX}.6.temp ${PREFIX}.7.temp ${PREFIX}.8.temp | cut -f 1,2,4,6,8,10,12,14,16 > ${PREFIX}.temp
cat ${PREFIX}.head.temp ${PREFIX}.temp > ${PREFIX}.intersect_features
rm ${PREFIX}.*temp
