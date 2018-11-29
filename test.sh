#!/bin/bash

r='\033[0;31m'
g='\033[0;32m'
w='\033[0;39m'

program="sscc"

try() {
    expected="$1"
    input="$2"

    ./${program} "${input}" > tmp.s
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

echo '========== binary operator'
try 10 '6+4'
try 10 '128 - 118'
try 20 '128 - 118 + 10'
try 15 '128 - 118 + 10 - 5'

echo
echo -e "${g}All test is OK${w}"
echo
