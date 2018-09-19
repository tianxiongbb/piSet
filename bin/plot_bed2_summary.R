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
fun_plot_bucket=function(x){
	m=max(c(x[,3],-x[,4])); h=signif(m/4,1)
	par(mar=c(0,2,2,0.5))
	barplot(as.vector(x[,3]),col="#fcbba1",border="#fcbba1",xaxt="n",space=0,yaxt="n",ylim=c(0,m))
	barplot(as.vector(x[,5]),col="#a50f15",border="#a50f15",xaxt="n",space=0,yaxt="n",add=T)
	axis(2,h*(0:4),label=h*(0:4))
	legend(dim(x)[1]/3,m*1.1,legend=c("uniqReads","allReads"),fill=c("#a50f15","#fcbba1"),xpd=T,ncol=2,bty="n")
	par(mar=c(2,2,0,0.5))
	barplot(as.vector(x[,4]),col="#9ecae1",border="#9ecae1",xaxt="n",space=0,yaxt="n",ylim=c(-m,0))
	barplot(as.vector(x[,6]),col="#08519c",border="#08519c",xaxt="n",space=0,yaxt="n",add=T)
	axis(2,-h*(0:4),label=c("",-h*(1:4)))
	axis(1,c(1,floor(dim(x)[1]/4*(1:4)))-0.5,label=c(1,x[dim(x)[1]/4*(1:4),2]))
}
fun_plot_lendis2=function(l1, l2, rn, m){
	maxN = 0
	if(rn!=0){
		for(sn in names(l1)){maxN=max(maxN, max(l1[[sn]][,rn]), max(l2[[sn]][,rn]))}
		for(sn in names(l1)){
			par(mar=c(0,2,2,0.5))
			barplot(l1[[sn]][,rn],space=0,border="white",col="#e41a1c",xaxt="n",ylim=c(0,maxN))
			if(sn==names(l1)[1]){mtext(m,3,font=2)}
			par(mar=c(2,2,0,0.5))
			barplot(-l2[[sn]][,rn],space=0,border="white",col="#377eb8",xaxt="n",ylim=c(-maxN,0))
			axis(1,1:21-0.5,label=15:35,lwd=0,padj=-0.3)
		}
	}else{
		for(sn in names(l1)){maxN=max(maxN, max(apply(l1[[sn]],1,sum)), max(apply(l2[[sn]],1,sum)))}
		for(sn in names(l1)){
			par(mar=c(0,2,2,0.5))
			barplot(apply(l1[[sn]],1,sum),space=0,border="white",col="#e41a1c",xaxt="n",ylim=c(0,maxN))
			mtext(m,3,font=2)
			par(mar=c(2,2,0,0.5))
			barplot(-apply(l2[[sn]],1,sum),space=0,border="white",col="#377eb8",xaxt="n",ylim=c(-maxN,0))
			axis(1,1:21-0.5,label=15:35,lwd=0,padj=-0.3)
		}
	}
}
fun_plot_pp2=function(l, rn){
	maxN = 0
	if(rn!=0){
		for(sn in names(l)){maxN=max(maxN, max(l[[sn]][,rn]))}
		for(sn in names(l)){
			par(mar=c(3,3,3,1),cex=0.65)
			barplot(l[[sn]][,rn],space=0,border="white",col="black",xaxt="n",ylim=c(0,maxN))
			axis(1,c(1,10,20,30)-0.5,label=c(1,10,20,30),lwd=0)
			if(sn==names(l)[1]){mtext("ping-pong",3,font=2)}
			zs=round((l[[sn]][10,rn]-mean(l[[sn]][c(1:9,11:30),rn]))/sd(l[[sn]][c(1:9,11:30),rn]),2)
			text(10,maxN*9/10,label=paste("z-score=",zs,sep=""),col="#e41a1c",font=2,pos=4,cex=1.2)
		}
	}else{
		for(sn in names(l)){maxN=max(maxN, max(apply(l[[sn]],1,sum)))}
		for(sn in names(l)){
			par(mar=c(3,3,3,1),cex=0.65)
			barplot(apply(l[[sn]],1,sum),space=0,border="white",col="black",xaxt="n",ylim=c(0,maxN))
			axis(1,c(1,10,20,30)-0.5,label=c(1,10,20,30),lwd=0)
			if(sn==names(l)[1]){mtext("ping-pong",3,font=2)}
			zs=round((apply(l[[sn]],1,sum)[10]-mean(apply(l[[sn]],1,sum)[c(1:9,11:30)]))/sd(apply(l[[sn]],1,sum)[c(1:9,11:30)]),2)
			text(10,maxN*9/10,label=paste("z-score=",zs,sep=""),col="#e41a1c",font=2,pos=4,cex=1.2)
		}
	}
}
fun_plot_bucket2=function(l, rn){
	maxN=0
	for(sn in names(l)){
		x=l[[sn]][which(l[[sn]][,1]==rn),]
		maxN=max(maxN, x[,3], -x[,4])
	}
	h=signif(maxN/4,1)
	for(sn in names(l)){
		x=l[[sn]][which(l[[sn]][,1]==rn),]
		par(mar=c(0,2,2,0.5))
		barplot(as.vector(x[,3]),col="#fcbba1",border="#fcbba1",xaxt="n",space=0,yaxt="n",ylim=c(0,maxN))
		barplot(as.vector(x[,5]),col="#a50f15",border="#a50f15",xaxt="n",space=0,yaxt="n",add=T)
		h=signif(maxN/4,1)
		axis(2,h*(0:4),label=h*(0:4))
		mtext(sn,3,font=2)
		par(mar=c(2,2,0,0.5))
		barplot(as.vector(x[,4]),col="#9ecae1",border="#9ecae1",xaxt="n",space=0,yaxt="n",ylim=c(-maxN,0))
		barplot(as.vector(x[,6]),col="#08519c",border="#08519c",xaxt="n",space=0,yaxt="n",add=T)
		axis(2,-h*(0:4),label=c("",-h*(1:4)))
		axis(1,c(1,floor(dim(x)[1]/4*(1:4)))-0.5,label=c(1,x[dim(x)[1]/4*(1:4),2]))
	}
}
fun_plot_scatter2=function(x, y, n1, n2, m){
	par(mar=c(4,4,4,2))
	lb=expression(10^0,10^1,10^2,10^3,10^4,10^5)
	cl=rep("black",length(x))
	cl[which((x+1)/(y+1)>2)]="#377eb8"
	cl[which((x+1)/(y+1)<1/2)]="#e41a1c"
	i1=log10(x+1); i2=log10(y+1)
	plot(-100,xlim=c(0,max(i1,i2)),ylim=c(0,max(i1,i2)),main=m,xaxt="n",yaxt="n",
	     xlab=paste(n1," + 1",sep=""),ylab=paste(n2," + 1",sep=""))
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

fun_plot_scatter2_for_pp=function(x, y, n1, n2){
	x=x[,9]; y=y[,9]
	x[x<(-1)]=(-1); y[y<(-1)]=(-1)
	par(mar=c(4,4,4,2))
	cl=rep("black",length(x))
	cl[which((x+2)/(y+2)>2)]="#377eb8"
	cl[which((x+2)/(y+2)<1/2)]="#e41a1c"
	i1=log2(x+2); i2=log2(y+2)
	plot(-100,xlim=c(0,min(max(i1,i2),9)),ylim=c(0,min(9,max(i1,i2))),xlab=n1,ylab=n2,xaxt="n",yaxt="n",main="ping-pong zscore")
	axis(1,0:10,label=c(2^(0:10)-2))
	axis(2,0:10,label=c(2^(0:10)-2))
	abline(0,1); abline(1,1,lty=2); abline(-1,1,lty=2)
	if(length(cl)<2000){
		points(i1,i2,pch=21,col="white",bg=cl)
	}else{
		points(i1,i2,pch=20,col=cl,cex=0.5)
	}
	if(length(imp_pi_dm3)==2){
		points(i1[imp_pi_dm3],i2[imp_pi_dm3],pch=1,cex=1.1)
		text(i1[imp_pi_dm3],i2[imp_pi_dm3],label=c("42AB","flam"),pos=1,font=2)
	}
	pv=signif(wilcox.test(i1,i2,paired=T)$p.value,2)
	text(0,max(i1,i2)*9/10,pos=4,label=paste("p-value = ",pv,sep=""),font=2)
}
fun_plot_scatter2_for_entropy=function(x, y, n1, n2){
	par(mar=c(4,4,4,2),bty="l")
	lb=expression(10^0,10^1,10^2,10^3,10^4,10^5)
	boxplot(log10(x[,1]+1),log10(y[,1]+1),log10(x[,2]+1),log10(y[,2]+1),at=c(1,2,4,5),staplewex=0,lty=1,
		col=c("#e41a1c","white","#377eb8","white"),border=c("black","#e41a1c","black","#377eb8"),
		ylab="RPM + 1",xaxt="n",main="uniqMappers",yaxt="n")
	axis(1,at=c(1.5,4.5),label=c("sense","antisense"),lwd=0)
	axis(2,0:5,label=lb)
	pv1=signif(wilcox.test(x[,1],y[,1],paired=T)$p.value,2)
	pv2=signif(wilcox.test(x[,2],y[,2],paired=T)$p.value,2)
	text(c(1.5,4.5),c(max(c(log10(x[,1]+1)),c(log10(y[,1]+1)))*8.5/10,
			  max(c(log10(x[,2]+1)),c(log10(y[,2]+1)))*8.5/10),label=c(pv1,pv2),srt=90)
	boxplot(log10(x[,3]+1),log10(y[,3]+1),log10(x[,4]+1),log10(y[,4]+1),at=c(1,2,4,5),staplewex=0,lty=1,
		col=c("#e41a1c","white","#377eb8","white"),border=c("black","#e41a1c","black","#377eb8"),
		ylab="log10 ( RPM + 1 )",xaxt="n",main="allMappers")
	axis(1,at=c(1.5,4.5),label=c("sense","antisense"),lwd=0)
	pv1=signif(wilcox.test(x[,3],y[,3],paired=T)$p.value,2)
	pv2=signif(wilcox.test(x[,4],y[,4],paired=T)$p.value,2)
	text(c(1.5,4.5),c(max(c(log10(x[,3]+1)),c(log10(y[,3]+1)))*8.5/10,
			  max(c(log10(x[,4]+1)),c(log10(y[,4]+1)))*8.5/10),label=c(pv1,pv2),srt=90)
	par(xpd=T)
	plot.new()
	legend("center",fill=c("black","white"),legend=c(n1,n2),y.intersp=1.5)
	par(xpd=F)
}

fun_plot_single_mode=function(i){
	ii=fun_sub(i)
	pdf(paste(pre,".",appendix,".temp.body.",ii,".pdf", sep=""), width=21, height=5*7/13, useDingbats=F)
	laymat=matrix(1,7,7)
	laymat[2:4,1]=2; laymat[5:7,1]=2
	laymat[2:4,2]=3; laymat[5:7,2]=4;
	laymat[2:4,3:4]=5; laymat[5:7,3:4]=6;
	for(k in 5:7){laymat[2:4,k]=k*2-3}
	for(k in 5:7){laymat[5:7,k]=k*2-2}
	layout(laymat)
	par(cex=0.5,tcl=0.3)
	par(mar=c(0,0,0,0),cex=1)
	plot.new()
	text(0,0.5,label=i,font=2,cex=1,pos=4)
	fun_plot_pp(pp[,i])
	fun_plot_lendis(all_reads_sense_lendis[,i],all_reads_anti_lendis[,i],"allMap reads")
	x=cov[which(cov[,1]==i),]
	fun_plot_bucket(x)
	fun_plot_lendis(uniq_reads_sense_lendis[,i],uniq_reads_anti_lendis[,i],"uniqMap reads")
	fun_plot_lendis(all_species_sense_lendis[,i],all_species_anti_lendis[,i],"allMap species")
	fun_plot_lendis(uniq_species_sense_lendis[,i],uniq_species_anti_lendis[,i],"uniqMap species")
	dev.off()
}

fun_plot_comparison_mode=function(name){
	ii=fun_sub(name)
	pdf(paste(pre,ln,".temp.body.",ii,".pdf", sep=""), width=21, height=5/13*(1+6*sample_num), useDingbats=F)
	laymat=matrix(1,1+6*sample_num,7)
	for(i in 1:sample_num){laymat[(6*i-4):(6*i+1),1]=i+1}
	for(i in 1:sample_num){
		laymat[(6*i-4):(6*i-2),2]=i*2-1+sample_num+1
		laymat[(6*i-1):(6*i+1),2]=i*2+sample_num+1
	}
	for(i in 1:sample_num){
		laymat[(6*i-4):(6*i-2),3:4]=i*2-1+3*sample_num+1
		laymat[(6*i-1):(6*i+1),3:4]=i*2+3*sample_num+1
	}
	for(i in 1:sample_num){
		laymat[(6*i-4):(6*i-2),5]=i*2-1+5*sample_num+1
		laymat[(6*i-1):(6*i+1),5]=i*2+5*sample_num+1
	}
	for(i in 1:sample_num){
		laymat[(6*i-4):(6*i-2),6]=i*2-1+7*sample_num+1
		laymat[(6*i-1):(6*i+1),6]=i*2+7*sample_num+1
	}
	for(i in 1:sample_num){
		laymat[(6*i-4):(6*i-2),7]=i*2-1+9*sample_num+1
		laymat[(6*i-1):(6*i+1),7]=i*2+9*sample_num+1
	}
	layout(laymat) # layout as laymat
	par(cex=0.5,tcl=0.3)
	par(mar=c(0,0,0,0),cex=1)
	plot.new()
	text(0,0.5,label=name,font=2,cex=1,pos=4)
	legend(0.35,0.9,legend=c("uniqReads","allReads"),fill=c("#a50f15","#fcbba1"),xpd=T,ncol=2,bty="n")
	fun_plot_pp2(pp, name)
	fun_plot_lendis2(all_reads_sense_lendis, all_reads_anti_lendis, name, "allMap reads")
	fun_plot_bucket2(cov, name)
	fun_plot_lendis2(uniq_reads_sense_lendis, uniq_reads_anti_lendis, name, "uniqMap reads")
	fun_plot_lendis2(all_species_sense_lendis, all_species_anti_lendis, name, "allMap species")
	fun_plot_lendis2(uniq_species_sense_lendis, uniq_species_anti_lendis, name, "uniqMap species")
	dev.off()
}

fun_sub=function(x){
	x=gsub("(",".",x,fixed=T)
	x=gsub(")",".",x,fixed=T)
	x=gsub("'",".",x,fixed=T)
	return(x)
}

# runs here----
system("echo0 2 \"....read files and pre-plot\"")
# comparison mode
pre=paste(Args[7]) # output prefix
#appendix=paste(strsplit(sn1,".",fixed=T)[[1]][(length(strsplit(sn1,".",fixed=T)[[1]])-1):length(strsplit(sn1,".",fixed=T)[[1]])],collapse=".")
#sn1=paste(strsplit(sn1,".",fixed=T)[[1]][1:(length(strsplit(sn1,".",fixed=T)[[1]])-2)],collapse=".")
#sn2=strsplit(Args[8],"/")[[1]][length(strsplit(Args[8],"/")[[1]])]
#sn2=paste(strsplit(sn2,".",fixed=T)[[1]][1:(length(strsplit(sn2,".",fixed=T)[[1]])-2)],collapse=".")
# read all files into lists
for(ln in c(".24-32nt.transposon", ".20-23nt.transposon", ".0-100nt.transposon", ".24-32nt.picluster", ".20-23nt.picluster", ".0-100nt.picluster")){
	uniq_reads_sense_lendis=list()
	uniq_reads_anti_lendis=list()
	uniq_species_sense_lendis=list()
	uniq_species_anti_lendis=list()
	all_reads_sense_lendis=list()
	all_reads_anti_lendis=list()
	all_species_sense_lendis=list()
	all_species_anti_lendis=list()
	pp=list() # ping-pong
	cov=list() # coverage across genes
	summary=list() # summary information
	for(i in 8:length(Args)){
		tsn = strsplit(Args[i],"/")[[1]][length(strsplit(Args[i],"/")[[1]])] # temp sample name
		uniq_reads_sense_lendis[[tsn]]=read.table(paste(Args[i],ln,".uniq.reads.sense.lendis",sep=""),header=T,row.names=1,check.names=F)
		uniq_reads_anti_lendis[[tsn]]=read.table(paste(Args[i],ln,".uniq.reads.antisense.lendis",sep=""),header=T,row.names=1,check.names=F)
		uniq_species_sense_lendis[[tsn]]=read.table(paste(Args[i],ln,".uniq.species.sense.lendis",sep=""),header=T,row.names=1,check.names=F)
		uniq_species_anti_lendis[[tsn]]=read.table(paste(Args[i],ln,".uniq.species.antisense.lendis",sep=""),header=T,row.names=1,check.names=F)
		all_reads_sense_lendis[[tsn]]=read.table(paste(Args[i],ln,".all.reads.sense.lendis",sep=""),header=T,row.names=1,check.names=F)
		all_reads_anti_lendis[[tsn]]=read.table(paste(Args[i],ln,".all.reads.antisense.lendis",sep=""),header=T,row.names=1,check.names=F)
		all_species_sense_lendis[[tsn]]=read.table(paste(Args[i],ln,".all.species.sense.lendis",sep=""),header=T,row.names=1,check.names=F)
		all_species_anti_lendis[[tsn]]=read.table(paste(Args[i],ln,".all.species.antisense.lendis",sep=""),header=T,row.names=1,check.names=F)
		pp[[tsn]]=read.table(paste(Args[i],ln,".pp",sep=""),header=T,row.names=1,check.names=F)
		cov[[tsn]]=read.table(paste(Args[i],ln,".cov",sep=""),header=F,row.names=NULL,check.names=F)
		summary[[tsn]]=read.table(paste(Args[i],ln,".summary",sep=""),header=T,row.names=1)
	}
	rn=row.names(summary[[1]])
	imp_pi_dm3=c(which(rn=="42AB"),which(rn=="flam"))
	# plot
	# add scatterplot for comparing all samples pair by pair
	pdf(paste(pre,ln,".scatter.pdf", sep=""), width=14, height=6, useDingbats=F)
	layout(matrix(c(1:9,9),2,5))
	par(tcl=0.3,bty="l")
	for(sn1 in names(summary)){
		for(sn2 in setdiff(names(summary), sn1)){
			if(length(grep("transposon",ln))>0){ # use antisense for TE
				fun_plot_scatter2(summary[[sn1]][,2],summary[[sn2]][,2],
					  	sn1,sn2,"uniqMap reads")
				fun_plot_scatter2(summary[[sn1]][,4],summary[[sn2]][,4],
					  	sn1,sn2,"allMap reads")
				fun_plot_scatter2(summary[[sn1]][,6],summary[[sn2]][,6],
					  	sn1,sn2,"uniqMap species")
				fun_plot_scatter2(summary[[sn1]][,8],summary[[sn2]][,8],
					  	sn1,sn2,"allMap species")
			}else{ # use both strand for picluster
				fun_plot_scatter2(summary[[sn1]][,1]+summary[[sn1]][,2],summary[[sn2]][,1]+summary[[sn2]][,2],
					  	sn1,sn2,"uniqMap reads")
				fun_plot_scatter2(summary[[sn1]][,3]+summary[[sn1]][,4],summary[[sn2]][,3]+summary[[sn2]][,4],
					  	sn1,sn2,"allMap reads")
				fun_plot_scatter2(summary[[sn1]][,5]+summary[[sn1]][,6],summary[[sn2]][,5]+summary[[sn2]][,6],
					  	sn1,sn2,"uniqMap species")
				fun_plot_scatter2(summary[[sn1]][,7]+summary[[sn1]][,8],summary[[sn2]][,7]+summary[[sn2]][,8],
					  	sn1,sn2,"allMap species")
			}
			fun_plot_scatter2(summary[[sn1]][,10],summary[[sn2]][,10],
				  	sn1,sn2,"10nt overlap")
			fun_plot_scatter2_for_pp(summary[[sn1]],summary[[sn2]],sn1,sn2)
			fun_plot_scatter2_for_entropy(summary[[sn1]],summary[[sn2]],sn1,sn2)
		}
	}
	dev.off()
	# bucket plot for all samples
	sample_num = length(summary)
	pdf(paste(pre,ln,".temp.head.pdf", sep=""), width=21, height=5/13*(1+6*sample_num), useDingbats=F)
	laymat=matrix(1,1+6*sample_num,7)
	for(i in 1:sample_num){laymat[(6*i-4):(6*i+1),1]=i+1}
	for(i in 1:sample_num){
		laymat[(6*i-4):(6*i-2),2]=i*2-1+sample_num+1
		laymat[(6*i-1):(6*i+1),2]=i*2+sample_num+1
	}
	for(i in 1:sample_num){
		laymat[(6*i-4):(6*i-2),3:4]=i*2-1+3*sample_num+1
		laymat[(6*i-1):(6*i+1),3:4]=i*2+3*sample_num+1
	}
	for(i in 1:sample_num){
		laymat[(6*i-4):(6*i-2),5]=i*2-1+5*sample_num+1
		laymat[(6*i-1):(6*i+1),5]=i*2+5*sample_num+1
	}
	for(i in 1:sample_num){
		laymat[(6*i-4):(6*i-2),6]=i*2-1+7*sample_num+1
		laymat[(6*i-1):(6*i+1),6]=i*2+7*sample_num+1
	}
	for(i in 1:sample_num){
		laymat[(6*i-4):(6*i-2),7]=i*2-1+9*sample_num+1
		laymat[(6*i-1):(6*i+1),7]=i*2+9*sample_num+1
	}
	layout(laymat) # layout as laymat
	# plot overall summary first
	par(cex=0.5,tcl=0.3,xpd=F)
	par(mar=c(0,0,0,0),cex=1)
	plot.new() # plot samples names in the first column
	text(0,0.5,label="overall summary",font=2,cex=1,pos=4)
	fun_plot_pp2(pp, 0)
	fun_plot_lendis2(all_reads_sense_lendis, all_reads_anti_lendis, 0, "allMap reads")
	for(i in 1:(2*sample_num)){
		plot.new()
		if(i%%2==1){
			mtext(names(cov)[ceiling(i/2)],3,font=2)
		}
	}
	fun_plot_lendis2(uniq_reads_sense_lendis, uniq_reads_anti_lendis, 0, "uniqMap reads")
	fun_plot_lendis2(all_species_sense_lendis, all_species_anti_lendis, 0, "allMap species")
	fun_plot_lendis2(uniq_species_sense_lendis, uniq_species_anti_lendis, 0, "uniqMap species")
	dev.off()
	# plot buckets for each genes parallely
	fun_plot_comparison_mode(rn[1])
	cl=makeCluster(as.numeric(Args[6]))
	clusterExport(cl=cl,varlist=c("uniq_reads_sense_lendis","uniq_reads_anti_lendis","uniq_species_sense_lendis","uniq_species_anti_lendis","all_reads_sense_lendis","all_reads_anti_lendis","all_species_sense_lendis","all_species_anti_lendis","pp","cov","summary","fun_plot_pp2","fun_plot_lendis2","fun_plot_bucket2","pre","Args","fun_sub","sample_num","ln"),envir=environment())
	system("echo0 2 \"....plot buckets for each element\"")
	parLapply(cl,rn,fun_plot_comparison_mode)
	# merge pdfs
	system("echo0 2 \"....merge pdfs\"")
	if(length(rn)>500){
		fun_merge=function(in_pdfs){
			command=paste("gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite -dNumRenderingThreads=",Args[6]," -sOutputFile=",in_pdfs,sep="")
			write.table(command,"ss",row.names=F,col.names=F,sep="\t",quote=F)
			system(command)
		}
		system(paste("mkdir ",pre,ln,".pdf",sep=""))
		trn=sort(rn)
		l_in_pdfs=c()
		for(i in 1:ceiling(length(trn)/500)){
			tlist=trn[((i-1)*500+1):min(i*500,length(trn))]
			in_pdfs=paste(pre,ln,".pdf/",trn[((i-1)*500+1)],"---",trn[min(i*500,length(trn))],".pdf ",pre,ln,".temp.head.pdf",sep="")
			for(i in tlist){
				in_pdfs=paste(in_pdfs," ",pre,ln,".temp.body.",i,".pdf",sep="")
			}
			in_pdfs=fun_sub(in_pdfs)
			l_in_pdfs=c(l_in_pdfs,in_pdfs)
		}
		parLapply(cl,l_in_pdfs,fun_merge)
		system(paste("rm ",pre,ln,".temp.*.pdf",sep=""))
	}else{
		system(paste("gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite -dNumRenderingThreads=",Args[6]," -sOutputFile=",pre,ln,".pdf ",pre,ln,".temp.head.pdf ",pre,ln,".temp.body.*.pdf && rm ",pre,ln,".temp.*.pdf",sep=""))
	}
}

stopCluster(cl)
