#!/usr/bin/env Rscript
library(parallel)
Args=commandArgs()

# help----
if(length(Args)<8){
	stop(paste("usage:\n\t",substr(Args[4],8,100)," CPU out.prefix in.prefix1 [in.prefix2] [in.prefix3] [...]\n",sep=""))
}

# function----
fun_zscore=function(x){
	x_HkGene=x[c(1:9,11:30)]
	x_treat=x[10]
	z=(x_treat-mean(x_HkGene))/sd(x_HkGene)
	return(z)
}
fun_plot_lendis=function(x1, x2, m){
	par(mar=c(0,2,2,0.5))
	barplot(x1,space=0,border="white",col="#e41a1c",ylim=c(0,max(x1,x2)),xaxt="n")
	mtext(m,3,font=2)
	par(mar=c(2,2,0,0.5))
	barplot(-x2,space=0,border="white",col="#377eb8",ylim=c(-max(x1,x2),0),xaxt="n")
	axis(1,1:21-0.5,label=15:35,lwd=0,padj=-0.3)
}
fun_plot_pp=function(x){
	par(mar=c(3,3,3,1),cex=0.65)
	barplot(x,space=0,border="white",col="black",ylim=c(0,max(x)),xaxt="n")
	axis(1,c(1,10,20,30)-0.5,label=c(1,10,20,30),lwd=0)
	zs=round((x[10]-mean(x[c(1:9,11:30)]))/sd(x[c(1:9,11:30)]),2)
	text(10,max(x)*9/10,label=paste("z-score=",zs,sep=""),col="#e41a1c",font=2,pos=4,cex=1.2)
}

fun_plot_scatter2=function(x, y, x1, y1, n1, n2, m){
	par(mar=c(4,4,4,2))
	lb=expression(10^0,10^1,10^2,10^3,10^4,10^5)
	i1=log10(x+1); i2=log10(y+1)
	ti=which(i1>0 | i2>0); i1=i1[ti]; i2=i2[ti]
	i3=log10(x1+1); i4=log10(y1+1)
	ti=which(i3>0 | i4>0); i3=i3[ti]; i4=i4[ti]
	plot(i1,i2,xlim=c(0,max(i1,i2,i3,i4)),ylim=c(0,max(i1,i2,i3,i4)),main=m,xaxt="n",yaxt="n",
	     xlab=paste(n1," + 1",sep=""),ylab=paste(n2," + 1",sep=""),
	     col="#e41a1c",pch=20,cex=0.1)
	points(i3,i4,col="#377eb8",pch=20,cex=0.5)
	abline(0,1); abline(log10(2),1,lty=2); abline(-log10(2),1,lty=2)
	pv1=signif(wilcox.test(i1,i2,paired=T)$p.value,2)
	pv2=signif(wilcox.test(i3,i4,paired=T)$p.value,2)
	text(0,max(i1,i2,i3,i4)*9.5/10,pos=4,label=paste("p-value = ",pv1,sep=""),font=2,cex=0.8,col="#e41a1c")
	text(0,max(i1,i2,i3,i4)*9/10,pos=4,label=paste("p-value = ",pv2,sep=""),font=2,cex=0.8,col="#377eb8")
	text(max(i1,i2,i3,i4)*9/10,0,pos=3,label="NR",font=2,cex=1,col="#377eb8")
	text(max(i1,i2,i3,i4)*9/10,max(i1,i2,i3,i4)*0.5/10,pos=3,label="NM",font=2,cex=1,col="#e41a1c")
	axis(1,0:5,label=lb);axis(2,0:5,label=lb)
}

fun_sub=function(x){
	x=gsub("(",".",x,fixed=T)
	x=gsub(")",".",x,fixed=T)
	x=gsub("'",".",x,fixed=T)
	return(x)
}

