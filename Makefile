SHELL=/bin/bash
FLAGS=-lgmp -Wall -O3
BINARY=hpcalc
OBJECTS=main.o std_funcs_hpcalc.o error.o math_hpcalc.o

clean : $(BINARY)
	rm *.o

$(BINARY) : $(OBJECTS)
	gcc $^ $(FLAGS) -o $@

%.o : %.c
	gcc -c $< $(FLAGS) -o $@
