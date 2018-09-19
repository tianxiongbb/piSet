#!/bin/bash

if [ $# -lt 2 ];then
	echo0 5 "$0 rawreads.insert prefix_of_piSet"
	exit 1
fi

ALL=(`awk '{sum1+=$2;sum2++} END{print sum1" "sum2}' $1`)
RRNA=(`awk '{sum1+=$4/$5;sum2+=1/$5} END{print sum1" "sum2}' $2.rRNA.bed2`)
HAIRPIN=(`awk '{sum1+=$4/$5;sum2+=1/$5} END{print sum1" "sum2}' $2.x_rRNA.hairpin.bed2`)
SNCRNA=(`awk '{sum1+=$4/$5;sum2+=1/$5} END{print sum1" "sum2}' $2.x_rRNA.x_hairpin.sncRNA.bed2`)
GENOME=(`awk '{sum1+=$4/$5;sum2+=1/$5;if($5==1){sum3+=$4;sum4++}} END{print sum1" "sum2" "sum3" "sum4}' $2.x_rRNA.x_hairpin.x_sncRNA.genome.bed2`)
PICLUSTER=(`awk '{sum1+=$4/$5;sum2+=1/$5} END{print sum1" "sum2}' $2.x_rRNA.x_hairpin.x_sncRNA.picluster.bed2`)
TRANSPOSON=(`awk '{sum1+=$4/$5;sum2+=1/$5} END{print sum1" "sum2}' $2.x_rRNA.x_hairpin.x_sncRNA.transposon.bed2`)
UNALIGNED=(`awk '{sum1+=$2;sum2++} END{print sum1" "sum2}' $2.x_rRNA.x_hairpin.x_sncRNA.unalign.insert`)

echo -e "#all_reads\t${ALL[0]}\nall_species\t${ALL[1]}\nrRNA_reads\t${RRNA[0]}\nrRNA_species\t${RRNA[1]}\nhairpin_reads\t${HAIRPIN[0]}\nhairpin_species\t${HAIRPIN[1]}\nsncRNA_reads\t${SNCRNA[0]}\nsncRNA_species\t${SNCRNA[1]}\ngenome_reads\t${GENOME[0]}\ngenome_species\t${GENOME[1]}\ngenome_unique_reads\t${GENOME[2]}\ngenome_unique_species\t${GENOME[3]}\ndirect_picluster_reads\t${PICLUSTER[0]}\ndirect_picluster_species\t${PICLUSTER[1]}\nunaligned_reads\t${UNALIGNED[0]}\ndirect_transposon_reads\t${TRANSPOSON[0]}\ndirect_transposon_species\t${TRANSPOSON[1]}\nunaligned_reads\t${UNALIGNED[0]}\nunaligned_species\t${UNALIGNED[1]}"
