#!/usr/bin/env Rscript

### arguments ----
Args=commandArgs()
if(length(Args)<6){
	stop(paste(substr(Args[4],8,100),"in.phasing","out.pdf",sep=" "))
}

### library packages ----

### functions ----
zscore_phasing=function(l){
  x_c=l[-12];x_t=l[12]
  return((x_t-mean(x_c))/sd(x_c))
}

### main program ----
df_phase=read.table(Args[6],header=F,row.names=1)
pdf(Args[7],width=4,height=2,useDingbats=F)
par(mar=c(4,4,1,1),tcl=0.3,bty="n",cex=5/6)
plot(df_phase[,2],type="l",ylab="normalized piRNA pairs",xaxt="n",xlab="5' to 3' distance")
axis(1,c(1,12,62),label=c(-10,1,50),lwd=0)
abline(v=12,lty=2)
zs=round(zscore_phasing(df_phase[,2]),2)
m=max(df_phase[,2]);text(12,m*19/20,label=paste("zscore=",zs,sep=""),pos=4)
dev.off()
