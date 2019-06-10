#!/bin/sh

grep -r -A1 --include \*.c -H "[-&|?:%]$" $@
grep -r -A1 --include \*.c -H -e '[^/]\*$' $@