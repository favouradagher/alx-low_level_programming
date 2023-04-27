#include<stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: the starting integer value
 * @max: the ending integer value
 *
 * Return: a pointer to the newly created array, or NULL if malloc fails or if
 * min is greater than max
 */
int *array_range(int min, int max)
{
    int *arr;
    int i;

    /* Check if min is greater than max */

    if (min > max)
        return NULL;

    /* Allocate memory for the array */

    arr = (int *)malloc((max - min + 1) * sizeof(int));

    if (arr == NULL)
        return NULL;

    /* Populate the array */
    for (i = 0; i <= max - min; i++)
        arr[i] = min + i;

    return arr;
}

