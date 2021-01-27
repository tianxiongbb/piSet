#!/usr/bin/env Rscript

# install and library packages for vennplot
if(!"VennDiagram" %in% rownames(installed.packages())){
	install.packages("VennDiagram")
}
library(VennDiagram)

Args=commandArgs()

files = list.files(Args[6], pattern=paste(Args[7],".tlist*",sep=""))
list_peak = list()

setwd(Args[6])
for(f in files){
	tv = as.vector(read.table(f, header=F, row.names=NULL)[,1])
	tn = strsplit(f, ".tlist.")[[1]][2]
	list_peak[[tn]] = tv
}

csl=c("#E41A1C","#377EB8","#4DAF4A","#984EA3","#FF7F00")
t=venn.diagram(list_peak,filename=NULL,fill=csl[1:length(list_peak)],main="TE insertion in all samples",margin=0.15,cex=5/6)
pdf(paste(Args[7],".venn.pdf",sep=""),width=5,height=5,useDingbats=F)
grid.draw(t)
dev.off()
