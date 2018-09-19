#################################
# $Id: Makefile.mk.in 512372 2016-08-30 14:51:36Z ivanov $
# Author:  Denis Vakatov (vakatov@ncbi.nlm.nih.gov)
#################################
#
# This template must be "configure"d and included in the very beginning
# of all underlying configurable NCBI project makefiles exactly this way:
#
# srcdir = /data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++/src/build-system
# include /data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++/ReleaseMT/build/Makefile.mk
#
#################################


### Make sure to use a right command shell

SHELL=/bin/bash

### Configurable paths

top_srcdir     = /data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++
abs_top_srcdir = /data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++
build_root     = /data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++/ReleaseMT
builddir       = /data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++/ReleaseMT/build
status_dir     = /data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++/ReleaseMT/status


### Other paths
### includedir0 is reserved; user makefiles should only use includedir.

includedir0 = $(top_srcdir)/include
includedir  = $(includedir0)
incdir      = $(build_root)/inc
libdir      = $(build_root)/lib
bindir      = $(build_root)/bin
runpath     = -Wl,-rpath,/home/yutianx/bin/lib -Wl,-rpath-link,$(libdir)

# Destination root for exported headers (overridden by import_project.sh)
incdest     = $(incdir)

### Optional top-level project groups

OPT_GROUPS = 


### Header dirs to include

STD_INCLUDE = -I$(incdir) -I$(includedir0) $(OPT_GROUPS:%=-I$(includedir0)/%)


### Auxiliary commands, filters

RM       = /bin/rm -f
RMDIR    = /bin/rm -rf
COPY     = /bin/cp -p
BINCOPY  = /bin/bash $(top_srcdir)/scripts/common/impl/if_diff.sh "/bin/ln -f"
TOUCH    = /bin/touch
MKDIR    = /bin/mkdir
BINTOUCH = $(TOUCH)
LN_S     = /bin/ln -s
GREP     = /bin/grep
LDD_R    = /usr/bin/ldd -r
SED      = /bin/sed

### filters for screening out bogus messages
CC_FILTER    = 
CXX_FILTER   = 
AR_FILTER    = 
LINK_FILTER  = 

### wrappers (ccache, purify, etc.)
CC_WRAPPER   = /usr/bin/ccache
CXX_WRAPPER  = /usr/bin/ccache
AR_WRAPPER   = 
LINK_WRAPPER = 

CHECK_ARG = 


### Configurable compiler/librarian/linker binaries and options
### (CONF-Set:  not to be alternated or used anywhere in the user makefiles!)

CONF_CC     = /usr/bin/gcc  -std=gnu11 -fgnu89-inline
CONF_CXX    = /usr/bin/g++  -std=gnu++11
CONF_CPP    = gcc -E
CONF_CXXCPP = /usr/bin/g++  -std=gnu++11 -E
CONF_AR     = ar cr
CONF_RANLIB = ranlib
CONF_LINK   = $(CXX)
CONF_C_LINK = $(CC)
CONF_STRIP  = strip

CONF_CFLAGS   =  -Wall -Wno-format-y2k  -pthread -fopenmp -O2 -fPIC 
CONF_CXXFLAGS =  -Wall -Wno-format-y2k  -pthread -fopenmp -O2 -fPIC 
CONF_CPPFLAGS = -DNDEBUG -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE   -D_MT -D_REENTRANT -D_THREAD_SAFE $(STD_INCLUDE)
CONF_DEPFLAGS = -M
CONF_DEPFLAGS_POST = 
CONF_LDFLAGS  =  -Wl,--enable-new-dtags -Wl,-export-dynamic  -pthread -fopenmp   -O
CONF_APP_LDFLAGS = 
CONF_DLL_LDFLAGS =  -fPIC $(DLL_UNDEF_FLAGS)
CONF_LIBS     = -ldl -lm  -lpthread
CONF_C_LIBS   = -lm  -lpthread

# Settings for building tools that shouldn't be cross-compiled, even
# if everything else is.
#
# NB: Code using these settings should not attempt to use any
# third-party packages, or even rely on settings from ncbiconf.h.
# Also, it should require unix and -XCODE, since these macros are
# otherwise undefined at the moment.

CC_FOR_BUILD       = gcc
CPP_FOR_BUILD      = gcc -E
CFLAGS_FOR_BUILD   = -g -O2
CPPFLAGS_FOR_BUILD = 
LDFLAGS_FOR_BUILD  = 

### Configurable compiler/librarian/linker binaries and options
### (ORIG-Set:  not to be alternated, but can be used in the user makefiles
### to alternate the value of relevant flags, e.g. CXX = $(ORIG_CXX) -DFOO_BAR)

