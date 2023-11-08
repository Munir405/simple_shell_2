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
 * _strcmp - this function compare between two strings
 * @str1: first string
 * @str2: second string
 * Return: success always(1)
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * _strdup - this function duplicate a string
 * @str: the argument to duplicate
 * Return: pointer to the newly allocated mem
 * success always(1)
 */

char *_strdup(const char *str)
{
	size_t i, len;
	char *copy;

	len = _strlen(str);
	copy = (char *)malloc(len + 1);

	if (copy)
	{
		for (i = 0; i <= len; i++)
		{
			copy[i] = str[i];
		}
	}
	return (copy);
}

/**
 * remove_newline - a function that removes newline
 * @str: argument to be checked through for possible
 * newline character
 * Return: success always (1)
 */

void remove_newline(char *str)
{
	char *check_newline;

	check_newline = strchr(str, '\n');
	if (check_newline)
	{
		*check_newline = '\0';
	}
}
