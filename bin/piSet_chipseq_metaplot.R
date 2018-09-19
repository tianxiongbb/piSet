#!/usr/bin/env Rscript

### arguments ----
Args=commandArgs()
if(length(Args)<6){
	stop(paste(substr(Args[4],8,100),"prefix group.list out.pdf",sep=" "))
}

### library packages ----
library(RColorBrewer)

### functions ----

### main program ----
mat_p = read.table(paste(Args[6],".t5.u5000.d5000.b200.mat",sep=""), header=F, row.names=1) # signal matrix around promoter
mat_gb = read.table(paste(Args[6],".t53.u5000.d5000.b400.mat",sep=""), header=F, row.names=1) # signal matrix around whole gene body
mat_gb[is.na(mat_gb)]=0
group = read.table(Args[7], header=F, row.names=1) # group information
list_group = list()
for(i in row.names(group)){
	gl=strsplit(as.character(group[i,1]), ",")[[1]]
	for(j in gl){
		list_group[[j]] = c(list_group[[j]], i)
	}
}
list_av_sig_p = list()
list_av_sig_gb = list()
ym_p=0;ym_gb=0
for(i in names(list_group)){
	list_av_sig_p[[i]] = apply(mat_p[list_group[[i]],], 2, mean)
	ym_p = max(ym_p, max(list_av_sig_p[[i]]))
	list_av_sig_gb[[i]] = apply(mat_gb[list_group[[i]],], 2, mean)
	ym_gb = max(ym_gb, max(list_av_sig_gb[[i]]))
	print(ym_gb)
}

pdf(Args[8], width=9, height=4.5)
cs=c(brewer.pal(9,"Set1"),brewer.pal(8,"Set2"));ci=1
laymat=matrix(1,4,8);laymat[2:4,1:5]=2;laymat[2:4,6:8]=3;layout(laymat)
par(mar=c(0,0,0,0), tcl=0.3, cex=5/6)
plot.new();text(0.5,0.9,label=Args[6],font=2)
legend("bottom", legend=names(list_group), col=cs[1:length(list_group)], lwd=2,
       bty="n", ncol=4)
last2_pre = substr(Args[6],nchar(Args[6])-1,nchar(Args[6]))
if(last2_pre == "FE"){yl="fold enrichment"}else{yl="tags per million reads"}
par(mar=c(2.5,4,1,1))
plot(NA, xlim=c(1,400), ylim=c(0,ym_gb), xlab="", ylab=yl, xaxt="n")
axis(1, c(1,100,300,400), label=c("-5kb","TSS","TES","+5kb"))
for(i in names(list_group)){
	lines(list_av_sig_gb[[i]], lwd=2, col=cs[ci]);ci=ci+1
}
plot(NA, xlim=c(1,200), ylim=c(0,ym_p), xlab="", ylab=yl, xaxt="n")
axis(1, c(1,100,200), label=c("-5kb","TSS","+5kb"))
ci=1
for(i in names(list_group)){
	lines(list_av_sig_p[[i]], lwd=2, col=cs[ci]);ci=ci+1
}
dev.off()
