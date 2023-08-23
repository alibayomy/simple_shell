#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * prompt - Function that print a prompt on standart output.
 *
 * Return: Void.
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("$ ");
	}
}
