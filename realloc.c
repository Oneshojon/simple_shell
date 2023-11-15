#include "shell.h"

/**
 *_realloc - realicate a memory space using malloc and free
 *@ptr: poointer to the previous memory
 *@size: size to add
 *
 *Return: a pointer
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(size));
	new_ptr = malloc(size);

	if (new_ptr == NULL)
		return (NULL);

	memcpy(new_ptr, ptr, size);

	free(ptr);
	return (new_ptr);
}
