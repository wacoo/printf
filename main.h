#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int _printf(const char *format, ...);
int print_str(char *st, int count);
int print_chr(char ar, int count);
void print_num(int num, int base, char hex);
void print_int(int no);
void fromDecimal(char *res, int base, unsigned int inputNum, char hex);

#endif
