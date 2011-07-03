# define ACC 8192 // default accuracy for GMP in Bit

// Integer routines
extern int int_addition(char *astr, char *bstr);
extern int int_subtraction(char *astr, char *bstr);
extern int int_multiplication(char *astr, char *bstr);
extern int int_fdivision(char *astr, char *bstr);
extern int int_cdivision(char *astr, char *bstr);
extern int int_remainder(char *astr, char *bstr);
extern int int_pow(char *astr, char *bstr);
extern int int_gcd(char *astr, char *bstr);
// Floatpoint routines
extern int float_addition(char *astr, char *bstr, unsigned int prec);
extern int float_subtraction(char *astr, char *bstr, unsigned int prec);
extern int float_multiplication(char *astr, char *bstr, unsigned int prec);
extern int float_division(char *astr, char *bstr, unsigned int prec);
extern int float_pow(char *astr, char *bstr, unsigned int prec);
