#include "main.h"

/**
 * intcount_3 - counts the length of an integer
 * @input: the integer
 * @base: the divisor
 * Return: success
*/

int intcount_3(short int input, int base)
{
	short int temp, counter;

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
 * funwithplus_2 - function that does + conversion
 * @id: Input value
 * @myaps: Input value
 * @b: input value
 * Return: Success
 */
int funwithplus_2(va_list myaps, int *id, char b)
{
	int counter = 0;

	if (b == 'i' || b == 'd')
	{
		short int num = va_arg(myaps, int);

		if (num < 0)
		{
			num = -(num);
			_putchar('-');
			counter = counter + 1;
		}
		counter = counter + fun_4(num);
	}
	else if (b == 'x' || b == 'X' || b == 'o')
	{
		short int num = va_arg(myaps, int);

		counter = counter + assistfunc_3(num, b);
	}
	else if (b == 'u')
	{
		unsigned short int num = va_arg(myaps, unsigned int);

		counter = counter + fun_5(num);
	}
	*id = *id + 2;
	return (counter);
}

/**
 * assistfunc_3 - assist function
 * @num: Input value
 * @b: Input
 * Return: Success
 */

int assistfunc_3(short int num, char b)
{
	short int count = 0;
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
/**
 * fun_4 - assist function
 * @num: input value
 * Return: Success
 */

int fun_4(short int num)
{
	short int j, i, exp = 1, bloop = 0, holder = 0, calc, newcal = 0;

	calc = num;

	bloop = intcount_3(num, 10);
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
 * conversion_2 - function function
 * @n: Input value
 * @diff: Input value
 * @base: Input value
 * @ii: Input value
 * Return: Always 0
 */

int conversion_2(short int n, int diff, int base, int *ii)
{
	short int i, j, counter = 0;
	short int temp, div, mod = 0;
	char *arr;

	temp = n, div = n;

	while (temp / base > 0)
	{
		temp /= base;
		counter += 1;
	}
	counter = counter + 1;
	arr = (char *)malloc(counter * sizeof(char));
	for (i = 0; i < counter; i++)
	{
		mod = div % base;
		if (base == 16 && mod < 10 && diff == 1)
			*(arr + i) = mod + 48;
		else if (base == 16 && mod > 9 && diff == 1)
			*(arr + i) = mod + 55;
		else if (base == 16 && mod < 10 && diff == 0)
			*(arr + i) = mod + 48;
		else if (base == 16 && mod > 9 && diff == 0)
			*(arr + i) = mod + 87;
		else
			*(arr + i) = mod;
		div = div / base;
	}
	for (j = i - 1; j >= 0; j--)
	{
		if (base == 16)
			_putchar(*(arr + j));
		else
			_putchar(*(arr + j) + '0');
	}
	*ii = *ii + 1;
	free(arr);
	return (counter);
}
