# define ERR_DATATYPE "Bad arguments: int vs. float: Only one type possible. Type '-h' for help\n"
# define ERR_CALCTYPE "Bad arguments: More than one calculation type is impossible. Type '-h' for help\n"

//#define DEBUG // activate debug functions

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "error.h"
# include "std_funcs_hpcalc.h"
# include <string.h>
# include "math_hpcalc.h"

/*
   Jump table description.
Call:
	(*int_funcs[funcindex])(a,b);
	resp.
	(*float_funcs[funcindex])(a,b);

   	int_funcs[]:
		0 = int_addition();
		1 = int_subtraction();
		2 = int_multiplication();
		3 = int_fdivision();
		4 = int_remainder();
		5 = int_pow();
		6 = int_gcd();
	float_funcs[]:
		0 = float_addition();
		1 = float_subtraction();
		2 = float_multiplication();
		3 = float_division();
		4 = float_pow();
		
	Call: (*int_funcs[2])(a,b); == int_addition(a,b);
*/

