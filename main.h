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
int my_rot13(va_list myaps, int *ii);
int my_rev(va_list myaps, int *ii);
int intcount(int input, int base);
int funwithplus(int num, int *id, char c, char b);
int assistfunc(int num, char b);
int intcount_1(long int input, int base);
int funwithplus_1(va_list myaps, int *id, char b);
int fun_2(long int num);
int conversion_1(long int n, int diff, int base, int *ii);
int fun_3(unsigned long int num);
int intcount_2(unsigned long int input, int base);
int assistfunc_1(long int num, char b);
#endif
