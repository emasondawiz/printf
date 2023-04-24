#ifndef PRINTF_PROJECT
#define PRINTF_PROJECT
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
void lengthcheck(int num, int count, int *counter);
int allinchar(char c, int diff, va_list myaps, int *i);
#endif
