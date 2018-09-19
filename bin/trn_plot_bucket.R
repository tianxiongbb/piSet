#!/usr/bin/env Rscript

### arguments ----
Args=commandArgs()
if(length(Args)<6){
	stop(paste("usage:\n", substr(Args[4],8,100), "in.bucket", "in.size out.pdf [if_overall]\nin.bucket file shall have two signal column for tru reads and all reads", sep=" "))
}

### library packages ----

### main program ----
# read data
df_bucket = read.table(Args[6], header=F, row.names=NULL)
df_size = read.table(Args[7], header=F, row.names=1)

# open pdf
pdf(Args[8], height=4, width=8, useDingbats=F)
par(mar=c(4,4,4,2), tcl=0.3, bty="l")
# plot buckets
if(length(Args)==9){
	x1 = rep(0, length(df_bucket[df_bucket[,1]==row.names(df_size)[1], 3]))
	x2 = x1
	for(n in row.names(df_size)){
		x1 = x1 + df_bucket[df_bucket[,1]==n, 3]
		x2 = x2 + df_bucket[df_bucket[,1]==n, 4]
	}
	barplot(x1, space=0, col="#d0d1e6", border="#d0d1e6", xaxt="n", xlab="", ylab="",main="overall")
	barplot(x2, space=0, col="#045a8d", border="#045a8d", xaxt="n", xlab="", ylab="", add=T, yaxt="n")
	axis(1, c(0.5,length(x1)-0.5), label=c("start","end"))
}
for(n in row.names(df_size)){
	x1 = df_bucket[df_bucket[,1]==n, 3]
	x2 = df_bucket[df_bucket[,1]==n, 4]
	barplot(x1, space=0, col="#d0d1e6", border="#d0d1e6", xaxt="n", xlab="", ylab="",main=n)
	barplot(x2, space=0, col="#045a8d", border="#045a8d", xaxt="n", xlab="", ylab="", add=T, yaxt="n")
	axis(1, seq(1,length(x1),length.out=6)-0.5, pos=-max(x1)/10,
	     label=floor(seq(1,df_size[n,1],length.out=6)))
}
dev.off()