ORIG_CC     = $(CONF_CC)
ORIG_CXX    = $(CONF_CXX)
ORIG_CPP    = $(CONF_CPP)
ORIG_CXXCPP = $(CONF_CXXCPP)
ORIG_AR     = $(CONF_AR)
ORIG_RANLIB = $(CONF_RANLIB)
ORIG_LINK   = $(CONF_LINK)
ORIG_C_LINK = $(CONF_C_LINK)
ORIG_STRIP  = $(CONF_STRIP)

ORIG_CFLAGS   = $(CONF_CFLAGS)
ORIG_CXXFLAGS = $(CONF_CXXFLAGS)
ORIG_CPPFLAGS = $(CONF_CPPFLAGS)
ORIG_DEPFLAGS = $(CONF_DEPFLAGS)
ORIG_DEPFLAGS_POST = $(CONF_DEPFLAGS_POST)
ORIG_LDFLAGS  = $(CONF_LDFLAGS)
ORIG_APP_LDFLAGS = $(CONF_APP_LDFLAGS)
ORIG_DLL_LDFLAGS = $(CONF_DLL_LDFLAGS)
ORIG_LIBS     = $(CONF_LIBS)
ORIG_C_LIBS   = $(CONF_C_LIBS)


### Configurable compiler/librarian/linker binaries and options
### (WORK-Set:  to be used by standard build rules;
###             can be modified to meet a particular project requirements)

CC     = $(CONF_CC)
CXX    = $(CONF_CXX)
CPP    = $(CONF_CPP)
CXXCPP = $(CONF_CXXCPP)
AR     = $(CONF_AR)
RANLIB = $(CONF_RANLIB)
LINK   = $(CONF_LINK)
# Linker for pure-C programs
C_LINK = $(CONF_C_LINK)
STRIP  = $(CONF_STRIP)

CFLAGS   = $(CONF_CFLAGS)
CXXFLAGS = $(CONF_CXXFLAGS)
CPPFLAGS = $(CONF_CPPFLAGS)
DEPFLAGS = $(CONF_DEPFLAGS)
DEPFLAGS_POST = $(CONF_DEPFLAGS_POST)
LDFLAGS  = $(CONF_LDFLAGS)
APP_LDFLAGS = $(CONF_APP_LDFLAGS)
DLL_LDFLAGS = $(CONF_DLL_LDFLAGS)
LIBS     = $(CONF_LIBS)
# Libraries for pure-C programs
C_LIBS   = $(CONF_C_LIBS)
PRE_LIBS =

# To add directory /foo to the list to search at runtime, you can add
# $(RUNPATH_FLAG)/foo to your LDFLAGS.
RUNPATH_FLAG = -Wl,-rpath,
# Special case: add the searcher's current location (only works on
# Linux and Solaris)
RUNPATH_ORIGIN = -Wl,-rpath,'$$ORIGIN'

### Debug/release suffixes
# "Debug" for debugging, "Release" for release
DEBUG_SFX = Release
# 'd' for debugging, empty for release
D_SFX=

### Muli-thread suffix
# "MT" if multi-thread,  "" if single-thread
MT_SFX = MT

### Whether to build apps
APP_OR_NULL = app

### DLL specifics
# whether to build the lib as static or dynamic; valid settings
# are lib, dll, both, $(USUAL_AND_DLL), and $(USUAL_AND_LIB).
ORIG_LIB_OR_DLL = lib
LIB_OR_DLL    = $(ORIG_LIB_OR_DLL)
USUAL_AND_DLL = both
USUAL_AND_LIB = lib

# Library name suffix; either "-dll" or empty.  Normally EMPTY for
# --with-dll configurations, which can simply exploit the linker's
# general preference for dynamic libraries.
DLL          = -dll
# Library name suffix; either "-static" or empty.
STATIC       = -static
# Hard-coded; use only for "LIB_OR_DLL = both" libraries!
FORCE_STATIC = -static

LINK_DLL      = $(CXX)  -shared -o
LINK_LOADABLE = 
CFLAGS_DLL    = 
CXXFLAGS_DLL  = 

dll_ext      = .so
loadable_ext = .so

# For various reasons, we traditionally allow shared libraries to have
# undefined symbols; however, it's also possible to ask the linker to
# be stricter by switching DLL_UNDEF_FLAGS to $(FORBID_UNDEF).
ALLOW_UNDEF     = 
FORBID_UNDEF    = -Wl,--no-undefined -Wl,--no-allow-shlib-undefined
DLL_UNDEF_FLAGS = $(ALLOW_UNDEF)
LDFLAGS_DLL     = $(LDFLAGS)

