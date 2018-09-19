#!/usr/bin/env Rscript
Args=commandArgs()

# help----
if(length(Args)<8){
	stop(paste("usage:\n\t",substr(Args[4],8,100)," in.cov in.virus.homolog out.pdf\n",sep=""))
}

# function----
fun_plot_bucket=function(x){
	m=max(c(x[,3],-x[,4])); h=signif(m/4,1)
	par(mar=c(0,2,0,0.5))
	barplot(as.vector(x[,3]),col="#fcbba1",border="#a50f15",xaxt="n",space=0,yaxt="n",ylim=c(0,m))
	axis(2,h*(0:4),label=h*(0:4))
	par(mar=c(2,2,0,0.5))
	barplot(as.vector(x[,4]),col="#9ecae1",border="#08519c",xaxt="n",space=0,yaxt="n",ylim=c(-m,0))
	axis(2,-h*(0:4),label=c("",-h*(1:4)))
	axis(1,c(1,floor(dim(x)[1]/4*(1:4)))-0.5,label=c(1,x[dim(x)[1]/4*(1:4),2]))
}
cov=read.table(Args[6],header=F,row.names=NULL,check.names=F)
map=read.table(Args[7],header=F,row.names=1,check.names=F,sep="\t")
rn=unique(cov[,1])
pdf(Args[8], width=8, height=5, useDingbats=F)
laymat=matrix(c(1,2,2,3,3),5,1)
layout(laymat)
par(tcl=0.3)
par(mar=c(0,0,0,0),cex=1)
for(i in rn){
	plot.new()
	text(0.5,0.5,label=paste(i,map[i,3],sep="\n"),font=2,cex=1)
	x=cov[cov[,1]==i,]
	fun_plot_bucket(x)
}
dev.off()
