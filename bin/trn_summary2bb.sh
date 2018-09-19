#!/bin/bash

if [ $# -lt 1 ];then
	echo0 5 "$0 in.summary genome"
	exit 1
fi

PATH_ANNO=`dirname $0` && CHROM_SIZE=${PATH_ANNO%/bin}/annotation/$2/$2.chrom.size
TYPE=`awk '{if(NR==1){if($0~/TransposonDirection/){print "insertion"}else{print "absense"}}else{exit}}' $1`

if [ "$TYPE" == "insertion" ];then
	awk 'BEGIN{FS=OFS="\t";cs[1]="229,245,224";cs[2]="216,235,213";cs[3]="204,226,203";cs[4]="192,217,192";cs[5]="180,207,182";cs[6]="168,198,172";cs[7]="156,189,161";cs[8]="144,179,151";cs[9]="132,170,141";cs[10]="120,161,130";cs[11]="108,151,120";cs[12]="96,142,109";cs[13]="84,133,99";cs[14]="72,123,79";cs[15]="60,114,78";cs[16]="48,105,68";cs[17]="36,95,58";cs[18]="24,86,47";cs[19]="12,77,37";cs[20]="0,68,27"} {if($5=="sense"){strand="+"}else{strand="-"};split($4,name,"_");ci=int($8*20)+1;if(ci==21){ci=20};if(NR>1){ttr=int($7/($8+0.0000001));if(ttr<$7){ttr=$7};print $1,$2,$3,$4";"$6";"$7"/"ttr";"strand,0,strand,$2,$3,cs[ci]}}' $1 | sort -k1,1 -k2,2n | awk 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){a[$1]=$2}else{if($3>a[$1]){$3=a[$1];$8=a[$1]};if($2>=a[$1]){$2=a[$1]-1;$7=a[$1]-1};print $0}}' ${CHROM_SIZE} - > $1.temp.bed
	awk 'BEGIN{FS=OFS="\t";cs[1]="229,245,224";cs[2]="216,235,213";cs[3]="204,226,203";cs[4]="192,217,192";cs[5]="180,207,182";cs[6]="168,198,172";cs[7]="156,189,161";cs[8]="144,179,151";cs[9]="132,170,141";cs[10]="120,161,130";cs[11]="108,151,120";cs[12]="96,142,109";cs[13]="84,133,99";cs[14]="72,123,79";cs[15]="60,114,78";cs[16]="48,105,68";cs[17]="36,95,58";cs[18]="24,86,47";cs[19]="12,77,37";cs[20]="0,68,27"} {if($6=="1p1"){if($5=="sense"){strand="+"}else{strand="-"};split($4,name,"_");ci=int($8*20)+1;if(ci==21){ci=20};if(NR>1){ttr=int($7/($8+0.0000001));if(ttr<$7){ttr=$7};print $1,$2,$3,$4";"$6";"$7"/"ttr";"strand,0,strand,$2,$3,cs[ci]}}}' $1 | sort -k1,1 -k2,2n | awk 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){a[$1]=$2}else{if($3>a[$1]){$3=a[$1];$8=a[$1]};if($2>=a[$1]){$2=a[$1]-1;$7=a[$1]-1};print $0}}' ${CHROM_SIZE} - > $1.temp1.bed
	awk 'BEGIN{FS=OFS="\t";cs[1]="229,245,224";cs[2]="216,235,213";cs[3]="204,226,203";cs[4]="192,217,192";cs[5]="180,207,182";cs[6]="168,198,172";cs[7]="156,189,161";cs[8]="144,179,151";cs[9]="132,170,141";cs[10]="120,161,130";cs[11]="108,151,120";cs[12]="96,142,109";cs[13]="84,133,99";cs[14]="72,123,79";cs[15]="60,114,78";cs[16]="48,105,68";cs[17]="36,95,58";cs[18]="24,86,47";cs[19]="12,77,37";cs[20]="0,68,27"} {if($6=="2p"){if($5=="sense"){strand="+"}else{strand="-"};split($4,name,"_");ci=int($8*20)+1;if(ci==21){ci=20};if(NR>1){ttr=int($7/($8+0.0000001));if(ttr<$7){ttr=$7};print $1,$2,$3,$4";"$6";"$7"/"ttr";"strand,0,strand,$2,$3,cs[ci]}}}' $1 | sort -k1,1 -k2,2n | awk 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){a[$1]=$2}else{if($3>a[$1]){$3=a[$1];$8=a[$1]};if($2>=a[$1]){$2=a[$1]-1;$7=a[$1]-1};print $0}}' ${CHROM_SIZE} - > $1.temp2.bed
	awk 'BEGIN{FS=OFS="\t";cs[1]="229,245,224";cs[2]="216,235,213";cs[3]="204,226,203";cs[4]="192,217,192";cs[5]="180,207,182";cs[6]="168,198,172";cs[7]="156,189,161";cs[8]="144,179,151";cs[9]="132,170,141";cs[10]="120,161,130";cs[11]="108,151,120";cs[12]="96,142,109";cs[13]="84,133,99";cs[14]="72,123,79";cs[15]="60,114,78";cs[16]="48,105,68";cs[17]="36,95,58";cs[18]="24,86,47";cs[19]="12,77,37";cs[20]="0,68,27"} {if($6=="singleton"){if($5=="sense"){strand="+"}else{strand="-"};split($4,name,"_");ci=int($8*20)+1;if(ci==21){ci=20};if(NR>1){ttr=int($7/($8+0.0000001));if(ttr<$7){ttr=$7};print $1,$2,$3,$4";"$6";"$7"/"ttr";"strand,0,strand,$2,$3,cs[ci]}}}' $1 | sort -k1,1 -k2,2n | awk 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){a[$1]=$2}else{if($3>a[$1]){$3=a[$1];$8=a[$1]};if($2>=a[$1]){$2=a[$1]-1;$7=a[$1]-1};print $0}}' ${CHROM_SIZE} - > $1.temp3.bed
	bedToBigBed $1.temp.bed ${CHROM_SIZE} ${1%.refined.bp.summary}.all.bb
	bedToBigBed $1.temp1.bed ${CHROM_SIZE} ${1%.refined.bp.summary}.1p1.bb
	bedToBigBed $1.temp2.bed ${CHROM_SIZE} ${1%.refined.bp.summary}.2p.bb
	bedToBigBed $1.temp3.bed ${CHROM_SIZE} ${1%.refined.bp.summary}.singleton.bb
	rm $1.temp.bed $1.temp1.bed $1.temp2.bed $1.temp3.bed 