# Alternate DLL_LIB setting to use when configured --with-dll.
DLL_DLIB = $(DLL_LIB)
# Alternate LIB and LIBS settings to use when configured --without-dll.
STATIC_LIB = $(LIB)
STATIC_LIBS = $(LIBS)

### To enable extra, potentially unsafe, optimization, use these flags
### INSTEAD of $(ORIG_*FLAGS).
### Note: If you have compiled any files with $(FAST_CXXFLAGS), you
### should pass $(FAST_LDFLAGS) to the linker for consistency.
FAST_CFLAGS   =   -Wall -Wno-format-y2k  -pthread -fopenmp -fPIC   -O3 -finline-functions -fstrict-aliasing -fomit-frame-pointer
FAST_CXXFLAGS =   -Wall -Wno-format-y2k  -pthread -fopenmp -fPIC   -O3 -finline-functions -fstrict-aliasing -fomit-frame-pointer
FAST_LDFLAGS  =   -Wl,--enable-new-dtags -Wl,-export-dynamic  -pthread -fopenmp    -O3 -finline-functions -fstrict-aliasing -fomit-frame-pointer

UNSAFE_MATH_FLAG = -funsafe-math-optimizations
SSE4_1_FLAG      = -msse4.1
AES_FLAG         = -maes

COLOR_DIAGNOSTICS = -fdiagnostics-color=always

# Refrain from optimizations that assume no aliasing.
NO_STRICT_ALIASING = -fno-strict-aliasing

### For platform-specific includes
COMPILER = gcc
OSTYPE   = linux

### Pointer size
NCBI_PLATFORM_BITS = 64

### Support for Objective C++ (needed to use some Mac OS X APIs)
OBJCXX_CXXFLAGS = 
OBJCXX_LIBS     = 

### Support for OpenMP
OPENMP_FLAGS = 

### Post-link command (empty by default, historically needed for
### graphical apps on Mac OS X)
POST_LINK = @:

### Configuration summary
signature = GCC_540-ReleaseMT64--x86_64-unknown-linux4.4.0-gnu2.23-z010

### Do not use any default suffix rules
.SUFFIXES:

### Use automatic auto-dependencies (SunOS make, .KEEP_STATE:)

### "rules"/"rules_with_autodep" (whether to build auto-deps for GNU make)
Rules=rules_with_autodep
### Kludge module to workaround an RTTI bug (Sun WorkShop only)
serial_ws50_rtti_kludge=
### Special object file needed for atomic counters
ncbicntr=
### Holds Java Native Interface glue in --with-jni builds
ncbi_java=

#################################
# Some platform-specific system libs that can be linked eventually
THREAD_LIBS  = -lpthread
NETWORK_LIBS = -lssl -lcrypto -lnsl
MATH_LIBS    = -lm
KSTAT_LIBS   = 
RPCSVC_LIBS  = 
CRYPT_LIBS   = -lcrypt
DL_LIBS      = -ldl
RT_LIBS      = 
DEMANGLE_LIBS= 
ICONV_LIBS   = 
UUID_LIBS    = 

# libconnect now uses NCBI_SwapPointers, which conditionally requires
# LIB to include xncbi (depending on certain configuration details);
# this macro always expands to the right value.
NCBIATOMIC_LIB = 

# This is a temporary workaround for Solaris/Intel platforms where
# we had to do a kludgy patch to work around a faulty Sybase "tli" lib.
# One can use this instead of $(NETWORK_LIBS) (which has the patch built in)
# if he is not using Sybase libs (and maybe even does not have them installed).
NETWORK_PURE_LIBS = -lssl -lcrypto -lnsl

# Extra name-resolution libraries; $(NETWORK[_PURE]_LIBS) should normally
# suffice, but in some specialized cases you may need to prepend
# $(RESOLVER_LIBS).
RESOLVER_LIBS = -lresolv


#################################
# Optional variables that may be needed to build some projects
# (see in "configure.ac" for the pre-set defaults)
#

# --with-local-lbsm:  --->  src/connect/Makefile.[x]connect.lib
LOCAL_LBSM = ncbi_lbsmd_stub
# --with-ncbi-crypt:  --->  src/connect/ext/Makefile.connext.lib
NCBI_CRYPT = ncbi_crypt_stub

# non-public (X)CONNECT extensions
CONNEXT  = 
XCONNEXT = 

# NCBI C++ API for BerkeleyDB
BDB_LIB       = 
BDB_CACHE_LIB = 

