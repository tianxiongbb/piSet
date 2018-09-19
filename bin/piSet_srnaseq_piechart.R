#!/usr/bin/env Rscript

### arguments ----
Args=commandArgs()
if(length(Args)<6){
	stop(paste("usage:\n", substr(Args[4],8,100), "in.statistics", "out.pdf", sep=" "))
}

### library packages ----

### main program ----
# read data
df_pie = read.table(Args[6], header=T, row.names=1)

# open pdf and plot piechart
pdf(Args[7], height=5, width=5, useDingbats=F)
par(mar=c(2,2,2,2),cex=5/6)
df_pie2=rowSums(df_pie)
rds=0.55
tl=as.vector(c(df_pie2[1:3],sum(df_pie2[4:12]),df_pie2[13]))
pie(tl,
    labels=paste(c("rRNA","miRNA","sncRNA","genome","unaligned")," ",round(tl/sum(tl),3)*100,"%",sep=""),
    col=c("#b3de69","#8dd3c7","#fdb462","#fb8072","#d9d9d9"),
    border="white",main="all smallRNA reads",radius=rds)
tl=rowSums(df_pie[4:12,])
pie(tl,
    labels=paste(row.names(df_pie)[4:12]," ",round(tl/sum(tl),3)*100,"%",sep=""),
    col=c("#80b1d3","#FC8D62","#66C2A5","#8DA0CB","#E78AC3","#A6D854","#FFD92F","#E5C494","#B3B3B3",""),
    border="#fb8072",main="genome mapping reads",radius=rds)
tl=colSums(df_pie[4:12,])
pie(tl,
    labels=paste(c("piRNA","siRNA","otherRNA")," ",round(tl/sum(tl),3)*100,"%",sep=""),
    col=c("#e41a1c","#377eb8","#999999"),
    border="#fb8072",main="genome mapping reads",radius=rds)
tl=df_pie[4:12,1]
pie(tl,
    labels=paste(row.names(df_pie)[4:12]," ",round(tl/sum(tl),3)*100,"%",sep=""),
    col=c("#80b1d3","#FC8D62","#66C2A5","#8DA0CB","#E78AC3","#A6D854","#FFD92F","#E5C494","#B3B3B3",""),
    border="#e41a1c",main="genome mapping piRNA reads",radius=rds)
tl=df_pie[4:12,2]
pie(tl,
    labels=paste(row.names(df_pie)[4:12]," ",round(tl/sum(tl),3)*100,"%",sep=""),
    col=c("#80b1d3","#FC8D62","#66C2A5","#8DA0CB","#E78AC3","#A6D854","#FFD92F","#E5C494","#B3B3B3",""),
    border="#377eb8",main="genome mapping siRNA reads",radius=rds)
tl=df_pie[4:12,3]
pie(tl,
    labels=paste(row.names(df_pie)[4:12]," ",round(tl/sum(tl),3)*100,"%",sep=""),
    col=c("#80b1d3","#FC8D62","#66C2A5","#8DA0CB","#E78AC3","#A6D854","#FFD92F","#E5C494","#B3B3B3",""),
    border="#999999",main="genome mapping otherRNA reads",radius=rds)
dev.off()
