#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: nothing
 */

int _printf(const char *format, ...)
{
	int i, length, counter = 0;
	va_list myaps;
	char *mystr = "";

	length = strlen(format);
	va_start(myaps, format);
	for (i = 0; i < length; i++)
	{
		if (format[i] != '%')
		{
			counter = counter + 1;
			_putchar(format[i]);
		}
		else if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				counter = counter + 1;
				_putchar(va_arg(myaps, int));
				i++;
			}
			else if (format[i + 1] == 's')
			{
				mystr = va_arg(myaps, char *);
				myfunction(mystr, 0, &counter);
				i++;
			} else if (format[i + 1] == '%')
				myfunc2(format[i], &i, &counter);
			else
			{
				myfunc2(format[i], &i, &counter);
				_putchar('%');
			}
		}
	}
	va_end(myaps);
	return (counter);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * myfunction - Function that kills space
 *  @str: Input value
 *  @j: Input value
 *  @counter: Input value
*/
void myfunction(char *str, int j, int *counter)
{
	int p;

	if (str == NULL)
	{
		str = "(null)";
	}

	p = strlen(str);
	for (j = 0; j < p; j++)
	{
		_putchar(str[j]);
		*counter = *counter + 1;
	}
}

/**
 * myfunc2 - Function that kills space
 * @i: Input value
 * @counter: Input
 * @str: Input value
 */

void myfunc2(char str, int *i, int *counter)
{
	*counter = *counter + 1;
	_putchar(str);
	*i = *i + 1;
}
