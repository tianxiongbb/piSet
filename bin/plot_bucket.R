#!/usr/bin/env Rscript

### arguments ----
Args=commandArgs()
if(length(Args)<6){
	stop(paste("usage:\n", substr(Args[4],8,100), "in.bucket", "in.size out.pdf [if_overall]\nin.bucket file shall have 3 columns, in which 1st column is gene name, 2nd column is gene location and 3rd column is signal\nin.size file shall have 2 columns, in which 1st column is gene name and 2nd column is gene size\nset if_overall to any value to add overall bucket, please make sure the bucket file is in fixed size of each elements", sep=" "))
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
	for(n in row.names(df_size)){
		x1 = x1 + df_bucket[df_bucket[,1]==n, 3]
	}
	barplot(x1, space=0, col="#3288bd", border="#3288bd", xaxt="n", xlab="", ylab="",main="overall")
	axis(1, c(0.5,length(x1)-0.5), label=c("start","end"))
}
for(n in row.names(df_size)){
	x = df_bucket[df_bucket[,1]==n, 3]
	barplot(x, space=0, col="#3288bd", border="#3288bd", xaxt="n", xlab="", ylab="",main=n)
	axis(1, seq(1,length(x),length.out=6)-0.5, pos=-max(x)/10,
	     label=floor(seq(1,df_size[n,1],length.out=6)))
}
dev.off()
