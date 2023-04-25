#ifndef PRINTF_PROJECT
#define PRINTF_PROJECT
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int lengthcheck(va_list myaps, int count, int *z);
int allinchar(char c, int diff, va_list myaps, int *i);
int my_unsigned_int(va_list myaps, int count, int *z);
int conversion(unsigned int n, int diff, int base, int *ii);
int special_string(va_list myaps, int *i);
int hex_lower(unsigned long int nums, int base);
int special_address(va_list args, int *ii);
int my_mixers(int mynum, int *gg);
void mix_helper(int holder, int calc, int newcal, int e, int c);
#endif