# Possibly absent DBAPI drivers (depending on whether the relevant
# 3rd-party libraries are present, and whether DBAPI was disabled altogether)
DBAPI_DRIVER  = dbapi_driver
DBAPI_CTLIB   = 
DBAPI_DBLIB   = 
DBAPI_FTDS    = ncbi_xdbapi_ftds
DBAPI_FTDS64  = ncbi_xdbapi_ftds64
DBAPI_FTDS95  = ncbi_xdbapi_ftds95
DBAPI_MYSQL   = ncbi_xdbapi_mysql
DBAPI_ODBC    = 

# Compression libraries; the LIBS version goes in LIBS, and the LIB
# version goes in LIB.
Z_INCLUDE   =  
Z_LIBS      = -lz 
Z_LIB       = 
BZ2_INCLUDE =  
BZ2_LIBS    = -lbz2 
BZ2_LIB     = 
LZO_INCLUDE = 
LZO_LIBS    = 

CMPRS_INCLUDE = $(Z_INCLUDE) $(BZ2_INCLUDE) $(LZO_INCLUDE)
CMPRS_LIBS    = $(Z_LIBS) $(BZ2_LIBS) $(LZO_LIBS)
CMPRS_LIB     = $(Z_LIB) $(BZ2_LIB)

# Perl-Compatible Regular Expressions
# For historical reasons, the bundled (LIB) version contains the POSIX
# wrapper and goes by the name "regexp".
PCRE_INCLUDE   =  -I/home/yutianx/miniconda2/include
PCRE_LIBS      = -L/home/yutianx/miniconda2/lib -Wl,-rpath,/home/yutianx/miniconda2/lib -lpcre 
PCREPOSIX_LIBS = -L/home/yutianx/miniconda2/lib -Wl,-rpath,/home/yutianx/miniconda2/lib -lpcreposix -lpcre 
PCRE_LIB       = 

# OpenSSL, GnuTLS, and potential supporting packages: headers and libs.
# TLS_* points to GNUTLS_* by preference.
GMP_INCLUDE     = 
GMP_LIBS        = 
GCRYPT_INCLUDE  = 
GCRYPT_LIBS     = 
NETTLE_INCLUDE  = 
NETTLE_LIBS     = 
GNUTLS_INCLUDE  = 
GNUTLS_LIBS     = 
OPENSSL_INCLUDE =  
OPENSSL_LIBS    = -lssl -lcrypto
OPENSSL_STATIC_LIBS = -lssl -lcrypto
TLS_INCLUDE     =  
TLS_LIBS        = -lssl -lcrypto

# Kerberos 5 (via GSSAPI)
KRB5_INCLUDE =  -I/home/yutianx/miniconda2/include 
KRB5_LIBS    = -L/home/yutianx/miniconda2/lib -Wl,-rpath,/home/yutianx/miniconda2/lib -lgssapi_krb5 -lkrb5 -lk5crypto -lcom_err

# Sybase:  headers and libs
SYBASE_INCLUDE = 
SYBASE_LIBS    = 
SYBASE_DLLS    = 
SYBASE_DBLIBS  = 

# FreeTDS -- specific bundled versions, default
FTDS64_CTLIB_LIBS    = 
FTDS64_CTLIB_LIB     = 
FTDS64_CTLIB_INCLUDE = 
FTDS64_LIBS          = 
FTDS64_LIB           = 
FTDS64_INCLUDE       = 

FTDS95_CTLIB_LIBS    = 
FTDS95_CTLIB_LIB     = 
FTDS95_CTLIB_INCLUDE = 
FTDS95_LIBS          = 
FTDS95_LIB           = 
FTDS95_INCLUDE       = 

FTDS_LIBS    = 
FTDS_LIB     = 
FTDS_INCLUDE = 

# MySQL: headers and libs
MYSQL_INCLUDE = -I/home/yutianx/miniconda2/include
MYSQL_LIBS    = -L/home/yutianx/miniconda2/lib -Wl,-rpath,/home/yutianx/miniconda2/lib -lmysqlclient -lpthread -lm -lrt -ldl

# Berkeley DB: headers and libs
BERKELEYDB_INCLUDE         = 
BERKELEYDB_STATIC_LIBS     = 
BERKELEYDB_LIBS            = 
BERKELEYDB_CXX_STATIC_LIBS = 
BERKELEYDB_CXX_LIBS        = 

# ODBC: headers and libs
ODBC_INCLUDE = -I$(includedir)/dbapi/driver/odbc/unix_odbc -I$(includedir0)/dbapi/driver/odbc/unix_odbc
ODBC_LIBS    = 

