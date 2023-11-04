#include "shell.h"

/**
 *_strlen - counts the number of characters in a string
 *@str: Pointer to the null terminated string
 *
 *Return: The length of the string
 */
unsigned int _strlen(char *str)
{
	unsigned int count = 0;

	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}
/**
 *_strdup - Duplicates a string
 *@str: Pointer to the string to duplicate
 *
 *Return: Pointer to the duplicate
 */
char *_strdup(char *str)
{
	char *duplicate = NULL;
	unsigned int index = 0;

	if (str == NULL)
		return (NULL);
	while (str[index] != '\0')
	{
		duplicate = realloc(duplicate, (index + 2) * sizeof(char));
		if (!duplicate)
			return (NULL);
		duplicate[index] = str[index];
		index++;
	}
	duplicate[index] = '\0';
	return (duplicate);
}
