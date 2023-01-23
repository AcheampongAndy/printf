#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct fmt - function to check for formats
 * @type: The format to print
 * @f: The print function to use
 */
typedef struct fmt
{
	char *type;
	int (*f)();
} fmt_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_opt(const char *format, fmt_t *array, va_list arg);
int _strlen(char *string);
int _bin(va_list bin);
int cha(va_list charac);
int _hex_str(unsigned int n, unsigned int hex, char alpha);
int _hex_u(va_list hexa);
int _hex_l(va_list hexa);
int _int(va_list integ);
int _oct(va_list octo);
int _rot13(va_list rot);
int str(va_list string);
int _ui(va_list unsign);

#endif
