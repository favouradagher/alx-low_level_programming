#include <stdio.h>
#include "main.h"

/**
 * flip_bits - returns the number of bits to flip to convert one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long int diff = n ^ m;

	while (diff)
	{
		count += (diff & 1);
		diff >>= 1;
	}

	return (count);
}

