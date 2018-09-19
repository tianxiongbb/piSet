# $Id: Makefile.in 371962 2012-08-14 09:45:56Z coulouri $

# Meta-makefile("APP" project)
#################################

REQUIRES = objects algo

APP_PROJ = rmblastn

srcdir = /data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++/src/app/rmblastn
include /data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++/ReleaseMT/build/Makefile.meta

.PHONY: all $(APP_PROJ)

rmblastn:
	${MAKE} ${MFLAGS} -f Makefile.rmblastn_app
