#!/bin/bash

r='\033[0;31m'
g='\033[0;32m'
w='\033[0;39m'

try() {
    expected="$1"
    input="$2"

    ./cell "${input}" > tmp.s
    gcc -o tmp tmp.s
    ./tmp
    actual="$?"

    if [ "${actual}" != "${expected}" ]; then
	echo -e "${r}NG:${w} $expected expected, but got $actual"
	exit 1
    else
	echo -e "${g}OK:${w} ${input} = ${actual}"
    fi
}

echo '========== number'
try 0 '0'
try 128 '128'
try 255 '255'

echo
echo -e "${g}All test is OK${w}"
echo
