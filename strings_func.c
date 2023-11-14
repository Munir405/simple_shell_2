#include "shell.h"

/**
 * _strlen - determine the length of a string.
 * @str: the argument to check its length
 * Return: length as success
 */

size_t _strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strdup - this function duplicate a string
 * @str: the argument to duplicate
 * Return: pointer to the newly allocated mem
 * success always(1)
 */

char *_strdup(const char *str)
{
	int len = 0;
	char *dup;

	if (!str)
		return (NULL);
	while (*str++)
	{
		len++;
	}
	dup = malloc(sizeof(char *) * (len + 1));
	if (!dup)
		return (NULL);
	for (len++; len--;)
		dup[len] = *--str;
	return (dup);
}
