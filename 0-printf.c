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
			else if (format[i + 1] == 'u')
				counter = counter + my_unsigned_int(myaps, 0, &i);
			else if (format[i + 1] == 'o')
				counter = counter + conversion(va_arg(myaps, unsigned int), 0, 8, &i);
			else if (format[i + 1] == 'X')
				counter = counter + conversion(va_arg(myaps, unsigned int), 1, 16, &i);
			else if (format[i + 1] == 'b')
				counter = counter + conversion(va_arg(myaps, unsigned int), 0, 2, &i);
			else if (format[i + 1] == 'x')
				counter = counter + conversion(va_arg(myaps, unsigned int), 0, 16, &i);
			else if (format[i + 1] == 'S')
				counter = counter + special_string(myaps, &i);
			else if (format[i + 1] == 'p')
				counter = counter + special_address(myaps, &i);
			else if (format[i + 1] == '+' || format[i + 1] == ' ')
				counter = counter + funwithplus(va_arg(myaps, int), &i, format[i + 1]);
			else if (format[i + 1] == 'R')
				counter = counter + my_rot13(myaps, &i);
			else if (format[i + 1] == 'r')
				counter = counter + my_rev(myaps, &i);
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

	while (n / 10 != 0)
	{
		count++;
		n /= 10;
	}
	count = count + 1;
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
/**
 * my_unsigned_int - unsigned function
 * @myaps: input value
 * @count: input value
 * @z: input value
 * Return: 0
 */
int my_unsigned_int(va_list myaps, int count, int *z)
{
	int exp = 1, i, a;
	unsigned int calc, holder = 0, newcal = 0, n;

	unsigned int num = va_arg(myaps, unsigned int);

	calc = num;
	n = num;

	while (n / 10 != 0)
	{
		count++;
		n /= 10;
	}
	count = count + 1;
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
	return (count);
}
