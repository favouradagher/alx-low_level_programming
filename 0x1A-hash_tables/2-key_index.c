#include "hash_tables.h"

/**
 * key_index - Gives you the index of a key.
 * @key: The key to hash.
 * @size: The size of the array of the hash table.
 *
 * Return: The index at which the key/value pair should be stored in the array.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int hash_value, index;

    /* Calculate the hash value using hash_djb2 */
    hash_value = hash_djb2(key);

    /* Compute the index within the array */
    index = hash_value % size;

    return (index);
}

