#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>

void ken_display(const char *title);
void show_prompt(void);
void operations_execute(const char *command);
void recieve_input(char *command, size_t size);

#endif
