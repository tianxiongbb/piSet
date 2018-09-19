ncbi_strings.o ncbi_strings.d : \
 $(wildcard /data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++/src/corelib/ncbi_strings.c) \
 $(wildcard /usr/include/stdc-predef.h) \
 $(wildcard $(includedir)/corelib/ncbi_strings.h) \
 $(wildcard $(includedir)/common/ncbi_export.h) \
 $(wildcard $(includedir)/ncbiconf.h) \
 $(wildcard $(incdir)/ncbiconf_unix.h) \
 $(wildcard $(includedir)/common/ncbiconf_impl.h) \
 $(wildcard $(includedir)/common/ncbi_skew_guard.h)
