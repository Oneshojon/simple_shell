
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

	if (argv == NULL || *argv == NULL)
		return (0);
	envp = get_environment_array();
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("./hsh");
		return (1);
	}
	if (child_pid == 0)
	{
		if (argv[0][0] != '/')
			path = find_executable(argv[0]);
		if (path == NULL)
			path = argv[0];
		if (execve(path, argv, envp) == -1)
		{
			perror("./hsh");
			free_environment_array(argv), free_environment_array(envp);
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
	return (status);
}
