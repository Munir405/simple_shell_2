#include "shell.h"
/**
 * tknz_cmdL_args - function that tokenize atrings.
 * @input_cmd: the argument to be tokenize
 * Return: a pointer to strings
 */
char **tknz_cmdL_args(char *input_cmd)
{
	char *delim = " \t\n", *tokenize = NULL, *tmp = NULL, **copy_cmd;
	int i = 0, j = 0;

	if (!input_cmd)
		return (NULL);
	tmp = _strdup(input_cmd);
	tokenize = strtok(tmp, delim);
	if (tokenize == NULL)
	{
		free(input_cmd), input_cmd = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (tokenize)
	{
		i++;
		tokenize = strtok(NULL, delim);
	}
	copy_cmd = malloc(sizeof(char *) * (i + 1));
	if (copy_cmd == NULL)
	{
		free(input_cmd), input_cmd = NULL;
		return (NULL);
	}
	tokenize = strtok(input_cmd, delim);
	while (tokenize)
	{
		copy_cmd[j] = _strdup(tokenize);
		tokenize = strtok(NULL, delim);
		j++;
	}
	free(input_cmd);
	copy_cmd[j] = NULL;
	return (copy_cmd);
}
