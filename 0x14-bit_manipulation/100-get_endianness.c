#include "main.h"

/**
 * get_endianness - Checks the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
    unsigned int num = 1;
    char *endian = (char *)&num;

    /* If the first byte of num is non-zero, we're little endian */
    if (*endian)
        return 1; /* little endian */
    else
        return 0; /* big endian */
}

