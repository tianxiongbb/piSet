#!/bin/bash

PATH_PRO=$(dirname `readlink -f $0`)

# write program path in PATH
echo -e "# added by piPipes_summary installer\nexport PATH=${PATH_PRO}:\$PATH" >> ~/.bashrc
echo -e "export PYTHONPATH=${PATH_PRO}/lib_python:\$PYTHONPATH" >> ~/.bashrc
# check gs
if [ ! `which gs` ];then
	echo0 3 "ghostScript not find, use gs-922-linux-x86_64 in bed2_summary......"
	echo -e "alias gs='gs-922-linux-x86_64'"
fi


