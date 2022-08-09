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
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}
/**
 * valSM - returns char version of numbers
 * @num: number
 *
 */
int valSM(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'a');
}
/**
 * nalLA - returns char version of numbers
 * @num: number
 *
 */
int valLA(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
/**
 * fromDecimal - Function to convert a given decimal number
 * to a base 'base' and
 * @res: destination pointer
 * @base: base
 * @inputNum: given number to be printed
 * @hex: flag for the type of hex or not x for a-f, X for A-F, any for the rest
 *
 */
void fromDecimal(char *res, int base, unsigned int inputNum, char hex)
{
    int index = 0;
    while (inputNum > 0)
    {
        if (hex == 'X')
            res[index++] = valLA(inputNum % base);
        else
              res[index++] = valSM(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';

    strev(res);
}

/**
 * print_num - prints numbers pf different base
 * @num: number
 * @base: base
 *
 */
void print_num(int num, int base, char hex)
{
	int j;
	char xx[100];
	fromDecimal(xx, base, num, hex);
	j = 0;
	while (xx[j] != '\0')
	{
		_putchar(xx[j]);
		j++;
	}
}

/**
 * print_uns - prints unsigned 
 * @num: given number
 * @base: number base
 *
 */
void print_uns(int num, int base)
{
        int j;
        char xx[100];
        if (num >= 0)
        {
		num *= -1;
                fromDecimal(xx, base, num, 'x');
        }
        j = 0;
	_putchar('-');
	j++;
        while (xx[j] != '\0')
        {
                _putchar(xx[j]);
                j++;
        }
}
