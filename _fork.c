#include "simple_shell.h"

/**
 * _fork - continue executing the remaining arguments
 * @args: the array of the given arguments
 * @argc: the number of the given arguments
 * @argv: the argument of the given main function
 * @status: the status of the program
 * Return: the status of the program
 * @
*/
int _fork(char *args[], int argc, char *argv[], int status)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, environ);
		fprintf(stderr, "%s: %d: %s: not found\n", argv[0], argc, args[0]);
		status = 2;
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
		status = WEXITSTATUS(status);
	}
	return (status);
}
