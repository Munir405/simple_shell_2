#include "shell.h"

/**
 * operations_execute - functions for executing commands
 * @command: the commands enterred
 */

void operations_execute(const char *command)
{
	char *args[100];
	char *tokenize, *delim;
	char *envp[] = { NULL };
	int i;
	pid_t minor_pid;

	delim = " \t\n";

       	minor_pid = fork();

	if (minor_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (minor_pid == 0)
	{
		i = 0;
		tokenize = strtok((char *)command, delim);
		while (tokenize != NULL)
		{
			args[i] = tokenize;
			tokenize = strtok(NULL, delim);
			i++;
		}
		args[i] = NULL;

		execve(args[0], args, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
