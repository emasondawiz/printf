#include "main.h"

/**
* mix_helper - as a support function to my_mixers function
* @holder: Input value
* @calc: Input value
* @newcal: Input value
* @e: Input value
* @c: Input value
*/

void mix_helper(int holder, int calc, int newcal, int e, int c)
{
	int a, i;

	for (a = 0; a < c; a++)
	{
		for (i = a + 1; i < c; i++)
			e = e * 10;
		holder = calc / e;
		newcal = calc - (holder * e);
		calc = newcal;
		_putchar(holder + '0');
		e = 1;
	}
}

/**
 * my_rot13 - function of rot13
 * @myaps: input value
 * @ii: input value
 * Return: always success
 */
int my_rot13(va_list myaps, int *ii)
{
	int i, j, count = 0;
	int z1 = 0;
	char *str = va_arg(myaps, char*);
	char up[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char lo[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		z1 = 0;
		for (j = 0; up[j] && !z1; j++)
		{
			if (str[i] == up[j])
			{
				_putchar(lo[j]);
				count++;
				z1 = 1;
			}
		}
		if (!z1)
		{
			_putchar(str[i]);
			count++;
		}
	}
	*ii = *ii + 1;
	return (count);
}

/**
 * my_rev - Function reverse
 * @myaps: value input
 * @ii: Input value
 *Return: always success
 */
int my_rev(va_list myaps, int *ii)
{

	char *str = va_arg(myaps, char*);
	int i;
	int j = 0;

	if (str == NULL)
		str = "(null)";
	while (str[j] != '\0')
		j++;
	for (i = j - 1; i >= 0; i--)
		_putchar(str[i]);
	*ii = *ii + 1;
	return (j);
}
