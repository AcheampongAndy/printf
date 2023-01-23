#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @s: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int print_from_to(char *s, char *stop, char *except)
{
	int total = 0;

	while (s <= stop)
	{
		if (s != except)
			total += _putchar(*s);
		s++;
	}
	return (total);
}

/**
 * print_rev - prints string in reverse
 * @arg: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list arg, params_t *params)
{
	int len, total = 0;
	char *str = va_arg(arg, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			total += _putchar(*str);
	}
	return (total);
}

/**
 * print_rot13 - prints string in rot13
 * @arg: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list arg, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(arg, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
