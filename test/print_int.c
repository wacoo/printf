#include "main.h"
#include <stdio.h>
/**
 * print_int - prints integers
 * @no: integer
 * @x: destination pointer
 *
 */
void print_int(int no)
{
	int i, nflag = 0;
	char x[100];
	i = 0;
	if (no < 0)
	{
		no *= -1;
		nflag = 1;
	}
	while (no > 0)
	{
		x[i] = no % 10;
		no /= 10;
		i++;
	}
	i--;
	if (nflag)
	{
		_putchar('-');
	}
	while (i >= 0)
	{
		_putchar(x[i] + '0');
		i--;
	}
    
}
