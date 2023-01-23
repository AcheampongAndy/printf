#include "main.h"

/**
 * _bin - function to print binary
 * @bin: list being passed
 * Return: updated count return
 */
int _bin(va_list bin)
{
	int count = 0, i;
	int *array;
	unsigned int x = va_arg(bin, unsigned int);
	unsigned int tmp = x;

	while (x / 2 != 0)
	{
		x /= 2;
		count++;
	}
	count++;
	array = malloc(count * sizeof(int));
	if (array == NULL)
	{
		free(array);
		return (0);
	}
	for (i = 0; i < count; i++)
	{
		array[i] = tmp % 2;
		tmp /= 2;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(array[i] + '0');
	}
	free(array);
	return (count);
}
