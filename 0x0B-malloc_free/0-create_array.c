#include <stdlib.h>

char *create_array(unsigned int size, char c)
{
    char *arr = malloc(size * sizeof(char));
    unsigned int i;

    if (size == 0 || arr == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
        arr[i] = c;

    return (arr);
}

