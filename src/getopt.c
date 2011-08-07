# include "../headers/main.h"
# include "../headers/getopt.h"

static unsigned long precision = ACC;

void getopts(int argc, char *argv[])
{
	char c = 0, datatype = 0;
	int calctype = 32767;
	short i = 0;
	// Getopt
	while ( (c = getopt(argc,argv,"ifasmpdcrhgb:")) >= 0 )
	{
		switch ( c )
		{
			case 'i' : // Integer
				if ( datatype != 0 )
					error_exit(ERR_DATATYPE);
				datatype = 'i';
				break;
			case 'f' : // Float
				if ( datatype != 0 )
					error_exit(ERR_DATATYPE);
				datatype = 'f';
				break;
			case 'a' : // Addition
				if ( calctype != 32767 )
					error_exit(ERR_CALCTYPE);
				calctype = 0;
				break;
			case 's' : // Subtraction
				if ( calctype != 32767 )
					error_exit(ERR_CALCTYPE);
				calctype = 1;
				break;
			case 'm' : // Multiplication
				if ( calctype != 32767 )
					error_exit(ERR_CALCTYPE);
				calctype = 2;
				break;
			case 'd' : // Division (fdiv per default)
				if ( calctype != 32767 )
					error_exit(ERR_CALCTYPE);
				calctype = 3;
				break;
			case 'c' : // Ceiling Division switch (cdiv)
				calctype = 7;
				break;
			case 'p' : // Power
				if ( calctype != 32767 )
					error_exit(ERR_CALCTYPE);
				calctype = 4;
				break;
			case 'r' : // Remainder (Modulo)
				if ( calctype != 32767 )
					error_exit(ERR_CALCTYPE);
				calctype = 5;
				break;
			case 'g' : // greatest common divisor
				if ( calctype != 32767 )
					   error_exit(ERR_CALCTYPE);
				calctype = 6;   
				break;
			case 'b' : // Precision in bits (Default: 8192)
				precision = strtoul(optarg,NULL,10);
				break;
			case 'h' : // Help
				printHelp();
				exit(0);
			case '?' : // Else
				printf("Unknown option. Please type '-h' to get help\n");
				exit(1);
		}		

		i++;
	}
	
	struct getopt_return *ret = (struct getopt_return *)malloc(sizeof(struct getopt_return));
	ret->i = i;
	ret->calctype = calctype;
	ret->datatype = datatype;
	ret->argc = argc;
	ret->optind = optind;
	ret->argv = argv;

	// No if(){}, because hpcalc gets killed if something's wrong with the arguments
	checkargs(ret);
}

void checkargs(struct getopt_return *stats)
{
	int i = stats->i;
	int calctype = stats->calctype;
	char datatype = stats->datatype;
	int argc = stats->argc;
	int optind = stats->optind;
	char **argv = stats->argv;

	if ( i == 0 )
		error_exit("No arguments passed! Type '-h' for help\n");

	if ( datatype == 0 )
		error_exit("No data type specified! Type '-h' for help\n");

	if ( calctype == 32767 )
		error_exit("No calc mode specified! Type '-h' for help\n");

	if ( datatype == 'f' && calctype == 5 )
		error_exit("Modulo not possible with float numbers! Type '-h' for help\n");

	if ( argc - optind < 2 ) // Has to be performed before the next if because else hpcalc gets a SIGSEGV if one or two argv values don't exist
		error_exit("Not enough numbers specified! Type '-h' for help\n");

	argv[optind] = changeCommaToPoint(argv[optind]); // Turn , into . so the following check only has to check the .
	argv[optind+1] = changeCommaToPoint(argv[optind+1]);

	if ( datatype == 'i' && ( contains(argv[optind],'.')  || contains(argv[optind+1],'.') ) ) 
		// If any given number contains a decimal point or comma, print an error
		error_exit("Decimal point in integer argument!\n");

	if ( (datatype == 'f' && calctype == 4) && contains(argv[optind+1],'.') )
		error_exit("Sorry, but there's a decimal point in the exponent - impossible with GnuMP\n");
	
	if ( datatype == 'f' && calctype == 7 )
		error_exit("ceiling division impossible with floats!\n");

	if ( (datatype == 'f') && (calctype == 6) )
		error_exit("GCD impossible when using float! Type '-h' for help\n");

	
	// If everything's OK, dispatch with the jump tables
	dispatch(datatype,calctype,argv);
}	

int dispatch(char datatype, int calctype, char **argv)
{

	// Jump table for integer routines. See description in headers/header_main.h
	int (*int_funcs[8])(char *astr, char *bstr) = { int_addition, int_subtraction, int_multiplication, int_fdivision, int_pow, int_remainder, int_gcd, int_cdivision };

	// Jump table for float routines. See description in headers/header_main.h
	int (*float_funcs[5])(char *astr, char *bstr, unsigned int prec) = { float_addition, float_subtraction, float_multiplication, float_division, float_pow };

	// Dispatcher with jumptable
	if ( datatype == 'i' )
	{
		(*int_funcs[calctype])(argv[optind],argv[optind+1]);
	} else if ( datatype == 'f' )
	{
		(*float_funcs[calctype])(argv[optind],argv[optind+1],precision);
	}

	return 0;
}
