#include "main.h"

/**
 * print_char - prints character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list arg, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, total = 0, ch = va_arg(arg, int);

	if (params->minus_flag)
		total += _putchar(ch);
	while (pad++ < params->width)
		total += _putchar(pad_char);
	if (!params->minus_flag)
		total += _putchar(ch);
	return (total);
}

/**
 * print_int - prints integer
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list arg, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(arg, long);
	else if (params->h_modifier)
		l = (short int)va_arg(arg, int);
	else
		l = (int)va_arg(arg, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list arg, params_t *params)
{
	char *str = va_arg(arg, char *), pad_char = ' ';
	unsigned int pad = 0, total = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				total += _putchar(*str++);
		else
			total += _puts(str);
	}
	while (j++ < params->width)
		total += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				total += _putchar(*str++);
		else
			total += _puts(str);
	}
	return (total);
}

/**
 * print_percent - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list arg, params_t *params)
{
	(void)arg;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list arg, params_t *params)
{
	char *str = va_arg(arg, char *);
	char *hex;
	int total = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			total += _putchar('\\');
			total += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				total += _putchar('0');
			total += _puts(hex);
		}
		else
		{
			total += _putchar(*str);
		}
	}
	return (total);
}
