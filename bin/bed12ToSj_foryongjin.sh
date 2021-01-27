#!/bin/bash
# UPDATE at Oct28,2019
# now we need spliced reads to be "+" strand instead of the same strand to detected splicing junctions

if [ $# -lt 3 ];then
	echo0 5 "$0 in.uniq.bed12 overhang_of_SJ(suggest: 7) out.prefix in.annotated.SJ(gene.SJ)"
	echo0 4 "the 5th column of bed12 should be mapped times of each read. And the columns of output stands for chr,SJ_start,SJ_end,SJ_strand,SJ_reads,uniq_SJ_reads,multi_SJ_reads,Overhang_reads,uniq_Overhang_reads,multi_Overhang_reads"
	exit 1
fi

awk -v oh=$2 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){split($11,a,",");split($12,b,",");if(a[1]<oh || a[2]<oh){next};for(i=2;i<=length(a);i++){s=a[i-1]+b[i-1]+$2;e=b[i]+$2;sj0[$1","s","e","$6]++}}else{print $1,$2,$3,$4,$5,sj0[$1","$2","$3","$4]/1}}' $1 $4 | sort -k1,1 -k2,2n | awk -v oh=$2 'BEGIN{FS=OFS="\t"} {print $1,$2-oh,$2+oh,$1","$2","$3","$4","$5","$6,0,$4;print $1,$3-oh,$3+oh,$1","$2","$3","$4","$5","$6,0,$4}' - | awk 'BEGIN{FS=OFS="\t"} {if($2<0){$2=0};print $0}' - > $1.temp

intersectBed -a $1.temp -b $1 -f 1 -wo -split -s | awk 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){a[$4]++}else{if(!b[$4]){split($4,k,",");print k[1],k[2],k[3],k[4],k[5],k[6],a[$4]/1;b[$4]=1}}}' - $1.temp | awk 'BEGIN{FS=OFS="\t"} {print $0,$6/($6+$7/2+0.1)}' - > $3.EEJ

#rm $1.temp $1.temp1
