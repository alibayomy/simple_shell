#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * execute_command - Search for a command in argv array,
 * concatenate the full path for that command and execute it.
 * @cmd: Command entered by the user.
 * @args: array of strings.
 * @argc: the number of the given arguments
 * @argv: the strings of the given commands
 * Return: 0 if success, -1 if failed.
 */
void execute_command(const char *cmd, char *args[], int argc, char *argv[])
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(cmd, args, environ);
		fprintf(stderr, "%s: %d: %s: not found\n", argv[0], argc, args[0]);
		exit(127);
	}
	else
	{
		int status = 0;

		waitpid(pid, &status, 0);
	}
}
