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
 *
 * Return: 0 if success, -1 if failed.
 */
void execute_command(const char *cmd, char *args[])
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
		execve(cmd, args, environ); /*i added the enviorn*/
		perror("execve"); /* This line is executed only if execve fails */
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
