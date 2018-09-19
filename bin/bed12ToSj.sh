#!/bin/bash

if [ $# -lt 3 ];then
	echo0 5 "$0 in.bed12 overhang_of_SJ(suggest: 7) if_piRNA(0|1) out.prefix"
	echo0 4 "the 5th column of bed12 should be mapped times of each read. And the columns of output stands for chr,SJ_start,SJ_end,SJ_strand,SJ_reads,uniq_SJ_reads,multi_SJ_reads,Overhang_reads,uniq_Overhang_reads,multi_Overhang_reads"
	exit 1
fi

if [ $3 -eq 1 ];then
	awk 'BEGIN{FS=OFS="\t"} {split($11,a,",");split($12,b,",");if((a[1]+a[2])<24 || (a[1]+a[2])>32){next};split($11,a,",");for(i=2;i<=length(a);i++){s=a[i-1]+b[i-1]+$2;e=b[i]+$2;sj0[$1","s","e","$6]+=1/$5;if($5==1){sj1[$1","s","e","$6]++}else{sj2[$1","s","e","$6]+=1/$5}}} END{for(i in sj0){split(i,k,",");print k[1],k[2],k[3],k[4],sj0[i]/1,sj1[i]/1,sj2[i]/1}}' $1 | sort -k1,1 -k2,2n | awk -v oh=$2 'BEGIN{FS=OFS="\t"} {print $1,$2-oh,$2+oh,$1","$2","$3","$4","$5","$6","$7,0,$4;print $1,$3-oh,$3+oh,$1","$2","$3","$4","$5","$6","$7,0,$4}' - | awk 'BEGIN{FS=OFS="\t"} {if($2<0){$2=0};print $0}' - > $1.temp
else
	awk 'BEGIN{FS=OFS="\t"} {split($11,a,",");split($12,b,",");for(i=2;i<=length(a);i++){s=a[i-1]+b[i-1]+$2;e=b[i]+$2;sj0[$1","s","e","$6]+=1/$5;if($5==1){sj1[$1","s","e","$6]++}else{sj2[$1","s","e","$6]+=1/$5}}} END{for(i in sj0){split(i,k,",");print k[1],k[2],k[3],k[4],sj0[i]/1,sj1[i]/1,sj2[i]/1}}' $1 | sort -k1,1 -k2,2n | awk -v oh=$2 'BEGIN{FS=OFS="\t"} {print $1,$2-oh,$2+oh,$1","$2","$3","$4","$5","$6","$7,0,$4;print $1,$3-oh,$3+oh,$1","$2","$3","$4","$5","$6","$7,0,$4}' | awk 'BEGIN{FS=OFS="\t"} {if($2<0){$2=0};print $0}' > $1.temp
fi
intersectBed -a $1.temp -b $1 -f 1 -wo -split -s | awk 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){if($11==1){a1[$4]++}else{a2[$4]+=1/$11};a3[$4]+=1/$11}else{if(!b[$4]){split($4,k,",");print k[1],k[2],k[3],k[4],k[5],k[6],k[7],a3[$4]/1,a1[$4]/1,a2[$4]/1;b[$4]=1}}}' - $1.temp | awk '($3-$2)>50'  | awk 'BEGIN{FS=OFS="\t"} {$2=$2-1;print $0}'> $4.EEJ
awk 'BEGIN{FS=OFS="\t"} {if(!k[$4]){split($4,a,",");k[$4]=1;$4=a[1]","a[2]-1","a[2]-1","a[4]","a[5]","a[6]","a[7]}else{split($4,a,",");$4=a[1]","a[3]","a[3]","a[4]","a[5]","a[6]","a[7]};if(a[3]-a[2]<=50){next};print $0}' $1.temp | awk 'BEGIN{FS=OFS="\t"} {split($4,a,",");n=a[1]","a[2]","a[3]","a[4];k1[n]=1;k2[n]+=a[5];k3[n]+=a[6];k4[n]+=a[7];t1[n]=$1;t2[n]=$2;t3[n]=$3;t4[n]=$6} END{for (i in k1){print t1[i],t2[i],t3[i],i","k2[i]","k3[i]","k4[i],0,t4[i]}}' > $1.temp1
intersectBed -a $1.temp1 -b $1 -f 1 -wo -split -s | awk 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){if($11==1){a1[$4]++}else{a2[$4]+=1/$11};a3[$4]+=1/$11}else{if(!b[$4]){split($4,k,",");print k[1],k[2],k[3],k[4],k[5],k[6],k[7],a3[$4]/1,a1[$4]/1,a2[$4]/1;b[$4]=1}}}' - $1.temp1 | awk 'BEGIN{FS=OFS="\t"} {print $0}' > $4.SJ
#rm $1.temp $1.temp1
