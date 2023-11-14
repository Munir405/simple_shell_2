#include "shell.h"


/**
 * _free - a function that checks free an array strings.
 * @ar: the array of strings to be freed.
 * Return: success always (1).
 */

void _free(char **ar)
{
	int i;

	if (!ar)
		return;
	for (i = 0; ar[i]; i++)
	{
		free(ar[i]);
		ar[i] = NULL;
	}
	free(ar[i]), ar = NULL;
}

/**
 * exec_cmd - an executable that execute commands
 * in the the directories specified in PATH.
 * @init_cmd: The command to execute.
 * @av: Array of arguments for the command.
 * Return: the status.
 */

int exec_cmd(char **init_cmd, char **av)
{
	pid_t little_pid;
	int stat;

	little_pid = fork();
	if (little_pid == 0)
	{
		if (execve(init_cmd[0], init_cmd, environ) == -1)
		{
			perror(av[0]);
			_free(init_cmd);
		}
	}
	else
	{
		waitpid(little_pid, &stat, 0);
		_free(init_cmd);
	}
	return (WEXITSTATUS(stat));
}
