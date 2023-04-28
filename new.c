#include "main.h"

/**
 * intcount - counts the length of an integer
 * @input: the integer
 * @base: the divisor
 * Return: success
*/

int intcount(int input, int base)
{
	int temp, counter;

	if (input < 0)
		input = -(input);
	temp = input;
	counter = 0;

	while (temp / base != 0)
	{
		temp /= base;
		counter = counter + 1;
	}
	counter = counter + 1;
	return (counter);
}
/**
 * funwithplus - function that does + conversion
 * @id: Input value
 * @num: Input value
 * @c: Input value
 * @b: input value
 * Return: Success
 */
int funwithplus(int num, int *id, char c, char b)
{
	int counter = 0, j, i, exp = 1, bloop = 0, holder = 0, calc, newcal = 0;

	if (c == ' ')
	{
		if (b != 'i' && b != 'd')
		{
			_putchar('%');
			_putchar(' ');
			counter = counter + 2;
			*id = *id + 2;
			return (counter);
		}
		if (num >= 0)
			_putchar(' ');
		else
		{
			_putchar('-');
			num = -(num);
		}
	}
	else if (c == '#')
	{
		counter = counter + assistfunc(num, b);
		*id = *id + 2;
		return (counter);
	}
	else
	{
		if (num >= 0)
			_putchar('+');
		else
		{
			_putchar('-');
			num = -(num);
		}
	}
	calc = num;
	bloop = intcount(num, 10);
	for (i = 0; i < bloop; i++)
	{
		for (j = i + 1; j < bloop; j++)
			exp = exp * 10;
		holder = calc / exp;
		newcal = calc - (holder * exp);
		calc = newcal;
		_putchar(holder + '0');
		exp = 1;
	}
	*id = *id + 2;
	return (counter + 1 + bloop);
}

/**
 * assistfunc - assist function
 * @num: Input value
 * @b: Input
 * Return: Success
 */

int assistfunc(int num, char b)
{
	int count = 0, gh = 0;

	if (num ==  0)
	{
		_putchar('0');
		return (1);
	}
	if (num < 0)
		num = -(num);
	if (b == 'x')
	{
		_putchar('0');
		_putchar('x');
		count = count + 2;
		count = count + conversion(num, 0, 16, &gh);
	}
	else if (b == 'X')
	{
		_putchar('0');
		_putchar('X');
		count = count + 2;
		count = count + conversion(num, 1, 16, &gh);
	}
	else
	{
		count = count + conversion(num, 0, 8, &gh);
	}
	return (count);
}

/**
 * fun_3 - assist function
 * @num: input value
 * Return: Success
 */

int fun_3(unsigned long int num)
{
	unsigned long int j, i, exp = 1, bloop = 0, holder = 0, calc, newcal = 0;

	calc = num;

	bloop = intcount_2(num, 10);
	for (i = 0; i < bloop; i++)
	{
		for (j = i + 1; j < bloop; j++)
			exp = exp * 10;
		holder = calc / exp;
		newcal = calc - (holder * exp);
		calc = newcal;
		_putchar(holder + '0');
		exp = 1;
	}
	return (bloop);
}

/**
 * intcount_2 - counts the length of an integer
 * @input: the integer
 * @base: the divisor
 * Return: success
*/

int intcount_2(unsigned long int input, int base)
{
	unsigned long int temp, counter;

	temp = input;
	counter = 0;

	while (temp / base != 0)
	{
		temp /= base;
		counter = counter + 1;
	}
	counter = counter + 1;
	return (counter);
}
