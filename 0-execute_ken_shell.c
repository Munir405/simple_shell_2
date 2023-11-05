#include "shell.h"

/**
 * operations_execute - functions for executing commands
 * @command: the commands enterred
 */

void operations_execute(const char *command)
{
	pid_t minor_pid = fork();

	if (minor_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (minor_pid == 0)
	{
		execlp(command, command, (char *)NULL);
		perror("exclp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
