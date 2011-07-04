# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "headers/math_hpcalc.h"

char* changeCommaToPoint(char *str)
{
	unsigned int i=0;

	while ( str[i] != '\0' )
	{
		if ( str[i] == ',' )
			str[i] = '.';
		i++;
	}
	return str;
}

int contains(char *str,char what)
{
	int i = 0,contyn=0;
	while ( str[i] != '\0' )
	{
		if ( str[i] == what )
		{
			contyn = 1;
		}
		i++;
	}

	return(contyn);
}
