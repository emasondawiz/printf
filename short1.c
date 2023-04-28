#include "main.h"

/**
 * fun_5 - assist function
 * @num: input value
 * Return: Success
 */

int fun_5(unsigned short int num)
{
	unsigned short int j, i, exp = 1, bloop = 0, holder = 0, calc, newcal = 0;

	calc = num;

	bloop = intcount_4(num, 10);
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
 * intcount_4 - counts the length of an integer
 * @input: the integer
 * @base: the divisor
 * Return: success
*/

int intcount_4(unsigned short int input, int base)
{
	unsigned short int temp, counter;

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
 * assistfunc_2 - assist function
 * @num: Input value
 * @b: Input
 * Return: Success
 */

int assistfunc_2(long int num, char b)
{
	long int count = 0;
	int gh = 0;

	if (num ==  0)
	{
		_putchar('0');
		return (1);
	}
	if (num < 0)
		num = -(num);
	if (b == 'x')
	{
		count = count + conversion_2(num, 0, 16, &gh);
	}
	else if (b == 'X')
	{
		count = count + conversion_2(num, 1, 16, &gh);
	}
	else
	{
		count = count + conversion_2(num, 0, 8, &gh);
	}
	return (count);
}



