#include "shell.h"
/**
 *main - Entry point for major programss
 *
 *Return: Status
 */
int main(void)
{
	char *input, **argv;

	/*display_prompt();*/
	while (1)
	{
		input = read_line();
		if (!input || !*input)
			break;
		argv = split_string(input, " \t\n\a\r");

		if (argv == NULL || !*argv)
		{
			free(input);
			free_environment_array(argv);
			continue;
		}
		execute(argv);
		free(input);
		free_environment_array(argv);
	}
	return (EXIT_SUCCESS);
}
