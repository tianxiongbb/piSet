#!/usr/bin/env Rscript
library(pheatmap)
Args=commandArgs()

# help----
if(length(Args)<9){
	stop(paste("usage:\n\t",substr(Args[4],8,100)," sample_information.tab out.prefix in.prefix1 [in.prefix2] [in.prefix3] [...]\n",sep=""))
}

# read tables
df_rpkm=list()
for(i in Args[8:length(Args)]){
	sn=strsplit(i,".rpkm")[[1]][1]
	sn=strsplit(sn,"/")[[1]][length(strsplit(sn,"/")[[1]])]
	if(i==Args[8]){
		df_rpkm=read.table(i,header=F,row.names=1,check.names=F)
		colnames(df_rpkm)=sn
	}else{
		df_rpkm[,sn]=read.table(i,header=F,row.names=1,check.names=F)[,1]
	}
}
sample_info=read.table(Args[6],header=F,row.names=1)
conditions=levels(sample_info[,1])
cols=rainbow(length(conditions))
sample_info$cs=cols[1]
for(i in 1:length(conditions)){
	sample_info[which(sample_info[,1]==conditions[i]),2]=cols[i]
}

# pca analysis
pdf(paste(Args[7],".pca.pdf",sep=""),width=10,height=5)
par(mar=c(4,4,2,2),mfrow=c(1,2))
pca=princomp(df_rpkm)
plot(pca$loadings[,1],pca$loadings[,2],bg=sample_info[row.names(pca$loadings),2],
     pch=21,col="white",xlab="PC1",ylab="PC2")
text(pca$loadings[,1],pca$loadings[,2],label=row.names(pca$loadings),cex=0.8,pos=4)
barplot(pca$sdev,las=3)
dev.off()

# coorelation analysis
tm1=cor(df_rpkm,method="spearman")
tm2=cor(df_rpkm,method="pearson")
pheatmap(tm1,filename=paste(Args[7],".cor.spearman.pdf",sep=""))
pheatmap(tm2,filename=paste(Args[7],".cor.spearman.pdf",sep=""))

# one-to-one scatterplot
pdf(paste(Args[7],".scatter.pdf",sep=""),width=5,height=5)
par(mar=c(4,4,4,2),tcl=0.3,bty="l")
for(i in colnames(df_rpkm)){
	for(j in colnames(df_rpkm)){
		if(i!=j){
			plot(log10(df_rpkm[,i]+0.1),log10(df_rpkm[,j]+0.1),
			     col=densCols(df_rpkm[,i],df_rpkm[,j],colorRampPalette(blues9[-(1:9)])),
			     abline(0,1),xlab=i,ylab=j,main="log10(RPKM+0.1)")
		}
	}
}
dev.off()





