#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * search_execute - Search for a command in argv array,
 * concatenate the full path for that command and execute it.
 * @cmd: Command entered by the user.
 * @args: array of strings.
 * @argc: the number of the given arguments
 * @argv: the strings of the given commands
 *
 * Return: 0 if success, -1 if failed.
 */
int search_execute(const char *cmd, char *args[], int argc, char *argv[])
{
	char *path_env;
	char *path_env_copy;
	char *path;
	char full_path[4096];

	path_env = get_path("PATH");
	if (path_env == NULL)
		return (2);
	path_env_copy = strdup(path_env);
	if (path_env_copy != NULL)
	{
		path = strtok(path_env_copy, ":");

		while (path != NULL)
		{
			snprintf(full_path, sizeof(full_path), "%s/%s", path, cmd);

			if (access(full_path, X_OK) == 0)
			{
				execute_command(full_path, args, argc, argv);
				free(path_env_copy);
				return (1);
			}

			path = strtok(NULL, ":");
		}
		free(path_env_copy);
	}
	return (0);
}
