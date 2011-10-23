SHELL=/bin/bash
FLAGS_FINAL=-lgmp -Wall -O3
FLAGS=-Wall -O3
BINARY=hpcalc


all : objects
	gcc -o build/$(BINARY) $(FLAGS_FINAL) *.o

objects :
	gcc $(FLAGS) -c src/*.c

clean : 
	rm *.o
