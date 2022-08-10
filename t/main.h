#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <inttypes.h>
int _putchar(char c);
int _printf(const char *format, ...);
int print_str(char *st, int count);
int print_chr(char ar, int count);
void print_num(unsigned int num, int base, char hex);
void print_int(int no);
void fromDecimal(char *res, int base, uintptr_t inputNum, char hex);
void print_p(uintptr_t num, int base, char hex);

typedef struct variables var;
/**
 * struct variables - holds global variables
 * @count: count of chars printed
 * @tmpa: temporary pinter to an argument string
 * @tmp: temorary var for char argument
 * @ap: argument list declaration
 */

struct variables
{
	int count;
	char *tmpa;
	char tmp;
	va_list ap;
};
#endif