# PYTHON: headers and libs (default + specific versions)
PYTHON_INCLUDE   = -I/home/yutianx/miniconda2/include/python2.7 -I/home/yutianx/miniconda2/include/python2.7
PYTHON_LIBS      = -L/home/yutianx/miniconda2/lib -L/home/yutianx/miniconda2/lib/python2.7/config -Wl,-rpath,/home/yutianx/miniconda2/lib:/home/yutianx/miniconda2/lib/python2.7/config -lpython2.7 -lpthread -ldl  -lutil -lm
PYTHON25_INCLUDE = 
PYTHON25_LIBS    = 
PYTHON26_INCLUDE = 
PYTHON26_LIBS    = 
PYTHON27_INCLUDE = -I/home/yutianx/miniconda2/include/python2.7 -I/home/yutianx/miniconda2/include/python2.7
PYTHON27_LIBS    = -L/home/yutianx/miniconda2/lib -L/home/yutianx/miniconda2/lib/python2.7/config -Wl,-rpath,/home/yutianx/miniconda2/lib:/home/yutianx/miniconda2/lib/python2.7/config -lpython2.7 -lpthread -ldl  -lutil -lm
PYTHON3_INCLUDE  = -I/usr/include/python3.5m -I/usr/include/python3.5m
PYTHON3_LIBS     = -L/usr/lib/python3.5/config-3.5m-x86_64-linux-gnu -Wl,-rpath,/usr/lib/python3.5/config-3.5m-x86_64-linux-gnu -lpython3.5m -lpthread -ldl  -lutil -lm

# Perl: executable, headers and libs
PERL         = /home/yutianx/miniconda2/bin/perl
PERL_INCLUDE = -I/home/yutianx/miniconda2/lib/perl5/5.22.0/x86_64-linux-thread-multi/CORE -D_REENTRANT -D_GNU_SOURCE -I/usr/local/include
PERL_LIBS    = -L/home/yutianx/miniconda2/lib/perl5/5.22.0/x86_64-linux-thread-multi/CORE -Wl,-rpath,/home/yutianx/miniconda2/lib/perl5/5.22.0/x86_64-linux-thread-multi/CORE -lperl -lpthread -lnsl -ldl -lm -lcrypt -lutil -lc

# Java: headers and installation root
JDK_INCLUDE = 
JDK_PATH    = 

# Boost: headers and libs [use as $(BOOST_LIBPATH) $(BOOST_*_LIBS) $(RT_LIBS)]
BOOST_INCLUDE              =  -Wno-unused-local-typedefs
BOOST_LIBPATH              = 
BOOST_TAG                  = -gcc54-mt--64
BOOST_FILESYSTEM_LIBS      = 
BOOST_FILESYSTEM_STATIC_LIBS = 
BOOST_IOSTREAMS_LIBS       = 
BOOST_IOSTREAMS_STATIC_LIBS = 
BOOST_PROGRAM_OPTIONS_LIBS = 
BOOST_PROGRAM_OPTIONS_STATIC_LIBS = 
BOOST_REGEX_LIBS           = 
BOOST_REGEX_STATIC_LIBS    = 
BOOST_SYSTEM_LIBS          = 
BOOST_SYSTEM_STATIC_LIBS   = 
BOOST_TEST_PEM_LIBS        = 
BOOST_TEST_PEM_STATIC_LIBS = 
BOOST_TEST_TEM_LIBS        = 
BOOST_TEST_TEM_STATIC_LIBS = 
BOOST_TEST_UTF_LIBS        = 
BOOST_TEST_UTF_STATIC_LIBS = 
BOOST_THREAD_LIBS          = 
BOOST_THREAD_STATIC_LIBS   = 
BOOST_TEST_LIBS            = $(BOOST_LIBPATH) $(BOOST_TEST_UTF_LIBS)
BOOST_TEST_STATIC_LIBS     = $(BOOST_LIBPATH) $(BOOST_TEST_UTF_STATIC_LIBS)
# Temporary, for backward compatibility, to be removed later:
BOOST_LIBS            = $(BOOST_TEST_LIBS)
BOOST_STATIC_LIBS     = $(BOOST_TEST_STATIC_LIBS)

# NCBI C Toolkit:  headers and libs
NCBI_C_INCLUDE = 
NCBI_C_LIBPATH = 
NCBI_C_ncbi = 

