#include <unistd.h>

/**
 * _putchar - prints characters in a string one at a time
 * @c: the chatacter to be printed
 *
 * Return: success status int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
