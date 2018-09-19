#!/usr/bin/env Rscript
library(parallel)
Args=commandArgs()

# help----
if(length(Args)<7){
	stop(paste("usage:\n\t",substr(Args[4],8,100)," CPU prefix1 [prefix2_to_compare_with_prefix1]\n",sep=""))
}

# function----
fun_plot_scatter2=function(x, y, n1, n2, m){
	lb=expression(10^0,10^1,10^2,10^3,10^4,10^5)
	par(mar=c(4,4,4,2))
	cl=rep("black",length(x))
	cl[which((x+1)/(y+1)>2)]="#377eb8"
	cl[which((x+1)/(y+1)<1/2)]="#e41a1c"
	i1=log10(x+1); i2=log10(y+1)
	plot(-100,xlim=c(0,max(i1,i2)),ylim=c(0,max(i1,i2)),main=m,xaxt="n",yaxt="n",
	     xlab=paste(n1," + 1",sep=""),ylab=paste("",n2,"+ 1",sep=""))
	abline(0,1); abline(log10(2),1,lty=2); abline(-log10(2),1,lty=2)
	if(length(cl)<2000){
		points(i1,i2,pch=21,col="white",bg=cl)
	}else{
		points(i1,i2,pch=20,col=cl,cex=0.3)
	}
	if(length(imp_pi_dm3)==2){
		points(i1[imp_pi_dm3],i2[imp_pi_dm3],pch=1,cex=1.1)
		text(i1[imp_pi_dm3],i2[imp_pi_dm3],label=c("42AB","flam"),pos=1,font=2)
	}
	pv=signif(wilcox.test(i1,i2,paired=T)$p.value,2)
	text(0,max(i1,i2)*9/10,pos=4,label=paste("p-value = ",pv,sep=""),font=2)
	axis(1,0:5,label=lb)
	axis(2,0:5,label=lb)
}
fun_plot_scatter2_for_entropy=function(x, y, n1, n2){
	lb=expression(10^0,10^1,10^2,10^3,10^4,10^5)
	par(mar=c(4,4,4,2),bty="n")
	boxplot(log10(x[,1]+1),log10(y[,1]+1),log10(x[,2]+1),log10(y[,2]+1),at=c(1,2,4,5),staplewex=0,lty=1,
		col=c("#e41a1c","white","#377eb8","white"),border=c("black","#e41a1c","black","#377eb8"),
		ylab="RPM + 1",xaxt="n",main="uniqMappers",yaxt="n")
	axis(1,at=c(1.5,4.5),label=c("sense","antisense"),lwd=0)
	pv1=signif(wilcox.test(x[,1],y[,1],paired=T)$p.value,2)
	pv2=signif(wilcox.test(x[,2],y[,2],paired=T)$p.value,2)
	text(c(1.5,4.5),c(max(c(log10(x[,1]+1)),c(log10(y[,1]+1)))*8.5/10,
			  max(c(log10(x[,2]+1)),c(log10(y[,2]+1)))*8.5/10),label=c(pv1,pv2),srt=90)
	axis(2,0:5,label=lb)
	boxplot(log10(x[,3]+1),log10(y[,3]+1),log10(x[,4]+1),log10(y[,4]+1),at=c(1,2,4,5),staplewex=0,lty=1,
		col=c("#e41a1c","white","#377eb8","white"),border=c("black","#e41a1c","black","#377eb8"),
		ylab="RPM + 1",xaxt="n",main="allMappers",yaxt="n")
	axis(1,at=c(1.5,4.5),label=c("sense","antisense"),lwd=0)
	pv1=signif(wilcox.test(x[,3],y[,3],paired=T)$p.value,2)
	pv2=signif(wilcox.test(x[,4],y[,4],paired=T)$p.value,2)
	text(c(1.5,4.5),c(max(c(log10(x[,3]+1)),c(log10(y[,3]+1)))*8.5/10,
			  max(c(log10(x[,4]+1)),c(log10(y[,4]+1)))*8.5/10),label=c(pv1,pv2),srt=90)
	axis(2,0:5,label=lb)
	par(xpd=T)
	plot.new()
	legend("center",fill=c("black","white"),legend=c(n1,n2),y.intersp=1.5)
}

fun_sub=function(x){
	x=gsub("(",".",x,fixed=T)
	x=gsub(")",".",x,fixed=T)
	x=gsub("'",".",x,fixed=T)
	return(x)
}

# runs here----
# judge mode (single or comparison)
if(1){
	# comparison mode
	pre=paste(strsplit(Args[7],".",fixed=T)[[1]][1:(length(strsplit(Args[7],".",fixed=T)[[1]])-2)],collapse=".")
	sn1=strsplit(Args[7],"/")[[1]][length(strsplit(Args[7],"/")[[1]])]
	appendix=paste(strsplit(sn1,".",fixed=T)[[1]][(length(strsplit(sn1,".",fixed=T)[[1]])-1):length(strsplit(sn1,".",fixed=T)[[1]])],collapse=".")
	sn1=paste(strsplit(sn1,".",fixed=T)[[1]][1:(length(strsplit(sn1,".",fixed=T)[[1]])-2)],collapse=".")
	sn2=strsplit(Args[8],"/")[[1]][length(strsplit(Args[8],"/")[[1]])]
	sn2=paste(strsplit(sn2,".",fixed=T)[[1]][1:(length(strsplit(sn2,".",fixed=T)[[1]])-2)],collapse=".")
	# read files
	summary1=read.table(paste(Args[7],".summary",sep=""),header=T,row.names=1)
	summary2=read.table(paste(Args[8],".summary",sep=""),header=T,row.names=1)
	rn=row.names(summary1)
	imp_pi_dm3=c(which(rn=="42AB"),which(rn=="flam"))
	# plot
	# add scatterplot for comparing sample1 and sample2
	pdf(paste(pre,"_vs_",sn2,".",appendix,".scatter.pdf", sep=""), width=14, height=6, useDingbats=F)
	layout(matrix(c(1:7,7),2,4))
	par(tcl=0.3,bty="n")
	fun_plot_scatter2(summary1[,1]+summary1[,2],summary2[,1]+summary2[,2],
			  sn1,sn2,"uniqMap reads")
	fun_plot_scatter2(summary1[,3]+summary1[,4],summary2[,3]+summary2[,4],
			  sn1,sn2,"allMap reads")
	fun_plot_scatter2(summary1[,5]+summary1[,6],summary2[,5]+summary2[,6],
			  sn1,sn2,"uniqMap species")
	fun_plot_scatter2(summary1[,7]+summary1[,8],summary2[,7]+summary2[,8],
			  sn1,sn2,"allMap species")
	fun_plot_scatter2_for_entropy(summary1,summary2,sn1,sn2)
	dev.off()
}
