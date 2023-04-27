#include "main.h"
#include <stdlib.h>

/**
 * array_range - Allocates memory for an array using malloc and sets the memory to 0
 * @min: Number of elements in the array
 * @max: Size of each element in bytes
 *
 * Return: Pointer to the allocated memory, or NULL if nmemb or size is 0 or if malloc fails
 */

int *array_range(int min, int max)
{
    if (min > max)
        return NULL;

    int *arr = malloc(sizeof(int) * (max - min + 1));
    if (arr == NULL)
        return NULL;

    for (int i = 0; i <= max - min; i++)
        arr[i] = min + i;

    return arr;
}

