#!/usr/bin/env Rscript

### arguments ----
Args=commandArgs()
if(length(Args)<6){
	stop(paste("usage:\n", substr(Args[4],8,100), "out.pdf", "in.nuldis", "in.nuldis2...", sep=" "))
}

### library packages ----

### main program ----
# read data
list_nul=list()
for(i in 7:length(Args)){
	tn=strsplit(Args[i],"/")[[1]][length(strsplit(Args[i],"/")[[1]])]
	tn=strsplit(tn,".nuldis")[[1]][1]
	list_nul[[tn]] = as.matrix(read.table(Args[i], header=F, row.names=1))}

# open pdf
# plot nuldis
library(ggseqlogo)
library(ggplot2)
fym=0
for(n in names(list_nul)){
	t1=apply(list_nul[[n]],2,max)
	t2=apply(list_nul[[n]],2,sum)
	if(max(t1/(t2+0.0001))>0.8){ym=2}else{ym=1}
	fym=max(fym,ym)
}
p=ggseqlogo(list_nul, ncol=4)+ylim(0,fym)
if(length(list_nul)>=4){tw=16}else{tw=length(list_nul)*3}
th=ceiling(length(list_nul)/4)*2.5
ggsave(Args[6],p,width=tw,height=th)
