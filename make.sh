#!/bin/bash

CFLAGS="-O2 -Wall"
LINKS="-lgmp"
CFLAGS_FINAL="-O2 -Wall -lgmp"
CC=gcc
BINARY=hpcalc

cd src/

$CC -c $CFLAGS *.c

mv *.o ../build
cd ../build

$CC -o $BINARY $CFLAGS_FINAL *.o

rm *.o
