#include "shell.h"
/**
 *env_main - stat example
 *@ac: count of arguments
 *@av: array of pointers to arguments
 *
 *Return: Always 0.
 */
int env_main(int ac, char **av)
{
	unsigned int i;
	struct stat st;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		printf("%s:", av[i]);
		if (stat(av[i], &st) == 0)
		{
			printf(" FOUND\n");
		}
		else
		{
			printf(" NOT FOUND\n");
		}
		i++;
	}
	return (0);
}
/**
 *find_executable - checks if a file exists
 *@filename: File to be checked
 *
 *Return: pointer to the path
 */
char *find_executable(const char *filename)
{
	struct stat st;
	char *path_env = getenv("PATH"),  *executable_path, *path, *token;

	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set\n");
		exit(EXIT_FAILURE);
	}
	path = strdup(path_env);
	if (path == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		executable_path = malloc(PATH_MAX);
		if (executable_path == NULL)
		{
			perror("malloc");
			free(path);
			exit(EXIT_FAILURE);
		}
		snprintf(executable_path, PATH_MAX, "%s/%s", token, filename);
		if (stat(executable_path, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode &
					S_IXUSR))
			return (executable_path);
		free(executable_path);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
/**
 *main - Entry point for the ealier program
 *@argc: count of argument
 *@argv: Array to pointers to arguments
 *
 *Return: 0
 */
int file_exists(int argc, char *argv[])
{
	int i;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	for (i = 1; i < argc; i++)
	{
		char *executable_path = find_executable(argv[i]);

		if (executable_path)
		{
			printf("%s\n", executable_path);
			free(executable_path);
		}
		else
		{
			printf("%s not found in PATH\n", argv[i]);
		}
	}
	return (EXIT_SUCCESS);
}
