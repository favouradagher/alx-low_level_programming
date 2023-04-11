#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: number of arguments
 * @av: arguments array
 *
 * Return: pointer to new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
    int i, j, k = 0;
    char *str;

    if (ac == 0 || av == NULL)
        return (NULL);

    /* calculate length of the resulting string */
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
            k++;
        k++; /* add one for the newline character */
    }

    /* allocate memory for the resulting string */
    str = malloc(sizeof(char) * k);
    if (str == NULL)
        return (NULL);

    /* copy arguments into the resulting string */
    k = 0;
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
        {
            str[k] = av[i][j];
            k++;
        }
        str[k] = '\n'; /* add newline character */
        k++;
    }

    str[k] = '\0'; /* add null terminator */

    return (str);
}
`
