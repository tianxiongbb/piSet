#!/usr/bin/env Rscript

### arguments ----
Args=commandArgs()
if(length(Args)<6){
	stop(paste(substr(Args[4],8,100),"in.mat group.list",sep=" "))
}

### library packages ----

### functions ----

### main program ----
mat = read.table(Args[6], header=F, row.names=1)
group = read.table(Args[7], header=F, row.names=1)
list_group = list()
for(i in row.names(group)){
	gl=strsplit(group[i,1], ",")
	for(j in gl){
		list_group[[j]] = c(list_group[[j]], i)
	}
}

