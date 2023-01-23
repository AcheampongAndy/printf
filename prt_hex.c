#include "main.h"

/**
 * _hex_str - converts the number from base 10 to hex
 * @n: number to be converted
 * @hex: base of 16 being passed
 * @alpha: Char 'A' to 'F' or 'a' to 'f'
 * Return: number of chars printed
 */
int _hex_str(unsigned int n, unsigned int hex, char alpha)
{
	unsigned int x = n % hex;
	unsigned int y = n / hex;
	char z;

	if (x > 10)
		z = (x - 10) + alpha;
	else
		z = x + '0';
	if (y == 0)
	{
		return (_putchar(z));
	}
	if (y < hex)
	{
		if (y > 10)
			return (_putchar(y - 10 + alpha) + _putchar(z));
		return (_putchar(y + '0') + _putchar(z));
	}
	return (_hex_str(y, hex, alpha) + _putchar(z));
}

/**
 * _hex_l - printing lower case hexa
 * @hexa: argument recieved
 * Return: no of char printed
 */
int _hex_l(va_list hexa)
{
	return (_hex_str(va_arg(hexa, unsigned int), 16, 'a'));
}

/**
 * _hex_u - printing upper case hexa
 * @hexa: argument recieved
 * Return: no. of char printed
 */
int _hex_u(va_list hexa)
{
	return (_hex_str(va_arg(hexa, unsigned int), 16, 'A'));
}
