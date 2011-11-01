# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../headers/math_hpcalc.h"

char* changeCommaToPoint(char *str) // We need this function for our users from germany
{
	unsigned int i=0;

	while ( str[i] != '\0' )
	{
		if ( str[i] == ',' )
		{
                        str[i] = '.';
                        break; // We don't need to check possibly thousands of characters after the comma
                }

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
                        break; // like at changeCommaToPoint. If contained one time, you don't need to check the other elements
		}
		i++;
	}

	return(contyn);
}
