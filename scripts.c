#include "shell.h"

/**
 * _strlen - Returns length of a string
 * @string: Pointer to string
 *
 * Return: Length of string
 */
int _strlen(char *string)
{
	int index;

	index = 0;
	while (string[index] != '\0')
	{
		index++;
	}
	return (index);
}
