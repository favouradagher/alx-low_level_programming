#include <stddef.h>
#include <stdlib.h>


/**
 * free_dog - frees dogs
 * @d: pointer to struct dog to be freed
 *
 * Return: void
 */
void free_dog(dog-t *d)
{
    if (d != NULL)  /* Check if pointer is not NULL */
    {
        free(d->name);
        free(d->owner);
        free(d);
    }
}


