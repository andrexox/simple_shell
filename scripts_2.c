#include "shell.h"
/**
 * _strcat - concatenate two strings (dest + src)
 * @dest: pointer to string to concatenate
 * @src: initial string
 *
 * Return: the final string to dest
 */
char *_strcat(char *dest, char *src)
{
	unsigned int len1 = 0, len2 = 0, i = 0;
	char *final_str = NULL;

	if (dest)
	len1 = _strlen(dest);
	if (src)
		len2 = _strlen(src);

	final_str = malloc(sizeof(char) * (len1 + len2 + 1));

	for (i = 0; i < len1; i++)
		final_str[i] = dest[i];
	for (; i < len1 + len2; i++)
		final_str[i] = src[i - len1];

	final_str[i] = '\0';
	return (final_str);
}
