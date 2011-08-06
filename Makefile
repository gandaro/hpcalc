SHELL=/bin/bash
FLAGS_FINAL=-lgmp -Wall -O3
FLAGS=-Wall -O3
BINARY=hpcalc
OBJECTFILES=main.o help.o std_funcs_hpcalc.o error.o math_hpcalc.o

clean : $(BINARY)
	rm *.o

$(BINARY) : $(OBJECTFILES)
	gcc $^ $(FLAGS_FINAL) -o $@

%.o : src/%.c
	gcc -c $< $(FLAGS) -o $@
