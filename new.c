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
 * Return: Success
 */
int funwithplus(int num, int *id, char c)
{
	int counter = 0, j, i, exp = 1, bloop = 0, holder = 0, calc, newcal = 0;

	if (c == ' ')
	{
		if (num >= 0)
			_putchar(' ');
		else
		{
			_putchar('-');
			num = -(num);
		}
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
