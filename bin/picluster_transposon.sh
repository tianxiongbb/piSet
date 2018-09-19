#!/bin/bash

if [ $# -lt 1 ];then
	echo0 "$0 in.insert(other srna removed) genome CPU outdir(suggest to use a new one)"
fi

INSERT=`readlink -f $1`
PATH_ANNO=`dirname $0` && PATH_ANNO=${PATH_ANNO%/bin}/annotation/$2
[ ! -d $4 ] && mkdir -p $4
cd $4

# map to piclustero
echo0 2 "map to picluster......"
bowtie -r -S -v 1 -a --best --strata -p $3 \
	${PATH_ANNO}/BowtieIndex/picluster ${INSERT} \
	2>map.picluster.log | \
	samtools view -bhSF 0x4 - 2>/dev/null | \
	bedtools bamtobed -i - > map.picluster.bed && \
	insertBed_to_bed2 ${INSERT} map.picluster.bed > map.picluster.bed2 && \
	rm -rf map.picluster.bed 

# extract picluster srna reads
echo0 2 "extract picluster mapping srna reads......"
mkdir temp.bed2
seperate_bed2.py map.picluster.bed2 ${PATH_ANNO}/$2.picluster.size temp.bed2
cd temp.bed2
mkdir ../temp.insert
for i in *bed2
do
	NR=(`wc -l $i`)
	if [ $NR -gt 0 ];then
		awk 'BEGIN{FS=OFS="\t"} {a[$7]+=$4/$5} END{for(i in a){print i,a[i]}}' $i > ../temp.insert/${i%bed2}insert
	else
		# write fake seq
		echo -e "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\t1" > ../temp.insert/${i%bed2}insert
	fi
done

# map reads to transposon, use bed3 format: bed2 + picluster_name as the 8th column
echo0 2 "map reads to transposon, convert result to bed3 format......"
cd ../temp.insert
for i in *insert
do
	n=${i%.insert}
	bowtie -r -S -v 1 -a --best --strata -p $3 \
		${PATH_ANNO}/BowtieIndex/transposon $i \
		2>/dev/null | samtools view -bhSF 0x4 - 2>/dev/null | \
		bedtools bamtobed -i - > ${n}.bed
	# bed to bed2
	awk -v pn=${n} 'BEGIN{FS=OFS="\t";k=0} {if(ARGIND==1){seq[k]=$1;sum[k]=$2;k++}else if(ARGIND==2){t[$4]+=1}else{print $1,$2,$3,sum[$4],t[$4],$6,seq[$4],pn}}' ${n}.insert ${n}.bed ${n}.bed > ${n}.bed3
done
cat *bed3 > ../result.bed3
cd ../
#rm -rf temp.insert temp.bed2

# get the result matrix
awk 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){p[$1]=1}else if(ARGIND==2){t[$1]=1}else{if($6=="+"){a[$8","$1]+=$4/$5}}} END{for(j in t){printf "\t"j};print "";for(i in p){printf i;for(j in t){printf "\t"a[i","j]/1};print ""}}' ${PATH_ANNO}/$2.picluster.size ${PATH_ANNO}/BowtieIndex/transposon.sizes result.bed3 > result.sense.mat
awk 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){p[$1]=1}else if(ARGIND==2){t[$1]=1}else{if($6=="-"){a[$8","$1]+=$4/$5}}} END{for(j in t){printf "\t"j};print "";for(i in p){printf i;for(j in t){printf "\t"a[i","j]/1};print ""}}' ${PATH_ANNO}/$2.picluster.size ${PATH_ANNO}/BowtieIndex/transposon.sizes result.bed3 > result.anti.mat

echo0 4 "------ finished, congras🍺🍺🍺 ------"


