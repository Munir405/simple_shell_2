#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * get_input - Collects users
 * @prompt: Enable a user to enter inputs
 * @buffer: Inputs storage
 * @buffer_size: buffer size
 */
void get_input(char *prompt, char *buffer, int buffer_size)
{
	write(STDOUT_FILENO, prompt, buffer_size - 1);
	int store = read(STDIN_FILENO, buffer, buffer_size - 1);

	if (store <= 0)
		perror("Error, can't read input");
		exit(1);

	buffer[store - 1] = '\0';
}

/**
 * display_name - Showing the formatted name
 * @first_name: User first name
 * @last_name: User last name
 */
void display_name(char *first_name, char *last_name)
{
	char display[100];
	int total_length = 0;
	int b;

	for (b = 0; first_name[b] != '\0'; b++)
		display[total_length++] = first_name[b];

	display[total_length++] = ' ';

	for (b = 0; last_name[b] != '\0'; b++)
		display[total_length++] = last_name[b];

	display[total_length++] = '\n';

	int store = write(STDOUT_FILENO, display, total_length);

	if (store <= 0)
		perror("Error writing display");
		exit(1);
}

/**
 * main - This is where the program start
 *
 * Return: 0 for success
 */
int main(void)
{
	char first_name[40];
	char last_name[40];

	get_input("Type your first name: ", first_name, sizeof(first_name));
	get_input("Type your last name: ", last_name, sizeof(last_name));

	display_name(first_name, last_name);

	return (0);
}
