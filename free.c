#include "shell.h"

/**
 *free_words - frees all allocated space
 *@words: pointer to array of pointers
 *@count: A number variable
 *
 *Return: Nothing
 */
void free_words(char **words, int count)
{
	int i = 0;

	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}
/**
 *free_environment_array - Frees the Environment array
 *@envp: pointer to environment
 *
 *Return: Nothing
 */
void free_environment_array(char **envp)
{
	int i = 0;

	if (envp == NULL)
		return;

	while (envp[i] != NULL)
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}
