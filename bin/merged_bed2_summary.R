#!/usr/bin/env Rscript
Args=commandArgs()

# function----
fun_zscore=function(x){
	x_HkGene=x[c(1:9,11:30)]
	x_treat=x[10]
	z=(x_treat-mean(x_HkGene))/sd(x_HkGene)
	return(z)
}
# read files
uniq_reads_sense_lendis=read.table(paste(Args[6],".uniq.reads.sense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
uniq_reads_anti_lendis=read.table(paste(Args[6],".uniq.reads.antisense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
uniq_species_sense_lendis=read.table(paste(Args[6],".uniq.species.sense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
uniq_species_anti_lendis=read.table(paste(Args[6],".uniq.species.antisense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
all_reads_sense_lendis=read.table(paste(Args[6],".all.reads.sense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
all_reads_anti_lendis=read.table(paste(Args[6],".all.reads.antisense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
all_species_sense_lendis=read.table(paste(Args[6],".all.species.sense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
all_species_anti_lendis=read.table(paste(Args[6],".all.species.antisense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
pp=read.table(paste(Args[6],".pp",sep=""),header=T,row.names=NULL,check.names=F)
summary=read.table(paste(Args[6],".summary",sep=""),header=T,row.names=1)
rn=row.names(summary)
# modify tables
summary=transform(summary, zscore=as.vector(apply(pp[,rn],2,fun_zscore)), pp_score=as.vector(t(pp[10,rn])))
summary[which(is.na(summary[,"zscore"])),"zscore"]=-1
write.table(summary, paste(Args[6],".summary",sep=""), sep="\t", quote=F)
row.names(pp)=1:30
write.table(pp, paste(Args[6],".pp",sep=""), sep="\t", quote=F)
row.names(uniq_reads_sense_lendis)=15:35
write.table(uniq_reads_sense_lendis, paste(Args[6],".uniq.reads.sense.lendis",sep=""), sep="\t", quote=F)
row.names(uniq_reads_anti_lendis)=15:35
write.table(uniq_reads_anti_lendis, paste(Args[6],".uniq.reads.antisense.lendis",sep=""), sep="\t", quote=F)
row.names(uniq_species_sense_lendis)=15:35
write.table(uniq_species_sense_lendis, paste(Args[6],".uniq.species.sense.lendis",sep=""), sep="\t", quote=F)
row.names(uniq_species_anti_lendis)=15:35
write.table(uniq_species_anti_lendis, paste(Args[6],".uniq.species.antisense.lendis",sep=""), sep="\t", quote=F)
row.names(all_reads_sense_lendis)=15:35
write.table(all_reads_sense_lendis, paste(Args[6],".all.reads.sense.lendis",sep=""), sep="\t", quote=F)
row.names(all_reads_anti_lendis)=15:35
write.table(all_reads_anti_lendis, paste(Args[6],".all.reads.antisense.lendis",sep=""), sep="\t", quote=F)
row.names(all_species_sense_lendis)=15:35
write.table(all_species_sense_lendis, paste(Args[6],".all.species.sense.lendis",sep=""), sep="\t", quote=F)
row.names(all_species_anti_lendis)=15:35
write.table(all_species_anti_lendis, paste(Args[6],".all.species.antisense.lendis",sep=""), sep="\t", quote=F)
