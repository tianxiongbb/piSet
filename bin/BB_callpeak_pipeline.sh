#!/bin/bash

# help information
help_info(){
	echo0 1 $0" <option>* -t treat1.bam[,treat2.bam] -c control1.bam[,control2.bam] -o out.prefix -C chrom.size"
	echo "    OPTIONS:"
	echo "    -q qvalue for peak calling. --default: 0.05"
	echo "    -f {AUTO, BAM, BAMPE} single or paired bam files. default: AUTO"
	echo "    -g genome used for macs2 genome length. eg: mm; hg; dm. default: mm"
	echo "    -B buffer-size for macs2 callpeak, remember to set it less than 10000 when the number of chromosome is more than 100000. default: 100000"
	echo "    -h help information"
	echo "    -v version"
	exit 0
}

if [ $# -lt 1 ];then
	help_info
fi

# configuration
VERSION=OCT06_2017_1.0
CHROM_SIZE=/data/tusers/yutianx/tongji2/Annotation/ChromSize/mm10.chrom.size
FILE_FORMAT=AUTO
QVALUE=0.05
PVALUE=0
GENOME=mm
BUFF_SIZE=100000

# read parameters
while getopts "hvt:c:o:C:q:p:f:g:B:" OPTION; do
	case $OPTION in
		h)  help_info;;
		v)  echo0 1 "VERSION: "${VERSION} && exit 1;;
		t)  TREAT_FILE=${OPTARG};;
		c)  CONTROL_FILE=${OPTARG};;
		o)  OUT_PREFIX=${OPTARG};;
		C)  CHROM_SIZE=${OPTARG};;
		q)  QVALUE=${OPTARG};;
		f)  FILE_FORMAT=${OPTARG};;
		g)  GENOME=${OPTARG};;
		B)  BUFF_SIZE=${OPTARG};;
		*)  help_info;;
	esac
done

