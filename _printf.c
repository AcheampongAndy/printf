#include "main.h"

/**
 * _printf - prints and input into the standard output
 * @format: the format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)

{
	int total = 0;
	va_list arg;
	char *a, *s;

	params_t params = PARAMS_INIT;

	va_start(arg, format);

	/* checking for NULL char */
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (a = (char *)format; *a; a++)
	{
		init_params(&params, arg);
		if (*a != '%')
		{
			total += _putchar(*a);
			continue;
		}
		s = a;
		a++;
		while (get_flag(a, &params))
		{
			a++;
		}
		a = get_width(a, &params, arg);
		a = get_precision(a, &params, arg);
		if (get_modifier(a, &params))
			a++;
		if (!get_specifier(a))
			total += print_from_to(s, a,
					params.l_modifier || params.h_modifier ? a - 1 : 0);
		else
			total += get_print_func(a, arg, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(arg);
	return (total);
}
