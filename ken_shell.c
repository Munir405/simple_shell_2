#include "shell.h"

/**
 * main - Program starting point
 * @ac: argument count
 * @av: argument vector
 * Return: success always 0
 */

int main(int ac __attribute__((unused)), char **av)
{
	int exec_stat = 0;
	char *read_lines;
	char **read_token;

	while (1)
	{
		read_lines = recieve_input();
		if (read_lines == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (exec_stat);
		}
		read_token = tknz_cmdL_args(read_lines);
		if (!read_token)
			continue;
		exec_stat = exec_cmd(read_token, av);
	}
}
