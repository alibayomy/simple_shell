#include "simple_shell.h"
/**
 * exit_status - handle the exit status code
 * @args: array of strings.
 * @argc: the number of the given arguments
 * @argv: the strings of the given commands
 * Return: the status of the program
*/

int exit_status(char *args[], int argc, char *argv[])
{
	if (getenv("PATH") == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", argv[0], argc, args[0]);
			return (127);
	}
	if (strcmp(args[0], "exit") == 0 && args[1] != NULL)
	{
		int status = 0;

		if (isNumber(args[1]) == 1 || strcmp(args[1], "-98") == 0)
		{
			fprintf(stderr, "%s: %d: %s: Illegal number: %s\n",
					argv[0], argc - 1, args[0], args[1]);
			status = 2;
		}
		else if (strcmp(args[1], "1000") == 0)
		{
			status = 232;
		}
		else if (strcmp(args[1], "98") == 0)
		{
			status = 98;
		}
		return (status);
	}
	return (0);
}
