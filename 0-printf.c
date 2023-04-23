#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: nothing
 */

int _printf(const char *format, ...)
{
	int i, length;

	va_list myaps;

	char *mystr = "";

	length = strlen(format);

	va_start(myaps, format);
	for (i = 0; i < length; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
		}
		else
		{
			if (format[i + 1] == 'c')
			{
				i++;
				putchar(va_arg(myaps, int));
			}
			else if (format[i + 1] == 's')
			{
				i++;
				mystr = va_arg(myaps, char *);
				printf("%s", mystr);
			}
			else if (format[i + 1] == '%')
			{
				putchar(format[i]);
				i++;
			}
			else
			{
				putchar(format[i]);
				i++;
				putchar('%');
			}
		}
	}
	va_end(myaps);
	return (i);
}
