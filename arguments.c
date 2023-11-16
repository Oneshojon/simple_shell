#include "shell.h"

/**
 *print_args - Prints all the arguments
 *@ac: The number of arguments passed
 *@av: An array of pointers to the arguments
 *
 *Return: 0 on success
 */
int print_args(int ac, char **av)
{
	int i = 1;
	char *arg;
	(void)ac;

	while (av[i])
	{
		arg = av[i];
		_puts(arg);
		_putchar('\n');
		i++;
	}
	return (0);
}

/**
 *read_line - Prints the arguments entered
 *
 *Return: pointer to line recovered
 */
char *read_line(void)
{
	char *buffer = NULL;
	size_t buff_size = 0;
	ssize_t characters_read;

	while (buffer == NULL || buffer[0] == '\0' || isspace(buffer[0]))
	{
#ifdef PROMPT
		if (printf("33sh> ") < 0)
			perror("write");
#endif

		characters_read = getline(&buffer, &buff_size, stdin);
		if (characters_read == -1)
		{
			free(buffer);
#ifdef PROMPT
			_puts("\n");
#endif
			return (NULL);
		}
		buffer[characters_read - 1] = '\0';
	}
	return (buffer);
}
/**
 *split_string - Splits a string and returns an array of each word of
 *		 string
 *@input: The string to be tokenized
 *@delimiter: Where to split
 *
 *Return: A ponter to the array
 */
char **split_string(char *input, const char *delimiter)
{
	int count = 0;
	char **words = NULL;
	char *token = NULL, *input_copy;

	words = NULL;
	input_copy = _strdup(input);
	if (!input_copy)
	{
		perror("strdup");
		return (NULL);
	}
	token = strtok(input_copy, delimiter);
	while (token != NULL)
	{
		words = realloc(words, (count + 1) * sizeof(char *));
		if (!words)
		{
			free(input_copy);
			return (NULL);
		}
		words[count] = _strdup(token);
		if (!words[count])
		{
			free(input_copy);
			free_words(words, count);
			return (NULL);
		}
		token = strtok(NULL, delimiter);
		count++;
	}
	free(input_copy);
	words = realloc(words, (count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	words[count] = NULL;
	return (words);
}
/**
 *split_string2 - Splits a string into array of words
 *@str: The String to split
 *
 *Return: A pointer to the array of words
 */
char **split_string2(char *str)
{
	unsigned int i = 0, j = 0, count = 0;
	char **words = NULL, *word = NULL, *str_dup;

	str_dup = _strdup(str);
	if (!str_dup)
	{
		perror("strdup");
		return (NULL);
	}
	while (str_dup[i] != '\0')
	{
		while (str_dup[i] != ' ')
		{
			word = realloc(word, (j + 2) * sizeof(char));
			if (!word)
			{
				perror("malloc"), free(str_dup);
				return (NULL);
			}
			word[j] = str_dup[i + j];
			j++, i++;
		}
		word[j] = '\0';
		j = 0;
		words = realloc(words, (count + 1) * sizeof(char *));
		if (!words)
		{
			free(str_dup), free(word);
			return (NULL);
		}
		words[count] = _strdup(word);
		if (!words[count])
		{
			perror("strdup"), free(str_dup), free(word);
			return (NULL);
		}
		count++, i++;
	}
	free(str_dup);
	return (words);
}
/**
 *trim_spaces - Trims spaces preceeding an arguments in str
 *@str: The provided string
 *
 *Return: pointer to non spaces preceeded  string
 */
char *trim_spaces(char *str)
{
	char *end;

	while (isspace((unsigned char)*str))
	{
		str++;
	}
	/* If all spaces, return an empty string*/
	if (*str == '\0')
		return (str);
	end = str + _strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
	{
		end--;
	}
	*(end + 1) = '\0';

	return (str);
}
