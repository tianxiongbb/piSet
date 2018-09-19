#! /bin/bash

# $Id: reconfigure.sh.in 117476 2008-01-16 16:44:07Z ucko $
# Author:  Denis Vakatov, NCBI 
# 
#  Launcher for "scripts/common/impl/reconfigure.sh"

builddir=/data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++/ReleaseMT/build
export builddir

exec /data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++/scripts/common/impl/reconfigure.sh "$@"
