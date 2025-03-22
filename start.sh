#!/bin/bash

PWD=`pwd`
CHECKED_SUM="24e7a7b2270daee89c64d3ca5fb3da1a"

MD5=`cat ${PWD}/ip_filter.tsv | ./otus_hw_2 | md5sum | awk '{ print $1 }'`

echo "Utility stdout md5sum: $MD5"

if [ "${MD5}" = "${CHECKED_SUM}" ]; then
	echo "Check md5sum Done"
else
	echo "Fail check md5sum"
fi

