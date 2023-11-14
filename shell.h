#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;
void ken_display(const char*);
void show_prompt(void);
int exec_cmd(char **init_cmd, char **av);
char *recieve_input(void);
size_t _strlen(const char *str);
char *_strdup(const char *);
char **tknz_cmdL_args(char *input_cmd);
void _free(char **ar);

#endif
