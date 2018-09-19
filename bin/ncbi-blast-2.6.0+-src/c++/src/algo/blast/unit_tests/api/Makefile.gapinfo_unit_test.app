# $Id: Makefile.gapinfo_unit_test.app 505858 2016-06-29 16:55:21Z elisovdn $

APP = gapinfo_unit_test
SRC = gapinfo_unit_test 

CPPFLAGS = -DNCBI_MODULE=BLAST $(ORIG_CPPFLAGS) $(BOOST_INCLUDE)
LIB = test_boost $(BLAST_LIBS) xncbi

CHECK_REQUIRES = MT in-house-resources
CHECK_CMD = gapinfo_unit_test
CHECK_COPY = gapinfo_unit_test.ini

WATCHERS = boratyng madden camacho fongah2
