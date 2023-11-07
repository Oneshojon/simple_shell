#include "shell.h"

/**
 *_getline - Reads files from a stream and copy content to a file
 *@n: Number of character to read
 *@stream: Strea to read from
 *Return: The number of characters retieved.
 */

ssize_t _getline(char **ptr, size_t n, FILE *stream)
{
	char *file_from;
	ssize_t count = 0, result= 0, len;

	file_from = read_file(stream);
	if (file_from == NULL)
		return (-1);

	if (ptr == NULL && n == 0)
	{
		len = strlen(file_from) - 1;
		*ptr = realloc(ptr, len * sizeof(char));
		if (*ptr == NULL)
			return (-1);
		while (result < len)
		{
			*ptr[result] = file_from[result];
			result++;
		}
		return (result);
	}
	else if (n > 0)
	{
		*ptr = malloc(n * sizeof(char));
		if (*ptr == NULL)
			return (-1);
		while (count < n)
		{
			*ptr[count] = file_from[count];
			count++;
		}
		return (count);
	}
	return (-1);
}
/**
 *read_file - Reads content from a strem and copy to a pointer
 *@stream: stream to read from
 *
 *Return: pointer to a string containing the file read
 */
char *read_file(FILE *stream)
{
	char buffer[1024], *file_to = "output.txt";	
	int fd;
	ssize_t bytesRead, bytesWritten;

	if (stream == NULL)
		return NULL;
	fd = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		bytesRead = read(fileno(stream), buffer, sizeof(buffer));
		if (bytesRead == -1)
		{
			close(fd);
			return (NULL);
		}
		else if (bytesRead == 0)
			break;
	}
	bytesWritten = write(fd, buffer, bytesRead);
	if (bytesWritten == -1)
	{
		close(fd);
		return (NULL);
	}


	if (close(fd) == -1)
		return (NULL);
	return (file_to);
}
