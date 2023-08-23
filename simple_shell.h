#ifndef _SIMPLE_SHELL_H_
#define _SIMPLE_SHELL_H_

#define ARGS_SIZE 4096
#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
extern char **environ;

void prompt(void);

int tokenize_input(char *input, char *args[]);

void execute_command(const char *cmd, char *args[]);

void simple_shell(void);

int search_execute(const char *cmd, char *args[]);

char  *get_path(char *name);

void print_env(char **env);

#endif
