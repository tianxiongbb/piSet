
all : nseg nmerge

nseg : nseg.c lnfac.h genwin.h genwin.o
	cc -g -o nseg nseg.c genwin.o -lm

nmerge : nmerge.c genwin.h genwin.o
	cc -g -o nmerge nmerge.c genwin.o -lm

genwin.o : genwin.c genwin.h
	cc -g -c genwin.c

clean:
	rm -f nseg nseg.o genwin.o
