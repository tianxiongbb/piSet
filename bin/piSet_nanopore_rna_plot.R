#!/usr/bin/env Rscript

### arguments ----
Args=commandArgs()
if(length(Args)<6){
	stop(paste(substr(Args[4],8,100),"in.forR","in.forR2","out.summary.txt",sep=" "))
}

### library packages ----

### functions ----

### main program ----
pre_result <- read.table(Args[6], header=F, row.names=NULL)
gene_list  <- read.table(Args[7], header=F, row.names=1)

tdf <- as.data.frame(matrix(0,dim(gene_list)[1],8))
row.names(tdf) <- row.names(gene_list)
colnames(tdf) <- c("geneType","readCount","medianReadLength","meanReadLength","minReadLength","maxReadLength","1stQTReadLength","3stQTReadLength")
tdf[,1] <- gene_list[,1]

for(i in row.names(gene_list)){
	l <- pre_result[which(pre_result[,1]==i),2]
	if(length(l)>0){
		tdf[i,2:8] <- c(length(l), median(l), mean(l), min(l), max(l), quantile(l,0.25), quantile(l,0.75))
	}
}

write.table(tdf, Args[8], sep="\t", quote=F)

