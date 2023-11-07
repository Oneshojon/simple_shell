#include "shell.h"

/**
 *exec_program - Executes aa program
 *
 *Return: 0 on success
 */
int exec_program(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	printf("Before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
		perror("Error");
	printf("After execve\n");
	return (0);
}
/**
 *create_process - Creates a new child process
 *
 *Return: 0
 */
int create_process(void)
{
	pid_t my_pid, pid;

	printf("Before fork\n");
	printf("pid is: %u\n", getpid());
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	printf("After fork\n");
	my_pid = getpid();
	printf("My pid is: %u\n", my_pid);
	return (0);
}
/**
 *child_father_pid - Differentiates child pid from parent pid
 *
 *Return: 0
 */
int child_father_pid(void)
{
	pid_t my_pid, child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	my_pid = getpid();
	printf("My pid is: %u\n", my_pid);
	if (child_pid == 0)
		printf("(%u) Nooooooo!\n", my_pid);
	else
		printf("(%u) %u, I am your father\n", my_pid, child_pid);
	return (0);
}
/**
 *wait_father - suspends execution of parent process untill
 *		Child process completes
 *Return: 0
 */
int wait_father(void)
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
		printf("Wait for me, wait for me\n");
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("Oh, it's all better now\n");
	}
	return (0);
}
/**
 *exec_5x - Executes commnad "ls -l /tmp" in 5 different child
 *		Processes created by the same father
 *
 *Return: 0
 */
int exec_5x(void)
{
	int i = 0, status;
	pid_t child_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};


	while (i < 5)
	{
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
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
		i++;
	}
	return (0);
}
