SHELL=/bin/bash
FLAGS_FINAL=-lgmp -Wall -O3
FLAGS=-Wall -O3
BINARY=build/hpcalc

$(BINARY): main_objs
	gcc -o $(BINARY) build/*.o $(FLAGS_FINAL)

main_objs:
	make -f src/Makefile

clean:
	rm build/*.o
