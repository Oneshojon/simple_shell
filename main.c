#include "shell.h"
/**
 *main - Entry point for major programss
 *
 *Return: Status
 */
int main(void)
{
	char *line = NULL, **arr;
	size_t size = 0;
	ssize_t read;
	int status = EXIT_SUCCESS;

	/*display_prompt();*/
	while (1)
	{
		read = getline(&line, &size, stdin);
		if (read == -1)
		{
			if (feof(stdin))
			{
#ifdef PROMPT
				printf("\n");
#endif
				break;
			}
			else
			{
				perror("getline");
				break;
			}
		}
		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';
		arr = split_string(line, " \t\n\a\r");
		status = execute(arr);
		if (*arr == NULL)
			status = (EXIT_SUCCESS);
		else
		{
			free_environment_array(arr);
			if (status != 127)
				status = EXIT_SUCCESS;
		}
	}
	free(line);
	return (status);
}
