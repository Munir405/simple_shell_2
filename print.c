#include "shell.h"
/**
 * ken_display - This is used to display an output
 * @title: The output
 * Return: void
 */

void ken_display(const char *title)
{
	write(STDOUT_FILENO, title, strlen(title));
}
