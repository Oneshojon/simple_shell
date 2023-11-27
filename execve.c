
#include "shell.h"
/**
 *execute - suspends execution of parent process untill
 *		Child process completes
 *@argv: pointer to array of arguments
 *Return: 0
 */
int execute(char *argv[])
{
	pid_t child_pid;
	int status = 0;
	char **envp, *path = NULL;

	path = check_executable(argv);
	if (path == NULL)
		return (127);
	envp = get_environment_array();
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("./hsh");
		free(path);
		return (127);
	}
	if (child_pid == 0)
	{
		if (execve(path, argv, envp) == -1)
		{
			perror("./hsh, rt");
			free(path), free_environment_array(envp);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
	do {
		waitpid(child_pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	free_environment_array(envp);
	}
	free(path);
	return (status);
}
/**
 *check_executable - Checks if executable file exists in environment
 *@argv: Array of arguments
 *
 *Return: Nothing
 */
char *check_executable(char **argv)
{
	char *path = NULL;

	if (argv == NULL || *argv == NULL)
		return (NULL);
	if (argv[0][0] != '/' && argv[0][0] != '.')
	{
		path = find_executable(argv[0]);
		if (path == NULL)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
			return (NULL);
		}
	}
	else if (argv[0][0] == '.' && (argv[0][3] == '.' || argv[0][3] == '/'))
	{
		path = find_executable(argv[0] + 3);
		if (path == NULL)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
			return (NULL);
		}
	}
	else
	{
		path = strdup(argv[0]);
		return (path);
	}
	return (path);
}
