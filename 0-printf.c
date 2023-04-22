#include "main.h"
#include "_putchar.c"
/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: nothing
 */

int _printf(const char *format, ...)
{
	int i, j, length, lenstr;
	va_list myaps;
	char *mystr = "";

	length = strlen(format);

	va_start(myaps, format);

	for (i = 0; i < length; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else if(format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				_putchar(va_arg(myaps, int));
				i++;
			}
			else if(format[i + 1] == 's')
			{
				mystr = va_arg(myaps, char *);

				lenstr =strlen(mystr);
                for (j = 0; j < lenstr; j++){
                    _putchar(mystr[j]);
                }
                i++;

            }else{
                _putchar(format[i]);
            }
}

