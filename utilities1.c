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
/**
 *_strcmp - Compares two strings
 *@str1: First string
 *@str2: Second string
 *
 *Return: 0 if strings are the same
 */
int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	if (str1 == NULL || str2 == NULL)
		return (-1);
	while (str1[i] != '\0' && str2[i] != NULL)
	{
		if (str1[i] != str2[i])
			return str1[i] - str2[i];
		i++;
	}

	return (str1[i] - str2[i]);
}