TREAT_FILE1=${TREAT_FILE%,*}
if [ `echo ${TREAT_FILE} | grep ","` ];then
	TREAT_FILE2=${TREAT_FILE#*,}
fi
CONTROL_FILE1=${CONTROL_FILE%,*}
if [ `echo ${CONTROL_FILE} | grep ","` ];then
	CONTROL_FILE2=${CONTROL_FILE#*,}
fi
OUT_DIR=`dirname ${OUT_PREFIX}`
OUT_NAME=`basename ${OUT_PREFIX}`
LOG_DIR=${OUT_DIR}"/log"

# check input
if [ ! -f ${TREAT_FILE1} ];then
	echo0 0 "treat_file1: ("${TREAT_FILE1}") is not a regular file. Abort!"
	exit 0
fi
if [ ! -f ${CONTROL_FILE1} ];then
	echo0 0 "control_file1: ("${CONTROL_FILE1}") is not a regular file. Abort!"
	exit 0
fi
if [ -z "${TREAT_FILE2}" -a -n "${CONTROL_FILE2}" ];then
	echo0 0 "control_file2 specified but treat_file2 not. Abort!"
	exit 0
fi
if [ -n "${TREAT_FILE2}" -a -z "${CONTROL_FILE2}" ];then
	echo0 0 "treat_file2 specified but control_file2 not. Abort!"
	exit 0
fi
if [ -n "${TREAT_FILE2}" -a ! -f ${TREAT_FILE1} ];then
	echo0 0 "treat_file2: ("${TREAT_FILE2}") is not a regular file. Abort!"
	exit 0
fi
if [ -n "${CONTROL_FILE2}" -a ! -f ${CONTROL_FILE1} ];then
	echo0 0 "treat_file2: ("${CONTROL_FILE2}") is not a regular file. Abort!"
	exit 0
fi
if [ ! -f ${CHROM_SIZE} ];then
	echo0 0 "chrom_size: ("${CHROM_SIZE}") is not a regular file Abort!"
	exit 0
fi

# preparation
echo0 3 "START->->->->->\t"`date`
if [ ! -d ${OUT_DIR} ];then
	mkdir ${OUT_DIR}
fi
if [ ! -d ${LOG_DIR} ];then
	mkdir ${LOG_DIR}
fi

# run macs2 for rep1, rep2 and rep1+rep2
if [ -n "${TREAT_FILE2}" ];then
	echo0 1 "run macs2 callpeak for rep1 + rep2\t"`date`
	set -x
	macs2 callpeak -q ${QVALUE} -t ${TREAT_FILE1} ${TREAT_FILE2} -c ${CONTROL_FILE1} ${CONTROL_FILE2} -f ${FILE_FORMAT} -g ${GENOME} --keep-dup all --outdir ${OUT_DIR} -n ${OUT_NAME}_rep0 -B --buffer-size ${BUFF_SIZE} > ${LOG_DIR}/macs2_callpeak_rep0.log 2>&1
	set +x
	echo0 1 "run macs2 callpeak for rep1\t"`date`
	set -x
	macs2 callpeak -q ${QVALUE} -t ${TREAT_FILE1} -c ${CONTROL_FILE1} -f ${FILE_FORMAT} -g ${GENOME} --keep-dup all --outdir ${OUT_DIR} -n ${OUT_NAME}_rep1 -B --buffer-size ${BUFF_SIZE} > ${LOG_DIR}/macs2_callpeak_rep1.log 2>&1
	set +x
	echo0 1 "run macs2 callpeak for rep2\t"`date`
	set -x
	macs2 callpeak -q ${QVALUE} -t ${TREAT_FILE2} -c ${CONTROL_FILE2} -f ${FILE_FORMAT} -g ${GENOME} --keep-dup all --outdir ${OUT_DIR} -n ${OUT_NAME}_rep2 -B --buffer-size ${BUFF_SIZE} > ${LOG_DIR}/macs2_callpeak_rep2.log 2>&1
	set +x
	# overlap peaks for rep1-rep2-rep0
	echo0 1 "call coordance peask\t"`date`
	bedtools intersect -wo -a ${OUT_PREFIX}_rep1_peaks.narrowPeak -b ${OUT_PREFIX}_rep0_peaks.narrowPeak | bedtools intersect -wo -a stdin -b ${OUT_PREFIX}_rep2_peaks.narrowPeak | awk -v PREFIX=${OUT_NAME} 'BEGIN{FS=OFS="\t";N=1} {sp=$2; ep=$3; if($12<sp){sp=$12}; if($13>ep){ep=$13}; if($23<sp){sp=$23}; if($24>ep){ep=$24}; print $1,sp,ep,PREFIX"_peak"N,"255","."; N++}' | sort -k1,1 -k2,2n | bedtools merge -i stdin | awk -v PREFIX=${OUT_NAME} 'BEGIN{FS=OFS="\t";N=1} {print $1,$2,$3,PREFIX"_replicated"N,255,"."}' > ${OUT_PREFIX}_replicated_peaks.bed
	# make bigBed files for visulization
	echo0 1 "make bigBed files for visulization\t"`date`
	awk 'BEGIN{FS=OFS="\t"} {print $1,$2,$3,$4,"255","."}' ${OUT_PREFIX}_rep1_peaks.narrowPeak | sort -k1,1 -k2,2n > ${OUT_PREFIX}_temp
	bedToBigBed ${OUT_PREFIX}_temp ${CHROM_SIZE} ${OUT_PREFIX}_rep1_peaks.bb
	awk 'BEGIN{FS=OFS="\t"} {print $1,$2,$3,$4,"255","."}' ${OUT_PREFIX}_rep2_peaks.narrowPeak | sort -k1,1 -k2,2n > ${OUT_PREFIX}_temp
	bedToBigBed ${OUT_PREFIX}_temp ${CHROM_SIZE} ${OUT_PREFIX}_rep2_peaks.bb
	awk 'BEGIN{FS=OFS="\t"} {print $1,$2,$3,$4,"255","."}' ${OUT_PREFIX}_rep0_peaks.narrowPeak | sort -k1,1 -k2,2n > ${OUT_PREFIX}_temp
	bedToBigBed ${OUT_PREFIX}_temp ${CHROM_SIZE} ${OUT_PREFIX}_rep0_peaks.bb
	awk 'BEGIN{FS=OFS="\t"} {print $1,$2,$3,$4,"255","."}' ${OUT_PREFIX}_replicated_peaks.bed | sort -k1,1 -k2,2n > ${OUT_PREFIX}_temp
	bedToBigBed ${OUT_PREFIX}_temp ${CHROM_SIZE} ${OUT_PREFIX}_replicated_peaks.bb
	rm ${OUT_PREFIX}_temp
	# make bigWig files for visulization
	echo0 1 "run macs2 bdgcmp to get FE and pvalue signal\t"`date`
	set -x
	macs2 bdgcmp -t ${OUT_PREFIX}_rep0_treat_pileup.bdg -c ${OUT_PREFIX}_rep0_control_lambda.bdg -m FE ppois --outdir ${OUT_DIR} -o ${OUT_NAME}_rep0.FE.bdg ${OUT_NAME}_rep1.pvalue.bdg > ${LOG_DIR}/macs2_bdgcmp_rep0.log 2>&1
	set +x
	echo0 1 "make bigWig files for visulization\t"`date`
	sort -k1,1 -k2,2n ${OUT_PREFIX}_rep0.FE.bdg > ${OUT_PREFIX}_rep0.FE.sort.bdg
	bedGraphToBigWig ${OUT_PREFIX}_rep0.FE.sort.bdg ${CHROM_SIZE} ${OUT_PREFIX}_rep0.FE.bw
	sort -k1,1 -k2,2n ${OUT_PREFIX}_rep0.pvalue.bdg > ${OUT_PREFIX}_rep0.pvalue.sort.bdg
	bedGraphToBigWig ${OUT_PREFIX}_rep0.pvalue.sort.bdg ${CHROM_SIZE} ${OUT_PREFIX}_rep0.pvalue.bw
	# summary
	cat << EOF > ${OUT_DIR}/plot.R
#!/usr/bin/env Rscript
###library packages###
###read data###
Args <- commandArgs()
prefix=Args[6]

peak_rep0=read.table(paste(prefix,"_rep0_peaks.narrowPeak",sep=""),header=F,row.names=NULL)
peak_rep1=read.table(paste(prefix,"_rep1_peaks.narrowPeak",sep=""),header=F,row.names=NULL)
peak_rep2=read.table(paste(prefix,"_rep2_peaks.narrowPeak",sep=""),header=F,row.names=NULL)
peak_repx=read.table(paste(prefix,"_replicated_peaks.bed",sep=""),header=F,row.names=NULL)

###plot###
pdf(paste(prefix,".summary.pdf",sep=""),height=4,width=4)
par(cex=5/6)
# peak numbers
x1=peak_repx[,3]-peak_repx[,2]+1
x2=peak_rep0[,3]-peak_rep0[,2]+1
x3=peak_rep1[,3]-peak_rep1[,2]+1
x4=peak_rep2[,3]-peak_rep2[,2]+1
boxplot(x1,x2,x3,x4,xaxt="n",col=c("#e41a1c","#377eb8","#4daf4a","#984ea3"),pch=20,cex=0.5,staplewex=0,ylim=c(0,max(x1,x2,x3,x4)*1.4),ylab="peak length")
lb=c(length(x1),length(x2),length(x3),length(x4))
lb=prettyNum(lb,big.mark=",")
text(1:4,c(max(x1),max(x2),max(x3),max(x4))*1.2,label=paste("n=",lb,sep=""),srt=45,col=c("#e41a1c","#377eb8","#4daf4a","#984ea3"),font=2)
axis(1,1:4,label=c("replicated","rep0","rep1","rep2"),las=3)
dev.off()
EOF
	Rscript ${OUT_DIR}/plot.R ${OUT_PREFIX}
	echo0 3 "FINISHED!!! <^_^>"
else
	echo0 1 "run macs2 callpeak for rep1\t"`date`
	set -x
	macs2 callpeak -q ${QVALUE} -t ${TREAT_FILE1} -c ${CONTROL_FILE1} -f ${FILE_FORMAT} -g ${GENOME} --keep-dup all --outdir ${OUT_DIR} -n ${OUT_NAME} -B --buffer-size ${BUFF_SIZE} > ${LOG_DIR}/macs2_callpeak_${OUT_NAME}.log 2>&1
	set +x
	# make bigBed files for visulization
	echo0 1 "make bigBed files for visulization\t"`date`
	awk 'BEGIN{FS=OFS="\t"} {print $1,$2,$3,$4,"255","."}' ${OUT_PREFIX}_peaks.narrowPeak | sort -k1,1 -k2,2n > ${OUT_PREFIX}_temp
	bedToBigBed ${OUT_PREFIX}_temp ${CHROM_SIZE} ${OUT_PREFIX}_peaks.bb
	rm ${OUT_PREFIX}_temp
	# make bigWig files for visulization
	echo0 1 "run macs2 bdgcmp to get FE and pvalue signal\t"`date`
	set -x
	macs2 bdgcmp -t ${OUT_PREFIX}_treat_pileup.bdg -c ${OUT_PREFIX}_control_lambda.bdg -m FE ppois --outdir ${OUT_DIR} -o ${OUT_NAME}.FE.bdg ${OUT_NAME}.pvalue.bdg > ${LOG_DIR}/macs2_bdgcmp_${OUT_NAME}.log 2>&1
	set +x
	echo0 1 "make bigWig files for visulization\t"`date`
	sort -k1,1 -k2,2n ${OUT_PREFIX}.FE.bdg > ${OUT_PREFIX}.FE.sort.bdg
	bedGraphToBigWig ${OUT_PREFIX}.FE.sort.bdg ${CHROM_SIZE} ${OUT_PREFIX}.FE.bw && rm ${OUT_PREFIX}.FE.sort.bdg 
	sort -k1,1 -k2,2n ${OUT_PREFIX}.pvalue.bdg > ${OUT_PREFIX}.pvalue.sort.bdg
	bedGraphToBigWig ${OUT_PREFIX}.pvalue.sort.bdg ${CHROM_SIZE} ${OUT_PREFIX}.pvalue.bw && rm ${OUT_PREFIX}.pvalue.sort.bdg 
	# summary
	cat << EOF > ${OUT_DIR}/plot.R
#!/usr/bin/env Rscript
###library packages###
###read data###
Args <- commandArgs()
prefix=Args[6]

peak_rep1=read.table(paste(prefix,"_peaks.narrowPeak",sep=""),header=F,row.names=NULL)

###plot###
pdf(paste(prefix,".summary.pdf",sep=""),height=4,width=2.5)
par(cex=5/6)
# peak numbers
x1=peak_rep1[,3]-peak_rep1[,2]+1
boxplot(x1,xaxt="n",col=c("#e41a1c"),pch=20,cex=0.5,staplewex=0,ylim=c(0,max(x1)*1.4),ylab="peak length")
lb=c(length(x1))
lb=prettyNum(lb,big.mark=",")
text(1,max(x1)*1.2,label=paste("n=",lb,sep=""),srt=45,col=c("#e41a1c"),font=2)
axis(1,1,label=c("rep1"),las=3)
dev.off()
EOF
	Rscript ${OUT_DIR}/plot.R ${OUT_PREFIX}
	echo0 3 "FINISHED!!! <^_^>"
fi
