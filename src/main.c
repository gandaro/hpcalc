# include "../headers/main.h"
# include "../headers/getopt.h"
# include "../headers/math_hpcalc.h"

int main(int argc, char *argv[])
{
	// Get the options and arguments and store them in a structure getopt_return (no malloc because only used locally)
	struct getopt_return *opt_struct = getopts(argc,argv);

	// No if construct because the program gets killed if something's wrong with the arguments
	checkargs(opt_struct);

	dispatch(opt_struct->datatype, opt_struct->calctype,argv);

	return(0);
}

