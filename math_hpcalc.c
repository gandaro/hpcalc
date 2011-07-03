# include <stdio.h>
# include <stdlib.h>
# include <gmp.h>
# include "headers/math_hpcalc.h"

int int_addition(char *astr, char *bstr)
{
	mpz_t a,b,sol;
	
	mpz_init_set_str(a,astr,10);
	mpz_init_set_str(b,bstr,10);
	mpz_init(sol);

	mpz_add(sol,a,b);

	gmp_printf("%Zd\n",sol);

	return 0;
}

int int_subtraction(char *astr, char *bstr)
{
	mpz_t a,b,sol;

	mpz_init_set_str(a,astr,10);
	mpz_init_set_str(b,bstr,10);
	mpz_init(sol);

	mpz_sub(sol,a,b);

	gmp_printf("%Zd\n",sol);

	return 0;
}

int int_multiplication(char *astr, char *bstr)
{
	mpz_t a,b,sol;

	mpz_init_set_str(a,astr,10);
	mpz_init_set_str(b,bstr,10);
	mpz_init(sol);

	mpz_mul(sol,a,b);

	gmp_printf("%Zd\n",sol);

	return 0;
}

int int_fdivision(char *astr, char *bstr)
{
	mpz_t a,b,sol;

	mpz_init_set_str(a,astr,10);
	mpz_init_set_str(b,bstr,10);
	mpz_init(sol);

	mpz_fdiv_q(sol,a,b);

	gmp_printf("%Zd\n",sol);

	return 0;
}

int int_cdivision(char *astr, char *bstr)
{
	mpz_t a,b,sol;

	mpz_init_set_str(a,astr,10);
	mpz_init_set_str(b,bstr,10);
	mpz_init(sol);

	mpz_cdiv_q(sol,a,b);

	gmp_printf("%Zd\n",sol);

	return 0;
}

int int_remainder(char *astr, char *bstr)
{
	mpz_t a,b,sol;

	mpz_init_set_str(a,astr,10);
	mpz_init_set_str(b,bstr,10);
	mpz_init(sol);

	mpz_fdiv_r(sol,a,b);

	gmp_printf("%Zd\n",sol);

	return 0;
}

int int_pow(char *astr, char *bstr)
{
	mpz_t a,sol;

	mpz_init_set_str(a,astr,10);
	unsigned long int exp = strtoul(bstr,NULL,10);
	mpz_init(sol);

	mpz_pow_ui(sol,a,exp);

	gmp_printf("%Zd\n",sol);

	return 0;
}

int int_gcd(char *astr, char *bstr)
{
	mpz_t a,b,sol;
	
	mpz_init_set_str(a,astr,10);
	mpz_init_set_str(b,bstr,10);
	mpz_init(sol);

	mpz_gcd(sol,a,b);

	gmp_printf("%Zd\n",sol);

	return 0;
}

////////////////////////////////////////////////////


int float_addition(char *astr, char *bstr, unsigned int prec)
{
	mpf_t a,b,sol;
	mpf_init2(a,prec);
	mpf_init2(b,prec);
	mpf_init2(sol,prec);

	mpf_set_str(a,astr,10);
	mpf_set_str(b,bstr,10);

	mpf_add(sol,a,b);
	
	gmp_printf("%.Ff\n",sol);

	return 0;
}

int float_subtraction(char *astr, char *bstr, unsigned int prec)
{
	mpf_t a,b,sol;
	mpf_init2(a,prec);
	mpf_init2(b,prec);
	mpf_init2(sol,prec);

	mpf_set_str(a,astr,10);
	mpf_set_str(b,bstr,10);

	mpf_sub(sol,a,b);

	gmp_printf("%.Ff\n",sol);
	return 0;
}

int float_multiplication(char *astr, char *bstr, unsigned int prec)
{
	mpf_t a,b,sol;
	mpf_init2(a,prec);
	mpf_init2(b,prec);
	mpf_init2(sol,prec);

	mpf_set_str(a,astr,10);
	mpf_set_str(b,bstr,10);

	mpf_mul(sol,a,b);

	gmp_printf("%.Ff\n",sol);
	return 0;
}

int float_division(char *astr, char *bstr, unsigned int prec)
{
	mpf_t a,b,sol;
	mpf_init2(a,prec);
	mpf_init2(b,prec);
	mpf_init2(sol,prec);

	mpf_set_str(a,astr,10);
	mpf_set_str(b,bstr,10);

	mpf_div(sol,a,b);

	gmp_printf("%.Ff\n",sol);

	return 0;
}

int float_pow(char *astr, char *bstr, unsigned int prec)
{
	mpf_t a,sol;
	unsigned long int exp = strtoul(bstr,NULL,10);
	
	mpf_init2(a,prec);
	mpf_init2(sol,prec);
	
	mpf_set_str(a,astr,10);

	mpf_pow_ui(sol,a,exp);

	gmp_printf("%.Ff\n",sol);

	return 0;
}

