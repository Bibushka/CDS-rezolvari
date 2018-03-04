#!/bin/bash

#set -x

logfile=$1

if [ $# -ne 1 ] || [ ! -f $logfile ]; then
    echo -e "\
Invalid parameter ($logfile) provided\n\
Use: ./test2.sh <log_file>\n\
    Where <log_file> is the absolute or relative path of the log file to be processed.\n\
    "
    exit 1
fi

lines=`wc -l ${logfile} | cut -d " " -f 1`
bytes=`wc -c ${logfile} | cut -d " " -f 1`
kbytes=`bc -l <<< "$bytes / 1024"`

echo "Start processing file: $file having $lines lines, `wc -m ${logfile} | cut -d ' ' -f 1` words and $kbytes kilobytes "

grep -e "Subnet" -e "Nr. devices" $logfile | sed -e "s/Subnet.*//" -e "s/, Confirmed.*//"

