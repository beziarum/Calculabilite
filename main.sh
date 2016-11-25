#!/bin/bash
function check {
    if [ ! -e $1 ];then
	echo "$1 don't exist, try to compile it"
	if make $1;then
	    echo compiled
	else
	    echo compilation failed
	fi
    fi
}

check "$1"
check "pars"

./pars $2 $(./$1 $2|./glucose-syrup_static -model -no-elim|tail -n 1)
