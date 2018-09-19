# $Id: Makefile.dustmasker.app 500573 2016-05-05 16:42:41Z gouriano $

REQUIRES = objects algo

ASN_DEP = seq

APP = dustmasker
SRC = main dust_mask_app

LIB = xalgodustmask seqmasks_io $(OBJREAD_LIBS) xobjutil \
      seqdb blastdb $(OBJMGR_LIBS:%=%$(STATIC))

LIBS = $(CMPRS_LIBS) $(NETWORK_LIBS) $(DL_LIBS) $(ORIG_LIBS)

CXXFLAGS = $(FAST_CXXFLAGS)
LDFLAGS  = $(FAST_LDFLAGS)


WATCHERS = camacho
