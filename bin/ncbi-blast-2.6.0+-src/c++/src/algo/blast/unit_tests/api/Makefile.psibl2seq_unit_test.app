# $Id: Makefile.psibl2seq_unit_test.app 505858 2016-06-29 16:55:21Z elisovdn $

APP = psibl2seq_unit_test
SRC = psibl2seq_unit_test 

CPPFLAGS = -DNCBI_MODULE=BLAST $(ORIG_CPPFLAGS) $(BOOST_INCLUDE) -I$(srcdir)/../../api
LIB = test_boost $(BLAST_LIBS) xobjsimple $(OBJMGR_LIBS:ncbi_x%=ncbi_x%$(DLL))
LIBS = $(NETWORK_LIBS) $(CMPRS_LIBS) $(DL_LIBS) $(ORIG_LIBS)

CHECK_REQUIRES = MT in-house-resources
CHECK_CMD = psibl2seq_unit_test
CHECK_COPY = psibl2seq_unit_test.ini data

WATCHERS = boratyng madden camacho
