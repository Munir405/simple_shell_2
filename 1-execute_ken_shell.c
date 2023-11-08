#include "shell.h"
/**
 * operations_execute - functions for executing commands
 * @command: the commands enterred
 */
void operations_execute(char *command)
{
	char *delim = " \t", *token, *cmd, *av[100];
	char *envp[] = {"PATH=/bin", NULL};
	pid_t minor_pid = fork();
	int i = 0, status;

	token = strtok(command, delim);
	cmd = token;
	while (token != NULL)
	{
		av[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	av[i] = NULL;
	if (cmd != NULL)
	{
		if (minor_pid == -1)
			exit(EXIT_FAILURE);
		else if (minor_pid == 0)
		{
			if (execve(cmd, av, envp) == -1)
			{
				perror(cmd);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (waitpid(minor_pid, &status, 0) == -1)
				perror(cmd);
		}
	}
}
