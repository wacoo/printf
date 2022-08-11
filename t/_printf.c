#include "main.h"
#include <string.h>
/**
 * print_c - print first part
 * @i: interator
 * @c: character
 * @vr: struct
 *
 * Return: iterator i
 */
int print_c(int i, char c, var *vr)
{
	char n[] = "(null)";
	char *d = &n[0];

	if (c == 'c')
	{
		vr->tmp = va_arg(vr->ap, int);
		if (vr->tmp != '\0')
			vr->count = print_chr(vr->tmp, vr->count);
		else
			print_str(n, vr->count);
		i++;
	}
	else if (c == 's')
	{
		vr->tmpa = va_arg(vr->ap, char *);
		 if (*(vr->tmpa) != '\0')
			vr->count = print_str(vr->tmpa, vr->count);
		 else
			 print_str(d, vr->count);
		i++;
	}
	else if (c == 'd' || c == 'i')
	{
		int in = va_arg(vr->ap, unsigned int);

		print_int(in);
		i++;
	}
	else if (c == 'u')
	{
		int in = va_arg(vr->ap, unsigned int);

		print_num(in, 10, '0');
		i++;
	}
	else if (c == 'o')
		{
		int in = va_arg(vr->ap, unsigned int);

		print_num(in, 8, '0');
		i++;
	}
	return (i);

}
/**
 * print_d - second part of printf
 * @i: iterator
 * @c: char
 * @vr: struct
 *
 * Return: i iterator
 *
 */
int print_d(int i, char c, var *vr)
{

	if (c == 'x')
	{
		int in = va_arg(vr->ap, unsigned int);
		
		print_num(in, 16, 'x');
		i++;
	}
	else if (c == 'X')
	{
		int in = va_arg(vr->ap, unsigned int);

		print_num(in, 16, 'X');
		i++;
	}
	else if (c == 'p')
	{
		uintptr_t in = va_arg(vr->ap, uintptr_t);

		print_p(in, 16, 'x');
		i++;
	}
	else if (c == '%')
	{
		vr->count = print_chr('%', vr->count);
		i++;
	}
	else
	{
		vr->count = print_chr(c, vr->count);
		i++;
	}
	return (i);
}
/**
 * _printf - prints formated text
 * @format: the format in which the text will be printed
 *
 * Return: the count of printed characters
 */
int _printf(const char *format, ...)
{
	int ln, i = 0;
	var v;
	var *vr = &v;

	vr->count = 0;
	va_start(vr->ap, format);
	ln = strlen(format);
	while (i < ln)
	{
		if (format == NULL)
		{
			return (vr-> count);
		}
		else if (format[i] == '%' && ln - 1 != i)
		{
			i = print_c(i, format[i + 1], vr);
			i = print_d(i, format[i + 1], vr);
		}
		else
		{
			vr->count = print_chr(format[i], vr->count);
		}
		i++;
	}
	_putchar('\n');
	return (vr->count);
}
