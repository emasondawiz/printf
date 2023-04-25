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
