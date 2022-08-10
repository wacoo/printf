#include "main.h"
#include <string.h>
#include <stdio.h>
/**
 * strev - reverse string
 * @str: string
 *
 */

void strev(char *str)
{
	int len = strlen(str);
	int i;

	for (i = 0; i < len / 2; i++)
	{
		char temp = str[i];

		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

/**
 * valla - returns char version of numbers
 * @num: number
 * @hex: letter case
 *
 * Return: int
 */
int valla(int num, char hex)
{
	if (hex == 'X')
	{
		if (num >= 0 && num <= 9)
			return ((char)(num + '0'));
		else
			return ((char)(num - 10 + 'A'));
	}
	else
	{
		if (num >= 0 && num <= 9)
			return ((char)(num + '0'));
		else
			return ((char)(num - 10 + 'a'));
	}
}
/**
 * fromdecimal - Function to convert a given decimal
 * number to a base 'base' and
 * @res: destination pointer
 * @base: base
 * @inputNum: given number to be printed
 * @hex: flag for the type of hex or not x for a-f, X for A-F,any for the rest
 *
 */
void fromdecimal(char *res, int base, uintptr_t inputNum, char hex)
{
	int index = 0;

	while (inputNum > 0)
	{
		res[index++] = valla(inputNum % base, hex);
		inputNum /= base;
	}
	res[index] = '\0';
	strev(res);
}

/**
 * print_num - prints numbers pf different base
 * @num: number
 * @base: base
 * @hex: type of numbering
 */
void print_num(unsigned int num, int base, char hex)
{
	int j;
	char xx[100];

	fromdecimal(xx, base, num, hex);
	j = 0;
	while (xx[j] != '\0')
	{
		_putchar(xx[j]);
		j++;
	}
}
/**
 * print_p - prints numbers pf different base
 * @num: number
 * @base: base
 * @hex: type of numbering
 *
 */

void print_p(uintptr_t num, int base, char hex)
{
	int j;
	char xx[100];

	fromdecimal(xx, base, num, hex);
	j = 0;
	_putchar('0');
	_putchar('x');
	while (xx[j] != '\0')
	{
		_putchar(xx[j]);
		j++;
	}

}
