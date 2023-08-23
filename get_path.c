#include <stdio.h>
#include <string.h>
#include "simple_shell.h"
#include <stdlib.h>
/**
 * get_path - return the path dirs
 * @name: the name of the env Variable
 *
 * Return: a pointer to the full PATH value string, NULL if not found
*/
char *get_path(char *name)
{
	size_t buffer_len = strlen(name);
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, buffer_len) == 0
			&& environ[i][buffer_len] == '=')
		{
			return (environ[i] + buffer_len + 1);
		}
	}

	return (NULL);
}
