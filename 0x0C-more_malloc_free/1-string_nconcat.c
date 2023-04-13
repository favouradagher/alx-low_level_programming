#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the maximum number of bytes of s2 to concatenate
 *
 * Return: a pointer to the concatenated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1, len2, copy;
	char *concat;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len1 = strlen(s1);
	len2 = strlen(s2);
	if (n >= len2)
		copy = len2;
	else
		copy = n;
	concat = malloc(len1 + copy + 1);
	if (concat == NULL)
		return (NULL);
	memcpy(concat, s1, len1);
	memcpy(concat + len1, s2, copy);
	concat[len1 + copy] = '\0';
	return (concat);
}


