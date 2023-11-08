#include "shell.h"

int main()
{
	char *input;
	int count = 0;

	while (1)
	{
		input = read_line();
		if (input == NULL)
			break;
		char **argv = split_string(input, " ", &count);
		if (argv == NULL || count == 0)
		{
			free(input);
			continue;
		}
		execute(argv);
		free(input);
		for (size_t i = 0; i < count; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
	return (0);
}
