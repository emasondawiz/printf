#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: nothing
 */

int _printf(const char *format, ...)
{
	int i, j, lenstr,  length, counter = 0;
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
				lenstr = strlen(mystr);
				for (j = 0; j < lenstr; j++)
				{
					_putchar(mystr[j]);
					counter = counter + 1;
				}
				i++;
			}
			else if (format[i + 1] == '%')
			{
				counter = counter + 1;
				_putchar(format[i]);
				i++;
			}
			else
			{
				counter = counter + 1;
				_putchar(format[i]);
				i++;
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
 *  @len: Input value
 *  @j: Input value
 *  @counter: Input value
*/
void myfunction(char *str, int len, int j, int *counter)
{
	for (j = 0; j < len; j++)
	{
		_putchar(str[j]);
		*counter = *counter + 1;
	}
}
