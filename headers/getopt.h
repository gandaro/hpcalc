extern struct getopt_return *getopts (int argc, char *argv[]);
extern int checkargs (struct getopt_return *stats);
extern int dispatch (char datatype, int calctype, char **argv);

struct getopt_return 
{
	char **argv;
	int calctype;
	int argc;
	int optind;
	short i;
	char datatype;
};

