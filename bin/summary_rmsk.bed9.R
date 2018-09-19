#!/usr/bin/env Rscript

### arguments ----
Args=commandArgs()
if(length(Args)<6){
	stop(paste("usage:\n", substr(Args[4],8,100), "prefix", "\nplot transposon summary to prefix.pdf via prefix.family.summ, prefix.subfamily and prefix.divergence.summ", sep=" "))
}

### library packages ----

### functions ----
plot_fml = function(df, cl, m){
	par(mar=c(4,4,3,3), tcl=0.3, cex=1)
	lb = expression(10^0,10^1,10^2,10^3,10^4,10^5,10^6,10^7,10^8,10^9)
	xl = ceiling(max(log10(df[,1])))
	yl = ceiling(max(df[,3]))
	plot(log10(df[,1]), df[,3], bg=cl, pch=21, lwd=1,
	     xlim=c(0,xl), ylim=c(0,yl), xaxt="n", ylab="divergence",
	     xlab="total length (bp)")
	axis(1, 0:9, label=lb)
	mtext(m,3,font=2,cex=1.2,padj=-0.2)
}

plot_legend = function(lgm){
	par(mar=c(0,0,0,0), cex=5/6)
	plot.new()
	nc = ceiling(dim(lgm)[1]/30)
	legend("center", legend=row.names(lgm), fill=lgm[,1], ncol=nc)
}



### main program ----
# read data
faml = read.table(paste(Args[6], ".family.summ", sep=""), header=F, row.names=1, check.names=F, sep="\t")
sfaml = read.table(paste(Args[6], ".subfamily.summ", sep=""), header=F, row.names=1, check.names=F, sep="\t")
divg = read.table(paste(Args[6], ".divergence.summ", sep=""), header=F, row.names=1, check.names=F, sep="\t")
# open pdf
pdf(paste(Args[6], ".pdf", sep=""), height=9, width=12, useDingbats=F)
laymat=matrix(1,9,12)
laymat[1:4,5:8]=2; laymat[5:9,9:12]=3; laymat[5:9,1:8]=4; laymat[1:4,9:12]=5
layout(laymat)
# annotate colors
line = row.names(faml)[which(faml[,4]=="LINE" | faml[,4]=="LINE?")]
sine = row.names(faml)[which(faml[,4]=="SINE" | faml[,4]=="SINE?")]
ltr = row.names(faml)[which(faml[,4]=="LTR" | faml[,4]=="LTR?")]
dna = row.names(faml)[which(faml[,4]=="DNA" | faml[,4]=="DNA?")]
od_line = order(faml[line,1], decreasing=T)
tl=length(od_line);od_line1=c()
for(i in 1:ceiling(tl/2)){if(i<=floor(tl/2)){od_line1=c(od_line1,od_line[i],od_line[tl-i+1])}else{od_line1=c(od_line1,od_line[i])}}
if(tl==0){od_line1=c()}
od_sine = order(faml[sine,1], decreasing=T)
tl=length(od_sine);od_sine1=c()
for(i in 1:ceiling(tl/2)){if(i<=floor(tl/2)){od_sine1=c(od_sine1,od_sine[i],od_sine[tl-i+1])}else{od_sine1=c(od_sine1,od_sine[i])}}
if(tl==0){od_sine1=c()}
od_ltr = order(faml[ltr,1], decreasing=T)
tl=length(od_ltr);od_ltr1=c()
for(i in 1:ceiling(tl/2)){if(i<=floor(tl/2)){od_ltr1=c(od_ltr1,od_ltr[i],od_ltr[tl-i+1])}else{od_ltr1=c(od_ltr1,od_ltr[i])}}
if(tl==0){od_ltr1=c()}
od_dna = order(faml[dna,1], decreasing=T)
tl=length(od_dna);od_dna1=c()
for(i in 1:ceiling(tl/2)){if(i<=floor(tl/2)){od_dna1=c(od_dna1,od_dna[i],od_dna[tl-i+1])}else{od_dna1=c(od_dna1,od_dna[i])}}
if(tl==0){od_dna1=c()}
cs_line = colorRampPalette(c("#00008B","#ACD8E5"))(length(line))
cs_sine = colorRampPalette(c("#A637F1","#D7B4F8"))(length(sine))
cs_ltr = colorRampPalette(c("#489E42","#90ED90"))(length(ltr))
cs_dna = colorRampPalette(c("#FF4825","#FF936C"))(length(dna))
faml = faml[c(dna[od_dna1],ltr[od_ltr1],line[od_line1],sine[od_sine1]),]
lgm = matrix(0, dim(faml)[1], 1); row.names(lgm) = row.names(faml)
lgm[,1] = c(cs_dna,cs_ltr,cs_line,cs_sine)
# plot faml
plot_fml(faml, as.vector(lgm[,1]), "transposon family")
# plot sfaml
cl2 = lgm[as.vector(sfaml[,5]),1]
plot_fml(sfaml, as.vector(cl2), "transposon")
# plot legend
plot_legend(lgm)
# plot divergence
par(mar=c(4,4,3,2), cex=1, lwd=0.3)
x=as.matrix(divg[c(dna[od_dna1],ltr[od_ltr1],line[od_line1],sine[od_sine1]),2:41])
barplot(x, col=as.vector(lgm[,1]), border="white", lwd=0.7, xaxt="n",
	space=0.5, ylab="percentage of genome", xlab="divergence")
axis(1, c(1,6,11,16,21,26,31,36,41)*1.5-0.5, label=0:8*5, lwd=0)
mtext("lanscape",3,font=2,cex=1.2,padj=-0.2)
# plot piechart for all families
tlist=apply(divg[c(dna[od_dna1],ltr[od_ltr1],line[od_line1],sine[od_sine1]),2:41],1,sum)
tlist=c(tlist,100-sum(tlist))
par(lwd=0.5,mar=c(0,0,0,0))
lb=paste(round(c(tlist,100-sum(tlist)),2),"%",sep="")
lb[tlist<1]=""
pie(tlist,col=c(as.vector(lgm[,1]),"black"),radius=0.8,
    labels=lb,border="white",cex=0.6)

# close pdf
dev.off()





