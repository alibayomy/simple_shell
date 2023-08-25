#include "simple_shell.h"
/**
 * isNumber - check for numbers in a string
 * @number: the given string
 * Return: 0 if string is number, else 1
 */

int isNumber(char *number)
{
	int i = 0, negative_flag = 0;

	/*checking for negative numbers*/
	if (number[0] == '-')
	{
		i = 1;
		negative_flag = 1;
	}
	for (; number[i] != 0; i++)
	{
		if (!isdigit(number[i]))
		{
			return (1);
		}
	}
	if (negative_flag == 1)
	{
		return (1);
	}

	return (0);
}
