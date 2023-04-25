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
				demo = 1;
				_putchar('0');
			}
			conversion(str[a], 1, 16, &key);
		}
		else
		{
			_putchar(str[a]);
		}
	}

	*i = *i + 1;
	return (len + 3 + demo);
}