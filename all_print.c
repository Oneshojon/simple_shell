#include "shell.h"

/**
 *_putchar - prints a single character to thr stdout
 *@c: The character to be printed
 */
void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

/**
 *_puts - prints a string to the stdout
 *@ptr: Pointer to the string
 */
void _puts(char *ptr)
{
	size_t len;
	ssize_t writtenByte;

	len = _strlen(ptr);
	writtenByte = write(STDOUT_FILENO, ptr, len);
	if (writtenByte == -1)
	{
		perror("write");
	}
}
/**
 *printError - writes error message to the stderr
 *@ptr: pointer to the string
 */
void printError(char *ptr)
{
	size_t len;
	ssize_t writtenByte;

	len = _strlen(ptr) + 1;
	writtenByte = write(STDERR_FILENO, ptr, len);
	if (writtenByte == -1)
	{
		perror("write");
	}
}
