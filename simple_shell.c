#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include "simple_shell.h"

/**
 * simple_shell - my main simple_shell program to execute command programs
 * @argv: argv from the main.
 */
void simple_shell(char *argv[])
{
	char input[4096], *newline, *args[512];
	int argc, status = 0, i = 0;
	size_t length;

	while (1)
	{
		prompt();
		if (fgets(input, sizeof(input), stdin) != NULL)
		{
			length = strlen(input);
			while (length > 0 && (input[length - 1] == '\n' || input[length - 1] == ' '
			|| input[length - 1] == '\t' || (isspace(input[length - 1]))))
			{
				input[--length] = '\0';
			}
			newline = input;
			while (newline[i] == '\0' && (isspace(newline[i]) || newline[i] == '\t'))
				newline++;
			if (newline[i] == '\0')
				continue;
			if (strcmp(input, "env") == 0)
			{
				print_env(environ);
				continue;
			}
			argc = tokenize_input(input, args), args[argc] = NULL;
			if (strcmp(args[0], "exit") == 0 && args[1] == NULL)
				exit(status);
			status = exit_status(args, argc, argv);
			if (status != 0)
				exit(status);
			if (!search_execute(args[0], args, argc, argv))
			{
				status = _fork(args, argc, argv, status);
			}
		}
		else
			exit(status);
	}
}
