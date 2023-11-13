#include "shell.h"

/**
 *extern_vs_main - compare extern environment to main environment
 *@ac: count of arguments
 *@av: array of pointers to args
 *@env: array of envirnments
 *
 *Return: 0
 */
int extern_vs_main(int ac, char **av, char **env)
{
	char **envx = environ;
	(void)ac, (void)av;

	if (envx == env)
		printf("They point to the same adress\n");
	else
		printf("Tehy point to different addree\n");

	return (0);
}
/**
 *extern_env - prints the encironnment using global variable
 *
 *Return: 0
 */
int extern_env(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
	return (0);
}
/**
 *_getenv - Gets the value of the environmental variable name
 *@name: Variable ehose value is to be found
 *
 *Return: Pointer to the variable and value or NULL is not found
 */
char *_getenv(const char *name)
{
	size_t name_len;
	char **env;

	if (name == NULL || environ == NULL)
		return (NULL);
	name_len = strlen(name);
	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
			return (*env + name_len + 1);
	}
	return (NULL);
}
/**
 *dir_in_path - Prints each directory contained in the environment
 *		variable PATH one directry per line
 *Return: nothing
 */
void dir_in_path(void)
{
	char *arr, *token;

	arr = _getenv("PATH");

	token = strtok(arr, ":");
	while (token != NULL)
	{
		printf("%s\n", token);

		token = strtok(NULL, ":");
	}
}