# OpenGL: headers and libs (including core X dependencies) for code
# not using other toolkits.  (The wxWidgets variables already include
# these as appropriate.)
OPENGL_INCLUDE     = 
OPENGL_LIBS        =   -lGLU -lGL  -lXt -lXext  -lX11 
OPENGL_STATIC_LIBS =   -lGLU -lGL  -lXt -lXext  -lX11 
OSMESA_INCLUDE     = 
OSMESA_LIBS        = 
OSMESA_STATIC_LIBS = 
GLUT_INCLUDE       = 
GLUT_LIBS          = 
GLEW_INCLUDE       = 
GLEW_LIBS          = 
GLEW_STATIC_LIBS   = 

# wxWidgets (2.6 or newer):  headers and libs
WXWIDGETS_INCLUDE        = 
WXWIDGETS_LIBS           = 
WXWIDGETS_STATIC_LIBS    = 
WXWIDGETS_GL_LIBS        = 
WXWIDGETS_GL_STATIC_LIBS = 
# Assign WXWIDGETS_POST_LINK to POST_LINK when building WX apps.
WXWIDGETS_POST_LINK      = :

# Fast-CGI lib:  headers and libs
FASTCGI_INCLUDE = 
FASTCGI_LIBS    = 
# Fast-CGI lib:  (module to add to the "xcgi" library)
FASTCGI_OBJS    = 

# NCBI SSS:  headers, library path, libraries
NCBI_SSS_INCLUDE = 
NCBI_SSS_LIBPATH = 
LIBSSSUTILS      = 
LIBSSSDB         = 
sssutils         = 
NCBILS2_LIB      = ncbils2_cli ncbils2_asn ncbils2_cmn
NCBILS_LIB       = $(NCBILS2_LIB)

# NCBI SRA/VDB Toolkit
VDB_INCLUDE     = 
VDB_LIBS        = 
VDB_STATIC_LIBS = 
VDB_REQ         = VDB
VDB_POST_LINK   = :
bamread               = 
sraread               = 
ncbi_id2proc_snp      = 
ncbi_id2proc_wgs      = 
ncbi_xloader_bam      = 
ncbi_xloader_csra     = 
ncbi_xloader_snp      = 
ncbi_xloader_sra      = 
ncbi_xloader_vdbgraph = 
ncbi_xloader_wgs      = 

# SP:  headers, libraries
SP_INCLUDE = 
SP_LIBS    = 

# ORBacus CORBA headers, library path, libraries
ORBACUS_INCLUDE = 
ORBACUS_LIBPATH = 
LIBOB           = 
# LIBIMR should be empty for single-threaded builds
LIBIMR          = 

# IBM's International Components for Unicode
ICU_CONFIG      = /home/yutianx/miniconda2/bin/icu-config
ICU_INCLUDE     = -I/home/yutianx/miniconda2/include 
ICU_LIBS        = -L/home/yutianx/miniconda2/lib -Wl,-rpath,/home/yutianx/miniconda2/lib -licui18n -licuuc -licudata 
ICU_STATIC_LIBS = -L/home/yutianx/miniconda2/lib  -lsicui18n -lsicuuc -lsicudata 

# XML/XSL support:
EXPAT_INCLUDE      =  
EXPAT_LIBS         = -lexpat 
EXPAT_STATIC_LIBS  = -lexpat 
SABLOT_INCLUDE     = 
SABLOT_LIBS        = 
SABLOT_STATIC_LIBS = 
LIBXML_INCLUDE     = -I/usr/include/libxml2
LIBXML_LIBS        = -lxml2 
LIBXML_STATIC_LIBS = -lxml2 
LIBXSLT_INCLUDE    = -I/usr/include/libxml2 
LIBXSLT_MAIN_LIBS  = -lxslt 
LIBXSLT_MAIN_STATIC_LIBS = -lxslt 
XSLTPROC           = /home/yutianx/miniconda2/bin/xsltproc
LIBEXSLT_INCLUDE   = -I/usr/include/libxml2  
LIBEXSLT_LIBS      = -lexslt 
LIBEXSLT_STATIC_LIBS=-lexslt 
LIBXSLT_LIBS       = $(LIBEXSLT_LIBS) $(LIBXSLT_MAIN_LIBS)
LIBXSLT_STATIC_LIBS= $(LIBEXSLT_STATIC_LIBS) $(LIBXSLT_MAIN_STATIC_LIBS)
XERCES_INCLUDE     = 
XERCES_LIBS        = 
XERCES_STATIC_LIBS = 
XALAN_INCLUDE      = 
XALAN_LIBS         = 
XALAN_STATIC_LIBS  = 
ZORBA_INCLUDE      = 
ZORBA_LIBS         = 
ZORBA_STATIC_LIBS  = 

# OpenEye OEChem library:
OECHEM_INCLUDE = 
OECHEM_LIBS    = 

