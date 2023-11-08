#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <ctype.h>

void ken_display(const char*);
void show_prompt(void);
void operations_execute(char *);
void recieve_input(char *cmd, int size);
size_t _strlen(const char*);
char *_strdup(const char*);
int _strcmp(const char*, const char*);
void remove_newline(char *);

#endif
