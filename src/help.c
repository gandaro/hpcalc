# include <stdio.h>
# include <stdlib.h>
# include "../headers/math_hpcalc.h"
	
const char *helpstring = "hpcalc (hyper precision calc) v0.5beta (base functions work almost perfectly)\n(c) 2011 by Der Messer. License: GNU-GPL 3\n"
	"hpcalc is a program to calculate with extreme large numbers and extreme precise numbers\n"
	"hpcalc uses a high precision for floatpoint calculation while the length of integer numbers is only limited by your RAM\n"
	"\n"
	"Data types (one, either -i or -f, must be specified):\n\t-i\tInteger numbers. They can be very, very large (a few million digits)\n"
	"\t-f\tFloat numbers. hpcalc uses in this version of hpcalc by default a precision of %d bits for this numbers. You may use both , and . as decimal point\n\n"
	"Calculation options: (You can only call 1 calculation option at once, if you do not so, you'll get an error)\n"
	"\t-a\tAddition\n\t-s\tSubtraction\n\t-m\tMultiplication\n\t-d\tDivision (Floor round when using integers (25 / 4 == 6))\n"
	"\t-c\tDivision, but with ceiling round ( 25 / 4 == 7 ) - only available for integers\n"
	"\t-r\tremainder (also called \"modulo\") - only available for integers\n\t-p\tPower\n\t-g\tGreatest Common Divisor (GCD) - only available for integers\n\n"
	"\t-b\tWith argument -b you may set the at-least-precision higher than 8192 bits (ex.: hpcalc -f -b 31415 -a 3.4 5.645). It's only expedient when using floats.\n\t\t"
	"You recognize the necessity to increase the precision when there are many 0 at the end of the result or you recognize that there are too few digits\n"
	"\n\nExample: to get the solution of 3.4 + 5.4, type\n\thpcalc -f -a 3.4 5.4\n\n"
	"2nd Example: to get the solution of 24 ^ 12, type\n\thpcalc -i -p 24 12\n\n(If you calculate with integers, it's faster and sometimes more precise)\n"
	"\nBugs and issues please to <der.messer@web.de>\n\n";

void printHelp(void)
{
	printf(helpstring,ACC);
}