# runs here----
system("echo0 2 \"....read files and plot\"")
# comparison mode
pre=paste(Args[7]) # output prefix
#appendix=paste(strsplit(sn1,".",fixed=T)[[1]][(length(strsplit(sn1,".",fixed=T)[[1]])-1):length(strsplit(sn1,".",fixed=T)[[1]])],collapse=".")
#sn1=paste(strsplit(sn1,".",fixed=T)[[1]][1:(length(strsplit(sn1,".",fixed=T)[[1]])-2)],collapse=".")
#sn2=strsplit(Args[8],"/")[[1]][length(strsplit(Args[8],"/")[[1]])]
#sn2=paste(strsplit(sn2,".",fixed=T)[[1]][1:(length(strsplit(sn2,".",fixed=T)[[1]])-2)],collapse=".")
# read all files into lists
for(ln in c(".24-32nt", ".20-23nt", ".0-100nt")){
	ld_me=list() # lendis
	ld_mi=list()
	ld_m5=list()
	ld_m3=list()
	ld_mc=list()
	ld_oe=list()
	ld_oi=list()
	pp_me=list() # ping-pong
	pp_mi=list()
	pp_m5=list()
	pp_m3=list()
	pp_mc=list()
	pp_oe=list()
	pp_oi=list()
	sum_me=list() # summary
	sum_mi=list()
	sum_m5=list()
	sum_m3=list()
	sum_mc=list()
	sum_oe=list()
	sum_oi=list()
	for(i in 8:length(Args)){
		ld_me[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.exon.lendis",sep=""),header=T,row.names=1,check.names=F)
		ld_mi[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.intron.lendis",sep=""),header=T,row.names=1,check.names=F)
		ld_m5[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.5UTR.lendis",sep=""),header=T,row.names=1,check.names=F)
		ld_m3[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.3UTR.lendis",sep=""),header=T,row.names=1,check.names=F)
		ld_mc[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.CDS.lendis",sep=""),header=T,row.names=1,check.names=F)
		ld_oe[[Args[i]]]=read.table(paste(Args[i],ln,".otherRNA.exon.lendis",sep=""),header=T,row.names=1,check.names=F)
		ld_oi[[Args[i]]]=read.table(paste(Args[i],ln,".otherRNA.intron.lendis",sep=""),header=T,row.names=1,check.names=F)
		pp_me[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.exon.pp",sep=""),header=F,row.names=1,check.names=F)
		pp_mi[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.intron.pp",sep=""),header=F,row.names=1,check.names=F)
		pp_m5[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.5UTR.pp",sep=""),header=F,row.names=1,check.names=F)
		pp_m3[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.3UTR.pp",sep=""),header=F,row.names=1,check.names=F)
		pp_mc[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.CDS.pp",sep=""),header=F,row.names=1,check.names=F)
		pp_oe[[Args[i]]]=read.table(paste(Args[i],ln,".otherRNA.exon.pp",sep=""),header=F,row.names=1,check.names=F)
		pp_oi[[Args[i]]]=read.table(paste(Args[i],ln,".otherRNA.intron.pp",sep=""),header=F,row.names=1,check.names=F)
		sum_me[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.exon.summary",sep=""),header=T,row.names=1,check.names=F)
		sum_mi[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.intron.summary",sep=""),header=T,row.names=1,check.names=F)
		sum_m5[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.5UTR.summary",sep=""),header=T,row.names=1,check.names=F)
		sum_m3[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.3UTR.summary",sep=""),header=T,row.names=1,check.names=F)
		sum_mc[[Args[i]]]=read.table(paste(Args[i],ln,".mRNA.CDS.summary",sep=""),header=T,row.names=1,check.names=F)
		sum_oe[[Args[i]]]=read.table(paste(Args[i],ln,".otherRNA.exon.summary",sep=""),header=T,row.names=1,check.names=F)
		sum_oi[[Args[i]]]=read.table(paste(Args[i],ln,".otherRNA.intron.summary",sep=""),header=T,row.names=1,check.names=F)
	}
	# plot
	# add scatterplot for comparing all samples pair by pair
	pdf(paste(pre,".gene",ln,".scatter.pdf", sep=""), width=5, height=5, useDingbats=F)
	par(tcl=0.3,bty="l")
	for(sn1 in names(sum_me)){
		for(sn2 in setdiff(names(sum_me), sn1)){
			fun_plot_scatter2(sum_me[[sn1]][,3],sum_me[[sn2]][,3],sum_oe[[sn1]][,3],sum_oe[[sn2]][,3],
					  sn1,sn2,"normalized all mapped sense reads in exons")
		}
	}
	dev.off()
	# lendis and pingpong plot for all samples
	sample_num = length(sum_me)
	pdf(paste(pre,".gene",ln,".pdf", sep=""), width=15, height=4/5*(1+5*sample_num), useDingbats=F)
	laymat=matrix(1,1+5*sample_num,5)
	for(i in 1:sample_num){
		laymat[5*i-3,]=10*i-8
		laymat[(5*i-2):(5*i+1),1]=10*i-7
		laymat[(5*i-2):(5*i-1),2]=10*i-6;laymat[(5*i):(5*i+1),2]=10*i-5
		laymat[(5*i-2):(5*i-1),3]=10*i-4;laymat[(5*i):(5*i+1),3]=10*i-3
		laymat[(5*i-2):(5*i-1),4]=10*i-2;laymat[(5*i):(5*i+1),4]=10*i-1
		laymat[(5*i-2):(5*i-1),5]=10*i;laymat[(5*i):(5*i+1),5]=10*i+1
	}
	layout(laymat) # layout as laymat
	# plot exon
	par(mar=c(0,0,0,0),cex=1);plot.new();text(0,0.5,label="mRNA exon",font=2,pos=4)
	for(sn in names(sum_me)){
		plot.new();text(0.5,0,label=sn,font=2,pos=3)
		par(cex=0.5,tcl=0.3,xpd=F)
		fun_plot_pp(pp_me[[sn]][,1]);fun_plot_lendis(ld_me[[sn]][,5],ld_me[[sn]][,6],"allMap reads");fun_plot_lendis(ld_me[[sn]][,1],ld_me[[sn]][,2],"uniqMap reads");fun_plot_lendis(ld_me[[sn]][,7],ld_me[[sn]][,8],"allMap species");fun_plot_lendis(ld_me[[sn]][,3],ld_me[[sn]][,4],"uniqMap species")
	}
	# plot 5utr
	par(mar=c(0,0,0,0),cex=1);plot.new();text(0,0.5,label="mRNA 5UTR",font=2,pos=4)
	for(sn in names(sum_m5)){
		plot.new();text(0.5,0,label=sn,font=2,pos=3,cex=1)
		par(cex=0.5,tcl=0.3,xpd=F)
		fun_plot_pp(pp_m5[[sn]][,1]);fun_plot_lendis(ld_m5[[sn]][,5],ld_m5[[sn]][,6],"allMap reads");fun_plot_lendis(ld_m5[[sn]][,1],ld_m5[[sn]][,2],"uniqMap reads");fun_plot_lendis(ld_m5[[sn]][,7],ld_m5[[sn]][,8],"allMap species");fun_plot_lendis(ld_m5[[sn]][,3],ld_m5[[sn]][,4],"uniqMap species")
	}
	# plot 3utr
	par(mar=c(0,0,0,0),cex=1);plot.new();text(0,0.5,label="mRNA 3UTR",font=2,pos=4)
	for(sn in names(sum_m3)){
		par(mar=c(0,0,0,0),cex=1);plot.new();text(0.5,0,label=sn,font=2,pos=3)
		par(cex=0.5,tcl=0.3,xpd=F)
		fun_plot_pp(pp_m3[[sn]][,1]);fun_plot_lendis(ld_m3[[sn]][,5],ld_m3[[sn]][,6],"allMap reads");fun_plot_lendis(ld_m3[[sn]][,1],ld_m3[[sn]][,2],"uniqMap reads");fun_plot_lendis(ld_m3[[sn]][,7],ld_m3[[sn]][,8],"allMap species");fun_plot_lendis(ld_m3[[sn]][,3],ld_m3[[sn]][,4],"uniqMap species")
	}
	# plot cds
	par(mar=c(0,0,0,0),cex=1);plot.new();text(0,0.5,label="mRNA CDS",font=2,pos=4)
	for(sn in names(sum_mc)){
		par(mar=c(0,0,0,0),cex=1);plot.new();text(0.5,0,label=sn,font=2,pos=3)
		par(cex=0.5,tcl=0.3,xpd=F)
		fun_plot_pp(pp_mc[[sn]][,1]);fun_plot_lendis(ld_mc[[sn]][,5],ld_mc[[sn]][,6],"allMap reads");fun_plot_lendis(ld_mc[[sn]][,1],ld_mc[[sn]][,2],"uniqMap reads");fun_plot_lendis(ld_mc[[sn]][,7],ld_mc[[sn]][,8],"allMap species");fun_plot_lendis(ld_mc[[sn]][,3],ld_mc[[sn]][,4],"uniqMap species")
	}
	# plot intron
	par(mar=c(0,0,0,0),cex=1);plot.new();text(0,0.5,label="mRNA intron",font=2,pos=4)
	for(sn in names(sum_mi)){
		par(mar=c(0,0,0,0),cex=1);plot.new();text(0.5,0,label=sn,font=2,pos=3)
		par(cex=0.5,tcl=0.3,xpd=F)
		fun_plot_pp(pp_mi[[sn]][,1]);fun_plot_lendis(ld_mi[[sn]][,5],ld_mi[[sn]][,6],"allMap reads");fun_plot_lendis(ld_mi[[sn]][,1],ld_mi[[sn]][,2],"uniqMap reads");fun_plot_lendis(ld_mi[[sn]][,7],ld_mi[[sn]][,8],"allMap species");fun_plot_lendis(ld_mi[[sn]][,3],ld_mi[[sn]][,4],"uniqMap species")
	}
	# plot exon for other RNA
	par(mar=c(0,0,0,0),cex=1);plot.new();text(0,0.5,label="otherRNA exon",font=2,pos=4)
	for(sn in names(sum_oe)){
		par(mar=c(0,0,0,0),cex=1);plot.new();text(0.5,0,label=sn,font=2,pos=3)
		par(cex=0.5,tcl=0.3,xpd=F)
		fun_plot_pp(pp_oe[[sn]][,1]);fun_plot_lendis(ld_oe[[sn]][,5],ld_oe[[sn]][,6],"allMap reads");fun_plot_lendis(ld_oe[[sn]][,1],ld_oe[[sn]][,2],"uniqMap reads");fun_plot_lendis(ld_oe[[sn]][,7],ld_oe[[sn]][,8],"allMap species");fun_plot_lendis(ld_oe[[sn]][,3],ld_oe[[sn]][,4],"uniqMap species")
	}
	# plot intron for other RNA
	par(mar=c(0,0,0,0),cex=1);plot.new();text(0,0.5,label="otherRNA intron",font=2,pos=4)
	for(sn in names(sum_oi)){
		par(mar=c(0,0,0,0),cex=1);plot.new();text(0.5,0,label=sn,font=2,pos=3)
		par(cex=0.5,tcl=0.3,xpd=F)
		fun_plot_pp(pp_oi[[sn]][,1]);fun_plot_lendis(ld_oi[[sn]][,5],ld_oi[[sn]][,6],"allMap reads");fun_plot_lendis(ld_oi[[sn]][,1],ld_oi[[sn]][,2],"uniqMap reads");fun_plot_lendis(ld_oi[[sn]][,7],ld_oi[[sn]][,8],"allMap species");fun_plot_lendis(ld_oi[[sn]][,3],ld_oi[[sn]][,4],"uniqMap species")
	}
	dev.off()
}
