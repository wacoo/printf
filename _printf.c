#include "main.h"
#include <stdarg.h>
#include <string.h>


/**
 * _printf - prints formated text
 * @format: the format in which the text will be printed
 *
 * Return: the count of printed characters
 */
int _printf(const char *format, ...)
{
	int ln, i = 0, count = 0;
	char *tmpa, tmp, c;
	va_list ap;

	va_start(ap, format);
	ln = strlen(format);
	while (i < ln)
	{
		c = format[i + 1];
		if (format[i] == '%' && ln - 1 != i)
		{
			if (c == 'c')
			{
				tmp = va_arg(ap, int);
				count = print_chr(tmp, count);
				i++;
			}
			else if (c == 's')
			{
				tmpa = va_arg(ap, char *);
				count = print_str(tmpa, count);
				i++;
			}
			else if (c == 'd' || c == 'i')
			{
				int in = va_arg(ap, unsigned int);

				print_int(in);
				i++;
			}
			else if (c == 'u')
			{
				int in = va_arg(ap, unsigned int);

				print_num(in, 10, '0');
				i++;
			}
			else if (c == 'o')
				{
				int in = va_arg(ap, unsigned int);

				print_num(in, 8, '0');
				i++;
			}
			else if (c == 'x')
			{
				int in = va_arg(ap, unsigned int);

				print_num(in, 16, 'x');
				i++;
			}
			else if (c == 'X')
			{
				int in = va_arg(ap, unsigned int);

				print_num(in, 16, 'X');
				i++;
			}
			else if (c == 'p')
			{
				int in = va_arg(ap, unsigned int);

				print_num(in, 16, '0');
				i++;
			}
			else if (c == '%')
			{
				count = print_chr('%', count);
				i++;
			}
			else
			{
				count = print_chr(c, count);
				i++;
			}
		}
		else
		{
			count = print_chr(format[i], count);
		}
		i++;
	}
	return (count);
}
