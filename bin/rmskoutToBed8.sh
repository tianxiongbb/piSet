#!/bin/bash

if [ $# -lt 1 ];then
	echo0 5 "$0 in.rmsk.out"
	exit 1
fi

awk 'BEGIN{FS=" ";OFS="\t"} {if(NR>3){if($9=="+"){print $5,$6-1,$7,$10,$2,"+",$12,$13}else{print $5,$6,$7,$10,$2,"-",$14,$13}}}' $1
