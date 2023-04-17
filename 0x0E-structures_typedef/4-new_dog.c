#include <stdlib.h>
#include "dog.h"

/**
 * _strdup - Duplicates a string
 * @str: the string to duplicate
 *
 * Return: A pointer to the newly allocated memory containing the duplicate
 * string, or NULL if str is NULL or if memory allocation fails.
 */
char *_strdup(char *str)
{
    char *dup;
    unsigned int i, len = 0;

    if (str == NULL)
        return (NULL);

    while (str[len] != '\0')
        len++;

    dup = malloc(sizeof(char) * (len + 1));
    if (dup == NULL)
        return (NULL);

    for (i = 0; i <= len; i++)
        dup[i] = str[i];

    return (dup);
}

/**
 * new_dog - Creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the owner
 *
 * Return: A pointer to the newly created dog, or NULL if memory allocation
 * fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *dog;
    char *name_dup, *owner_dup;

    dog = malloc(sizeof(dog_t));
    if (dog == NULL)
        return (NULL);

    name_dup = _strdup(name);
    if (name_dup == NULL)
    {
        free(dog);
        return (NULL);
    }

    owner_dup = _strdup(owner);
    if (owner_dup == NULL)
    {
        free(name_dup);
        free(dog);
        return (NULL);
    }

    dog->name = name_dup;
    dog->age = age;
    dog->owner = owner_dup;

    return (dog);
}