else
	awk 'BEGIN{FS=OFS="\t";cs[1]="239,237,245";cs[2]="229,224,238";cs[3]="220,212,232";cs[4]="211,199,226";cs[5]="201,187,219";cs[6]="192,174,213";cs[7]="183,162,207";cs[8]="174,149,200";cs[9]="164,137,194";cs[10]="155,124,188";cs[11]="146,112,181";cs[12]="137,99,175";cs[13]="127,87,169";cs[14]="118,74,162";cs[15]="109,62,156";cs[16]="100,49,150";cs[17]="90,37,143";cs[18]="81,24,137";cs[19]="72,12,131";cs[20]="63,0,125"} {ci=int($9*20)+1;if(ci==21){ci=20};if(NR>1){print $1,$2,$3,$4";"$7"/"($7+$8/2)";"$9,0,".",$2,$3,cs[ci]}}' $1 | sort -k1,1 -k2,2n | awk 'BEGIN{FS=OFS="\t"} {if(ARGIND==1){a[$1]=$2}else{if($3>a[$1]){$3=a[$1];$8=a[$1]};if($2>=a[$1]){$2=a[$1]-1;$7=a[$1]-1};print $0}}' ${CHROM_SIZE} - > $1.temp.bed
	bedToBigBed $1.temp.bed ${CHROM_SIZE} ${1%.refined.bp.summary}.bb
	rm $1.temp.bed
fi
	