# Sun Grid Engine (libdrmaa):
SGE_INCLUDE = 
SGE_LIBS    = 

# muParser
MUPARSER_INCLUDE = 
MUPARSER_LIBS    = 

# HDF5
HDF5_INCLUDE = 
HDF5_LIBS    = 

# SQLite 3.x
SQLITE3_INCLUDE     = 
SQLITE3_LIBS        = 
SQLITE3_STATIC_LIBS = 

# Various image-format libraries
JPEG_INCLUDE  =  
JPEG_LIBS     = -ljpeg 
PNG_INCLUDE   =   
PNG_LIBS      = -lpng -lz 
TIFF_INCLUDE  =  
TIFF_LIBS     = -ltiff -lz 
GIF_INCLUDE   = 
GIF_LIBS      = 
UNGIF_INCLUDE = 
UNGIF_LIBS    = 
XPM_INCLUDE   =  
XPM_LIBS      = -lXpm   -lX11

IMAGE_LIBS    = $(TIFF_LIBS) $(JPEG_LIBS) $(PNG_LIBS) $(GIF_LIBS) $(XPM_LIBS)

# FreeType, FTGL
FREETYPE_INCLUDE = -I/home/yutianx/miniconda2/include/freetype2
FREETYPE_LIBS    = -L/home/yutianx/miniconda2/lib -Wl,-rpath,/home/yutianx/miniconda2/lib -lfreetype
FTGL_INCLUDE     = 
FTGL_LIBS        = 

# libmagic (file-format identification)
MAGIC_INCLUDE = 
MAGIC_LIBS    = 

# libcurl (URL retrieval)
CURL_INCLUDE =  
CURL_LIBS    = -lcurl 

# libmimetic (MIME handling)
MIMETIC_INCLUDE = 
MIMETIC_LIBS    = 

# libgSOAP++
GSOAP_PATH     = No_GSOAP
GSOAP_INCLUDE  = 
GSOAP_LIBS     = 
GSOAP_SOAPCPP2 = 
GSOAP_WSDL2H   = 

# Apache Avro
AVRO_INCLUDE     = 
AVRO_LIBS        = 
AVRO_STATIC_LIBS = 
AVROGENCPP       = 

# USC Cereal (header-only)
CEREAL_INCLUDE = 

# SASL 2
SASL2_INCLUDE =  
SASL2_LIBS    = -lsasl2 

# MongoDB
MONGODB_INCLUDE     = 
MONGODB_LIBS        = 
MONGODB_STATIC_LIBS = 

# Google Mock
GMOCK_INCLUDE = 
GMOCK_LIBS    = 

# LAPACK
LAPACK_INCLUDE =  
LAPACK_LIBS    = -llapack -lblas

# LMDB
LMDB_INCLUDE = 
LMDB_LIBS    = 

# Compress
COMPRESS_LDEP = $(CMPRS_LIB)
COMPRESS_LIBS = xcompress $(COMPRESS_LDEP)

#################################
# Useful sets of object libraries
GENBANK_LDEP = \
    ncbi_xreader_id1 ncbi_xreader_id2 ncbi_xreader_cache \
    $(GENBANK_READER_PUBSEQOS_LIBS)
GENBANK_LIBS = ncbi_xloader_genbank $(GENBANK_LDEP)

GENBANK_READER_LDEP = $(XCONNEXT) xconnect id1 id2 $(SOBJMGR_LIBS) $(COMPRESS_LIBS)
GENBANK_READER_LIBS = ncbi_xreader $(GENBANK_READER_LDEP)

# In-house-only PubSeqOS loader (not always built)
ncbi_xreader_pubseqos = 
ncbi_xreader_pubseqos2 = 
GENBANK_READER_PUBSEQOS_LDEP = $(DBAPI_DRIVER) $(GENBANK_READER_LIBS)
#  GENBANK_READER_PUBSEQOS_LDEP = xconnect $(GENBANK_READER_LIBS)
GENBANK_READER_PUBSEQOS_LIBS = $(ncbi_xreader_pubseqos) $(GENBANK_READER_PUBSEQOS_LDEP)

GENBANK_READER_ID1_LDEP = xconnect id1 $(GENBANK_READER_LIBS)
GENBANK_READER_ID1_LIBS = ncbi_xreader_id1 $(GENBANK_READER_ID1_LDEP)

GENBANK_READER_ID2_LDEP = xconnect id2 seqsplit $(GENBANK_READER_LIBS)
GENBANK_READER_ID2_LIBS = ncbi_xreader_id2 $(GENBANK_READER_ID2_LDEP)

