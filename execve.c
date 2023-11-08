#include "shell.h"

/**
 *execute - suspends execution of parent process untill
 *		Child process completes
 *Return: 0
 */
int execute(char *argv[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (child_pid == 0)
	{ 
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
