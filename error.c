# include <stdio.h>
# include <stdlib.h>

void error_exit(const char outp[])
{
	fprintf(stderr,"%s",outp);
	exit(1);
}
