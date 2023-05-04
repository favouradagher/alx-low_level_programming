#include <stdio.h>
#include "main.h"

/**
 * clear_bit - Entry Point
 * @n: input
 * @index: index
 * Return: 0
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    unsigned long int mask = 1;

    if (index > sizeof(unsigned long int) * 8 - 1)
        return (-1);

    mask <<= index;
    *n &= ~mask;
    return (1);
}

