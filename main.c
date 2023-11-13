#include "shell.h"

int main()
{
	char *input, **argv;
	int count = 0, i;

	display_prompt();
	while (1)
	{
		input = read_line();
		if (input == NULL)
		{
			display_prompt();
			continue;
		}
		argv = split_string(input, " ", &count);

		if (argv == NULL || count == 0)
		{
			free(input);
			continue;
		}
		execute(argv);
		free(input);
		for (i = 0; i < count; i++)
		{
			free(argv[i]);
		}
		free(argv);
		display_prompt();
	}
	return (EXIT_SUCCESS);
}
