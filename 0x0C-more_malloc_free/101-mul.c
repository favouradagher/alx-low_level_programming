#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free.
 *
 * @ptr: Pointer to the memory previously allocated with a call to malloc.
 * @old_size: Size, in bytes, of the allocated space for ptr.
 * @new_size: Size, in bytes, of the new memory block.
 *
 * Return: If new_size == old_size - returns ptr.
 *         If new_size == 0 and ptr != NULL - frees the memory space pointed to
 *         by ptr, and returns NULL.
 *         Otherwise - returns a pointer to the new allocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p, *np;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		return (p);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	p = (char *)ptr;
	np = malloc(new_size);
	if (np == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		np[i] = p[i];

	free(ptr);
	return (np);
}

