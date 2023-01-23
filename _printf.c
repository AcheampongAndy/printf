#include "main.h"
/**
 * print_op - function to check which specifier to print
 * @format: string being passed
 * @print_arr: array of struct opts
 * @list: list of arguments to print
 * Return: numb of char to be printed
 */
int print_opt(const char *format, fmt_t *array, va_list arg)
{
	char a;
	int count = 0, b = 0, c = 0;

	a = format[b];
	while (a != '\0')
	{
		if (a == '%')
		{
			c = 0;
			b++;
			a = format[b];
			while (array[c].type != NULL &&
			       a != *(array[c].type))
				c++;
			if (array[c].type != NULL)
				count = count + array[c].f(arg);
			else
			{
				if (a == '\0')
					return (-1);
				if (a != '%')
					count += _putchar('%');
				count += _putchar(a);
			}
		}
		else
			count += _putchar(a);
		b++;
		a = format[b];
	}
	return (count);
}

/**
 * _printf - prints output according to format
 * @format: string being passed
 * Return: char to be printed
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int a = 0;

	fmt_t ops[] = {
		{"c", ch},
		{"s", str},
		{"d", _int},
		{"b", _bin},
		{"i", _int},
		{"u", _ui},
		{"o", _oct},
		{"x", _hex_l},
		{"X", _hex_u},
		{"R", _rot13},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	a = print_opt(format, ops, arg);
	va_end(arg);
	return (a);
}
