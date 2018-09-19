#!/usr/bin/env Rscript

### arguments ----
Args=commandArgs()
if(length(Args)<8){
	stop(paste("usage:\n", substr(Args[4],8,100), "te.size/picluster.size", "out.pdf", "watson.bdg|noStrand.bdg", "[crick.bdg]", sep=" "))
}

### library packages ----

### functions ----
fun_add_bar1 = function(x, cs){
	polygon(c(x[2],x[2],x[3],x[3]), c(0,x[4],x[4],0), border=F, col="#e41a1c")
}
fun_add_bar2 = function(x, cs){
	polygon(c(x[2],x[2],x[3],x[3]), c(0,-as.numeric(x[4]),-as.numeric(x[4]),0), border=F, col="#377eb8")
}

### main program ----
# read size
df_size = read.table(Args[6], header=F, row.names=1)

# plot buckets
pdf(Args[7], width=6, height=4, useDingbats=F)
par(bty="n",mar=c(3,3,4,1),tcl=0.3)
if(length(Args)==8){ # non-strand-specific mode
	bdg = read.table(Args[8], header=F, row.names=NULL)
	for(te in row.names(df_size)){
		x = bdg[bdg[,1]==te,]
		if(dim(x)[1]>0){ma=max(x[,4])}else{ma=0}
		plot(NA, xlim=c(0,df_size[te,1]), ylim=c(0,ma), xlab="", ylab="", main=te, xaxt="n")
		axis(1,c(0,df_size[te,1]),label=c(0,df_size[te,1]))
		apply(x, 1, fun_add_bar1)
	}
}else{ # strand-specific mode
	bdg_s = read.table(Args[8], header=F, row.names=NULL)
	bdg_a = read.table(Args[9], header=F, row.names=NULL)
	for(te in row.names(df_size)){
		x1 = bdg_s[bdg_s[,1]==te,]
		x2 = bdg_a[bdg_a[,1]==te,]
		if(dim(x1)[1]>0){ma1=max(x1[,4])}else{ma1=0}
		if(dim(x2)[1]>0){ma2=max(x2[,4])}else{ma2=0}
		ma = max(ma1, ma2)
		plot(NA, xlim=c(0,df_size[te,1]), ylim=c(-ma,ma), xlab="", ylab="", main=te, xaxt="n")
		axis(1,c(0,df_size[te,1]),label=c(0,df_size[te,1]))
		apply(x1, 1, fun_add_bar1)
		apply(x2, 1, fun_add_bar2)
	}
}
dev.off()
