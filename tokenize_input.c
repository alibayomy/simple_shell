#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * tokenize_input - Tokenize the buffer (user input line)
 * to smaller strings (tokens).
 * @input: User input as one line (befor tokenize).
 * @args: Array of Tokens (smaller strings) from user input line.
 *
 * Return: Length of tokens array if success, 1 if failed.
 */
int tokenize_input(char *input, char *args[])
{
	int argc;
	char *token;

	argc = 0;
	token = strtok(input, " ");
	while (token != NULL && argc < 19)
	{
		args[argc++] = token;
		token = strtok(NULL, " ");
	}

	return (argc);
}
