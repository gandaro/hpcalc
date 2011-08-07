// Before the prototypes because of compiler warnings (struct is declared in prototype...)
struct getopt_return 
{
	char **argv;
	int calctype;
	int argc;
	int optind;
	short i;
	char datatype;
};

extern void getopts (int argc, char *argv[]);
extern void checkargs (struct getopt_return *stats);
extern int dispatch (char datatype, int calctype, char **argv);


