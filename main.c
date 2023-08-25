#include <stdio.h>
#include "simple_shell.h"

/**
 * main - Start point of program.
 *
 * Return: 0 if success, 1 if failed.
 * @argc: number of the given arguments
 * @argv: 2d array of the given argumetns
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	simple_shell(argv);
	return (0);
}
