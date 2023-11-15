#include <stdio.h>
#include <unistd.h>
#include <string.h>
/**
 * main - Program starting point
 * Return: 0 if successful
 */
int main(void)
{
	char first_name[40];
	char last_name[40];
	char display[100];
	int store;
	int first_lastname = 0;
	int b;

	write(STDOUT_FILENO, "Type your first name: ", 23);
	store = read(STDIN_FILENO, first_name, sizeof(first_name) - 1);
	if (store <= 0)
	{
		perror("Error, can't read name");
		return (1);
	}
	first_name[store - 1] = '\0';
	write(STDOUT_FILENO, "Type your last name: ", 22);
	store = read(STDIN_FILENO, last_name, sizeof(last_name) - 1);
	if (store <= 0)
	{
		perror("Error can't read input");
		return (1);
	}
	last_name[store - 1] = '\0';
	for (b = 0; first_name[b] != '\0'; b++)
	{
		display[first_lastname++] = first_name[b];
	}
	display[first_lastname++] = ' ';
	for (b = 0; last_name[b] != '\0'; b++)
	{
		display[first_lastname++] = last_name[b];
	}
	display[first_lastname++] = '\n';
	store = write(STDOUT_FILENO, display, first_lastname);
	if (store <= 0)
	{
		perror("Error writing display");
		return (1);
	}
	return (0);
}
