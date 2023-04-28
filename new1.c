#include "main.h"

/**
 * intcount_1 - counts the length of an integer
 * @input: the integer
 * @base: the divisor
 * Return: success
*/

int intcount_1(long int input, int base)
{
	long int temp, counter;

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
 * funwithplus_1 - function that does + conversion
 * @id: Input value
 * @num: Input value
 * @b: input value
 * Return: Success
 */
int funwithplus_1(va_list myaps, int *id, char b)
{
	int counter = 0;

	if (b == 'i' || b == 'd' || b == 'u')
	{
		long int num = va_arg(myaps, long int);

		if (num < 0)
		{
			num = -(num);
			if (b != 'u')
			{
				_putchar('-');
				counter = counter + 1;
			}
		}
		counter = counter + fun2(num);
	}
	*id = *id + 2;
	return (counter);
}

/**
 * assistfunc_1 - assist function
 * @num: Input value
 * @b: Input
 * Return: Success
 */

int assistfunc_1(int num, char b)
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
 * fun2 - assist function
 * @num - input value
 * Return - Success
 */

int fun2(long int num)
{
	long int j, i, exp = 1, bloop = 0, holder = 0, calc, newcal = 0;

	calc = num;

	bloop = intcount_1(num, 10);
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
