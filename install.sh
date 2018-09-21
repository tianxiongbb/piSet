#!/bin/bash

PATH_PRO=$(dirname `readlink -f $0`)

# write program path in PATH
[ ! `which piSet_srnaseq` ] && echo -e "# added by piSet installer\nexport PATH=${PATH_PRO}/bin:\$PATH" >> ~/.bashrc
! python -c "import bb_basic" 2>/dev/null && echo -e "# added by piSet installer\nexport PYTHONPATH=${PATH_PRO}/bin/lib_python:\$PYTHONPATH" >> ~/.bashrc

# configure RepeatMasker
#awk -v pt=${PATH_PRO}/bin \
#	'{\
#		if(NR==96){print "    $RMBLAST_DIR   = \""pt"/ncbi-blast-2.6.0+-src/c++/ReleaseMT/bin\";"}\
#		else if(NR==131){print "  $DEFAULT_SEARCH_ENGINE = \"ncbi\";"}\
#		else if(NR==162){print "  $TRF_PRGM = \""pt"/trf404.linux64\";"}\
#		else{print $0}\
#	}' ${PATH_PRO}/bin/RepeatMasker/RepeatMaskerConfig.pm > t && mv t ${PATH_PRO}/bin/RepeatMasker/RepeatMaskerConfig.pm 
#
#
## install RepeatModeler dependencies and configure
#echo "install RECON......"
#cd ${PATH_PRO}/bin/RECON-1.08/src && make && awk -v pt=${PATH_PRO}/bin/RECON-1.08/bin '{if(NR==3){print "$path = \""pt"\""}else{print $0}}' ${PATH_PRO}/bin/RECON-1.08/scripts/recon.pl > t && mv t ${PATH_PRO}/bin/RECON-1.08/scripts/recon.pl
#echo "install RepeatScout......"
#cd ${PATH_PRO}/bin/RepeatScout-1 && make
#echo "install nseg......"
#cd ${PATH_PRO}/bin/nseg && make
#echo "configure RepeatModeler......"
#awk -v pt=${PATH_PRO}/bin \
#	'{\
#		if(NR==59){print "  $REPEATMASKER_DIR = \""pt"/RepeatMasker\";"}\
#		else if(NR==67){print "  $RMBLAST_DIR      = \""pt"/ncbi-blast-2.6.0+-src/c++/ReleaseMT/bin\";"}\
#		else if(NR==93){print "  $DEFAULT_SEARCH_ENGINE = \"ncbi\";"}\
#		else if(NR==100){print "  $RECON_DIR = \""pt"/RECON-1.08/bin\";"}\
#		else if(NR==107){print "  $TRF_PRGM = \""pt"/trf404.linux64\";"}\
#		else if(NR==113){print "  $NSEG_PRGM = \""pt"/nseg/nseg\";"}\
#		else if(NR==120){print "  $RSCOUNT_DIR = \""/RepeatScout-1"\";"}\
#		else{print $0}\
#	}' ${PATH_PRO}/bin/RepeatModeler-open-1.0.11/RepModelConfig.pm > t && mv t ${PATH_PRO}/bin/RepeatModeler-open-1.0.11/RepModelConfig.pm 
#
## test if RepeatMasker and RepeatModeler are installed successfully
#[ "`${PATH_PRO}/bin/RepeatMasker/RepeatMasker -v 2>/dev/null`" ] && echo "RepeatMasker installed successfully!" || echo "Error in RepeatMasker installation."
#[ "`${PATH_PRO}/bin/RepeatModeler-open-1.0.11/RepeatModeler -v 2>/dev/null`" ] && echo "RepeatModeler installed successfully!" || echo "Error in RepeatModeler installation."
