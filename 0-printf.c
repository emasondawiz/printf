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

	if (format == NULL)
		format = "(null)";
	length = strlen(format);

	va_start(myaps, format);
	for (i = 0; i < length; i++)
	{
		if (format[i] != '%')
			counter = counter + allinchar(format[i], 0, myaps, &i);
		else if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				counter = counter + allinchar('c', 1, myaps, &i);
			else if (format[i + 1] == 's')
				counter = counter + allinchar('s', 2, myaps, &i);
			else if (format[i + 1] == '%')
				counter = counter + allinchar('%', 3, myaps, &i);
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				counter = counter + lengthcheck(myaps, 0, &i);
			else
				counter = counter + allinchar(format[i + 1], 4, myaps, &i);
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
 * allinchar - Function that kills space
 *  @c: Input value
 *  @diff: Input value
 *  @myaps: Input value
 * @i: Input value
 * Return: Always zero
*/
int allinchar(char c, int diff, va_list myaps, int *i)
{
	if (diff == 0)
	{
		_putchar(c);
		return (1);
	}
	else if (diff == 1)
	{
		*i = *i + 1;
		_putchar(va_arg(myaps, int));
		return (1);
	}
	else if (diff == 2)
	{
		int j, len;
		char *str;

		*i = *i + 1;
		str = va_arg(myaps, char *);
		if (str == NULL)
			str = "(null)";
		len = strlen(str);
		for (j = 0; j < len; j++)
			_putchar(str[j]);
		return (len);
	}
	else if (diff == 3)
	{
		*i = *i + 1;
		_putchar(c);
		return (1);
	}
	else if (diff == 4)
	{
		_putchar('%');
		_putchar(c);
		*i = *i + 1;
		return (2);
	}
	else
		return (0);
}





/**
 * lengthcheck - length of function
 * @myaps: input value
 * @count: input value
 * @z: input value
 * Return: Always 0
 */

int lengthcheck(va_list myaps, int count, int *z)
{
	int n, calc, newcal = 0, holder = 0, fixs = 0, num;
	int exp = 1, i, a;

	num = va_arg(myaps, int);

	if (num < 0)
	{
		_putchar('-');
		fixs = 1;
		num = -(num);
	}
	calc = num;
	n = num;
	count = count + 1;
	while (n / 10 != 0)
	{
		count++;
		n /= 10;
	}
	for (a = 0; a < count; a++)
	{
		for (i = a + 1; i < count; i++)
		{
			exp = exp * 10;
		}
		holder = calc / exp;
		newcal = calc - (holder * exp);
		calc = newcal;
		_putchar(holder + '0');
		exp = 1;
	}
	*z = *z + 1;
	return (fixs + count);
}
