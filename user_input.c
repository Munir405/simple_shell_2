#include "shell.h"
/**
 * recieve_input - Function use in reading user's input
 * @command: The user's input
 * @size: The size of the input
 * Return: void
 */

void recieve_input(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			ken_display("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			ken_display("Error.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
