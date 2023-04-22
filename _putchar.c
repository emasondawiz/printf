#include <unistd.h>

/**
 * _putchar - putchar function
 * @c: Input value
 * Return: Always success
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
