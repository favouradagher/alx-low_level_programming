
#include "dog.h"
#include <stddef.h>

/**
 * free_dog - frees the memory allocated for a struct dog
 * @d: pointer to the struct dog
 *
 * Return: void
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}

