#include "simple_shell.h"
/**
 * print_env - print the env of the program
 * @env: the environment of the program
*/
void print_env(char **env)
{
int  i = 0, len = 0;
char *new_line = "\n";

while (env[i] != NULL)
{
while (env[i][len] != '\0')
len++;

write(1, env[i], len);
len = 0;
i++;
write(1, new_line, 2);
}
}
