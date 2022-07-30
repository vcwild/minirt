#!/bin/sh

if [ -f "/etc/redhat-release" ]
	then return=$"gcc"
elif [ -f "/etc/debian_version" ]
	then return="clang"
else return="cc"
fi

echo $return
