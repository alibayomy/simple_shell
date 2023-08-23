#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * simple_shell - my main simple_shell program to execute command programs
 */
void simple_shell(void)
{
	char input[9046], *newline, *args[20];
	int argc, pid, flag = 0, i;

	while (1)
	{
		prompt();
		if (fgets(input, sizeof(input), stdin) != NULL)
		{
			for (i = 0; input[i] != '\n'; i++)
			{
				if (input[i] != ' ')
					flag++;
			}
			if (flag == 0)
				continue;
			newline = strchr(input, '\n');
			if (newline != NULL)
				*newline = '\0';
			if (strcmp(input, "env") == 0)
			{
				print_env(environ);
				continue;
			}
			if (strcmp(input, "exit") == 0)
				break;
			argc = tokenize_input(input, args), args[argc] = NULL;
			if (!search_execute(args[0], args))
			{
				pid = fork();
				if (pid == 0)
					if (execve(args[0], args, environ) == -1)
						perror(args[0]), exit(2);
				wait(NULL);
			}
		}
		else
			exit(0);
	}
}