GENBANK_READER_CACHE_LDEP = $(GENBANK_READER_LIBS)
GENBANK_READER_CACHE_LIBS = ncbi_xreader_cache $(GENBANK_READER_CACHE_LDEP)

GENBANK_READER_GICACHE_LDEP = $(GENBANK_READER_LIBS)
GENBANK_READER_GICACHE_LIBS = ncbi_xreader_gicache \
        $(GENBANK_READER_GICACHE_LDEP)

# Interdependent sequence libraries + seqcode.  Does not include seqset.
SEQ_LIBS = seq seqcode sequtil
SOBJMGR_LDEP = genome_collection seqedit seqsplit seqset $(SEQ_LIBS) \
    pub medline biblio general xser xutil xncbi
SOBJMGR_LIBS = xobjmgr $(SOBJMGR_LDEP)
OBJMGR_LIBS = $(GENBANK_LIBS)

# Overlapping with qall is poor, so we have a second macro to make it
# easier to stay out of trouble.
QOBJMGR_ONLY_LIBS = xobjmgr id2 seqsplit id1 genome_collection seqset \
    $(SEQ_LIBS) pub medline biblio general xcompress $(CMPRS_LIB)
QOBJMGR_LIBS = $(QOBJMGR_ONLY_LIBS) qall
QOBJMGR_STATIC_LIBS = $(QOBJMGR_ONLY_LIBS:%=%$(STATIC)) qall

# EUtils
EUTILS_LIBS = eutils egquery elink epost esearch espell esummary linkout \
              einfo uilist ehistory

# Object readers
OBJREAD_LIBS = xobjread variation creaders submit

# formatting code
XFORMAT_LIBS = xformat xcleanup gbseq submit mlacli mla medlars pubmed valid taxon3

# object editing library
OBJEDIT_LIBS = xobjedit $(OBJREAD_LIBS) taxon3

# standard data loader configuration, plus supporting libraries
DATA_LOADERS_UTIL_LIB = data_loaders_util \
                        ncbi_xloader_asn_cache asn_cache bdb \
                        ncbi_xloader_lds2 lds2 $(OBJREAD_LIBS) sqlitewrapp \
                        ncbi_xloader_blastdb seqdb blastdb \
                        $(ncbi_xreader_pubseqos2) ncbi_xdbapi_ftds $(FTDS_LIB) \
                        $(ncbi_xloader_wgs) $(ncbi_xloader_csra) \
                        $(SRAREAD_LIBS)

DATA_LOADERS_UTIL_LIBS = $(BERKELEYDB_LIBS) $(SQLITE3_LIBS) $(FTDS_LIBS) \
                         $(VDB_LIBS)

### Extra macro definitions from /data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++/src/algo/blast/Makefile.blast_macros.mk

#line 1 "/data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++/src/algo/blast/Makefile.blast_macros.mk"
#################################
# $Id: Makefile.blast_macros.mk 499473 2016-04-26 14:40:22Z camacho $
# This file contains macro definitions for using libraries maintained by the
# BLAST TEAM
# Author:  Christiam Camacho (camacho@ncbi.nlm.nih.gov)
#################################


BLAST_FORMATTER_MINIMAL_LIBS = xblastformat align_format taxon1 blastdb_format \
    gene_info $(XFORMAT_LIBS) xalnmgr blastxml blastxml2 xcgi xhtml
# BLAST_FORMATTER_LIBS = $(BLAST_FORMATTER_MINIMAL_LIBS)
BLAST_FORMATTER_LIBS = $(BLAST_INPUT_LIBS)
BLAST_DB_DATA_LOADER_LIBS = ncbi_xloader_blastdb_rmt ncbi_xloader_blastdb
BLAST_INPUT_LIBS = blastinput \
    $(BLAST_DB_DATA_LOADER_LIBS) $(BLAST_FORMATTER_MINIMAL_LIBS)

# Libraries required to link against the internal BLAST SRA library
BLAST_SRA_LIBS=blast_sra $(SRAXF_LIBS) vxf $(SRA_LIBS)

# BLAST_FORMATTER_LIBS and BLAST_INPUT_LIBS need $BLAST_LIBS
BLAST_LIBS = xblast xalgoblastdbindex composition_adjustment \
		xalgodustmask xalgowinmask seqmasks_io seqdb blast_services xalnmgr \
		xobjutil $(OBJREAD_LIBS) xnetblastcli xnetblast blastdb scoremat tables
# BLAST additionally needs xconnect $(SOBJMGR_LIBS) or $(OBJMGR_LIBS)
