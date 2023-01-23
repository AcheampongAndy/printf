#include "main.h"

/**
 * _strlen - gets string length
 * @string: string
 * Return: length (int)
 */

int _strlen(char *string)
{
	int length;

	for (length = 0; string[length] != '\0'; length++)
	{
		;
	}
	return (length);
}
