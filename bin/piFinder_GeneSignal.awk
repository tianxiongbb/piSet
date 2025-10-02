#!/usr/bin/awk -f

BEGIN{
	FS=OFS="\t"
}

{
	SIGNAL[$4][1]=$1
	SIGNAL[$4][2]=$2
	SIGNAL[$4][3]=$3
	SIGNAL[$4][4]=$4
	SIGNAL[$4][5]=SIGNAL[$4][5]+$10/$11
	SIGNAL[$4][6]=$6
}

END{
	for(pi in SIGNAL){
		SIGNAL[pi][5]=SIGNAL[pi][5]/FACTOR
		print SIGNAL[pi][1]"\t"SIGNAL[pi][2]"\t"SIGNAL[pi][3]"\t"SIGNAL[pi][4]"\t"SIGNAL[pi][5]"\t"SIGNAL[pi][6]
	}
}
		



