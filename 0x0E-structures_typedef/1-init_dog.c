#include "stdlib.h"


/**
 * init_dog - Initializes a dog structure
 * @d: pointer to the dog structure
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the owner
 *
 * Return: Nothing.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
    if (d == NULL)
        return;

    d->name = name;
    d->age = age;
    d->owner = owner;
}

