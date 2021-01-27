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
pdf(Args[7],width=5,height=2,useDingbats=F)
par(mar=c(4,4,1,1),tcl=0.3,bty="n",cex=5/6)
plot(lowess(df_phase[,2],f=0.1),type="l",ylab="normalized piRNA pairs",xaxt="n",xlab="5' to 3' distance")
axis(1,c((1:10)*20-19),label=c((1:10)*20),lwd=0,cex.axis=0.6)
dev.off()
