#include "main.h"
/**
 * conversion - function function
 * @n: Input value
 * @diff: Input value
 * @base: Input value
 * @ii: Input value
 * Return: Always 0
 */

int conversion(unsigned int n, int diff, int base, int *ii)
{
	int i, j, counter = 0;
	unsigned int temp, div, mod = 0;
	char *arr;

	temp = n, div = n;

	while (temp > 0)
	{
		temp /= base;
		counter += 1;
	}
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
/**
 * special_string - Special function
 * @i: Input value
 * @myaps: Input valur
 * Return: Counters
 */

int special_string(va_list myaps, int *i)
{
	char *str;
	int a, len, key = 0, demo = 0;

	str = va_arg(myaps, char *);

	if (str == NULL)
	{
		str = "(null)";
	}

	len = strlen(str);

	for (a = 0; a < len; a++)
	{
		if (str[a] < 32 || str[a] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (str[a] < 16)
			{
				demo = demo + 1;
				_putchar('0');
			}
			demo = demo + conversion(str[a], 1, 16, &key);
		}
		else
		{
			_putchar(str[a]);
		}
	}
	*i = *i + 1;
	return (len + demo + 2);
}


/**
 * hex_lower - function that uses full hexadecimal lowercase.
 * @nums: Input value
 * @base: Base to 16
 * Return: always success
 */
int hex_lower(unsigned long int nums, int base)
{
	unsigned int *arr;
	long int i;
	unsigned long int temp = nums;
	unsigned int count = 0;

	while (nums / base != 0)
	{
		nums /= base;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(long int));

	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 16;
		temp /= base;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 39;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}

/**
 * special_address - function that print address.
 * @args: input value
 * @ii: Input value
 * Return: Count
 */
int special_address(va_list args, int *ii)
{
	void *z;
	char *y = "(nil)";
	long int a;
	int b;
	int i;

	z = va_arg(args, void*);


	if (z == NULL)
	{
		for (i = 0; y[i] != '\0'; i++)
		{
			_putchar(y[i]);
		}
		return (i);
	}

	a = (unsigned long int)z;
	_putchar('0');
	_putchar('x');
	b = hex_lower(a, 16);
	*ii = *ii + 1;
	return (b + 2);
}
/**
 * my_mixers - Fun with plus, space and pounds
 * @gg: Input value
 * @mynum: Input value
 * Return: always success
 */

int my_mixers(int mynum, int *gg)
{
	int calc, n, count = 0, ld = 0, exp = 1, holder = 0, newcal = 0, i, width;

	width = 5;

	if (mynum < 0)
	{
		mynum = -(mynum);
		_putchar('-');
	}
	else
		_putchar(' ');
	calc = mynum;
	n = mynum;
	count = count + 1;
	while (n / 10 != 0)
	{
		count++;
		n /= 10;
	}
	ld = width - count;
	if (ld <= 1)
	{
		mix_helper(holder, calc, newcal, exp, count);
	}
	else
	{
		ld = ld - 1;
		for (i = 0; i < ld; i++)
			_putchar('#');
		mix_helper(holder, calc, newcal, exp, count);
	}
	*gg = *gg + 1;
	return (count + 1);
}
