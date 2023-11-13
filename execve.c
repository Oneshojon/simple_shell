#include "shell.h"

/**
 *execute - suspends execution of parent process untill
 *		Child process completes
 *Return: 0
 */
int execute(char *argv[])
{
	pid_t child_pid;
	int status = 0;
	char *envp[2], *path_dir = _getenv("PATH");

	if (argv == NULL || *argv == NULL)
		return (0);
	child_pid = fork();
	if (child_pid == -1)
	{
		perror(argv[0]);
		return (1);
	}
	if (child_pid == 0)
	{ 
		envp[0] = path_dir, envp[1] = NULL;
		if (execve(argv[0], argv, envp) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
		{
			waitpid(child_pid, &status, WUNTRACED);
		}
	}
	return (1);
}
