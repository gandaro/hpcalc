SHELL=/bin/bash
FLAGS_FINAL=-lgmp -Wall -O3
FLAGS=-Wall -O3
BINARY=hpcalc

$(BINARY): main_objs
	gcc $(FLAGS_FINAL) -o $(BINARY) build/*.o

main_objs:
	make -f src/Makefile

clean:
	rm build/*.o
