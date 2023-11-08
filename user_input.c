#include "shell.h"
/**
 * recieve_input - Function use in reading user's input
 * @command: The user's input
 * @size: The size of the input
 * Return: void
 */

void recieve_input(char *command, int size)
{
	fgets(command, size, stdin);
	remove_newline(command);
	operations_execute(command);
}
