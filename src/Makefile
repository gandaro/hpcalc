SHELL=/bin/bash
FLAGS=-Wall -O3
OBJECTS=src/error.o src/getopt.o src/help.o src/main.o src/math_hpcalc.o src/std_funcs_hpcalc.o

all: $(OBJECTS)
	mv src/*.o build/
.c.o:
	gcc $(FLAGS) -c $< -o $@
