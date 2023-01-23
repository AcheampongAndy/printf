#include "main.h"

/**
 * _int - function to print integers
 * @integ: list printed
 * Return: Return count
 */
int _int(va_list integ)
{
	int x, expo = 1, size = 0;
	unsigned int n;

	x = va_arg(integ, int);

	if (x < 0)
	{
		size +=  _putchar('-');
		n = x * -1;
	}
	else
		n = x;
	while (n / expo > 9)
		expo *= 10;

	while (expo != 0)
	{
		size = size + _putchar(n / expo + '0');
		n = n % expo;
		expo = expo / 10;
	}
	return (size);
}
