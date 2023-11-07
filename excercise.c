#include "shell.h"

/**
 *get_ppid - finds the process ID of a parent process
 *
 */
void get_ppid(void)
{
	pid_t my_pid;

	my_pid = getppid();
	printf("The parent PID is : %u\n", my_pid);
}
