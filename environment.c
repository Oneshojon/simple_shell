#include "shell.h"

/**
 *main_env - Prints the environment
 *@ac: count of arguments
 *@av: array of pointers to args
 *@env: array of envirnments
 *
 *Return: 0
 */
int main(int ac, char **av, char **env)
{
	unsigned int i = 0;

	while (env[i] != 0)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
