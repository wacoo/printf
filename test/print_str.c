#include "main.h"
/**
 * print_str - prints string and character
 * @c: flag
 * @st: string or char given
 *
 * Return: count of chers
 *
 */
int print_str(char *st, int count)
{
	while (*st != '\0')
	{
		_putchar(*st);
		st++;
		count += 1;
	}
	return (count);
}
