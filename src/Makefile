SHELL=/bin/bash
FLAGS_FINAL=-lgmp -Wall -O3
FLAGS=-Wall -O3
BINARY=hpcalc
OBJECTS=src/error.o src/getopt.o src/help.o src/main.o src/math_hpcalc.o src/std_funcs_hpcalc.o

all: $(OBJECTS)
	mv src/*.o build/
.c.o:
	gcc -c $< -o $@
