#include "shell.h"

/**
 * recieve_input - Function use in reading user's input
 * @void - no argument pass.
 * Return: void
 */

char *recieve_input(void)
{
	char *read_input = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
		show_prompt();
	read = getline(&read_input, &len, stdin);
	if (read == -1)
	{
		free(read_input);
		return (NULL);
	}
	return (read_input);
}
