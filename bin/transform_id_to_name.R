#!/usr/bin/env Rscript

###arguments
Args=commandArgs()
all_reads_sense_lendis=read.table(paste(Args[6],".all.reads.sense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
all_reads_anti_lendis=read.table(paste(Args[6],".all.reads.antisense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
all_species_sense_lendis=read.table(paste(Args[6],".all.species.sense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
all_species_anti_lendis=read.table(paste(Args[6],".all.species.antisense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
uniq_reads_sense_lendis=read.table(paste(Args[6],".uniq.reads.sense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
uniq_reads_anti_lendis=read.table(paste(Args[6],".uniq.reads.antisense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
uniq_species_sense_lendis=read.table(paste(Args[6],".uniq.species.sense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
uniq_species_anti_lendis=read.table(paste(Args[6],".uniq.species.antisense.lendis",sep=""),header=T,row.names=NULL,check.names=F)
pp=read.table(paste(Args[6],".pp",sep=""),header=T,row.names=NULL,check.names=F)
summary=read.table(paste(Args[6],".summary",sep=""),header=T,row.names=1)
rn=row.names(summary)
id_to_name=read.table(Args[7],header=F,row.names=1)

###modify tables
row.names(summary)=id_to_name[row.names(summary),1]
colnames(pp)=id_to_name[colnames(pp),1]
colnames(all_reads_sense_lendis)=id_to_name[colnames(all_reads_sense_lendis),1]
colnames(all_reads_anti_lendis)=id_to_name[colnames(all_reads_anti_lendis),1]
colnames(all_species_sense_lendis)=id_to_name[colnames(all_species_sense_lendis),1]
colnames(all_species_anti_lendis)=id_to_name[colnames(all_species_anti_lendis),1]
colnames(uniq_reads_sense_lendis)=id_to_name[colnames(uniq_reads_sense_lendis),1]
colnames(uniq_reads_anti_lendis)=id_to_name[colnames(uniq_reads_anti_lendis),1]
colnames(uniq_species_sense_lendis)=id_to_name[colnames(uniq_species_sense_lendis),1]
colnames(uniq_species_anti_lendis)=id_to_name[colnames(uniq_species_anti_lendis),1]
write.table(summary, paste(Args[6],".summary",sep=""), sep="\t", quote=F)
write.table(pp, paste(Args[6],".pp",sep=""), sep="\t", quote=F, row.names=F)
write.table(all_reads_sense_lendis, paste(Args[6],".all.reads.sense.lendis",sep=""), sep="\t", quote=F, row.names=F)
write.table(all_reads_anti_lendis, paste(Args[6],".all.reads.antisense.lendis",sep=""), sep="\t", quote=F, row.names=F)
write.table(all_species_sense_lendis, paste(Args[6],".all.species.sense.lendis",sep=""), sep="\t", quote=F, row.names=F)
write.table(all_species_anti_lendis, paste(Args[6],".all.species.antisense.lendis",sep=""), sep="\t", quote=F, row.names=F)
write.table(uniq_reads_sense_lendis, paste(Args[6],".uniq.reads.sense.lendis",sep=""), sep="\t", quote=F, row.names=F)
write.table(uniq_reads_anti_lendis, paste(Args[6],".uniq.reads.antisense.lendis",sep=""), sep="\t", quote=F, row.names=F)
write.table(uniq_species_sense_lendis, paste(Args[6],".uniq.species.sense.lendis",sep=""), sep="\t", quote=F, row.names=F)
write.table(uniq_species_anti_lendis, paste(Args[6],".uniq.species.antisense.lendis",sep=""), sep="\t", quote=F, row.names=F)
