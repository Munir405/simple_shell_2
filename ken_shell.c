#include "shell.h"
/**
 * show_prompt - Display the shell prompt
 */
void show_prompt(void)
{
	ken_display("kenny_shell$ ");
}
/**
 * main - Program starting point
 *
 * Return: 0
 */
int main(void)
{
	char *command[100];

	while (true)
	{
		show_prompt();
<<<<<<< HEAD
		recieve_input(command, sizeof(command));
=======
		recieve_input(*command, sizeof(*command));
		operations_execute(*command);
>>>>>>> 305ecbaa9dcb958757e271c3f3159bc7c40422e5
	}
	return (0);
}
