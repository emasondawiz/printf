#include "main.h"
/**
 * conversion - function function
 * @myaps: Input value
 * @diff: Input value
 * @base: Input value
 * @ii: Input value
 * Return: Always 0
 */

int conversion(va_list myaps, int diff, int base, int *ii)
{
	int i, j, counter = 0;
	unsigned int temp, div, mod = 0;
	char *arr;

	unsigned int n = va_arg(myaps, unsigned int);

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
