#include "main.h"

/**
 * cha - function to return char
 * @character: list given
 * Return: number of char printed
 */
int cha(va_list charac)
{
	return (_putchar(va_arg(charac, int)));
}
