#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count the words of.
 *
 * Return: The number of words counted.
 */
int count_words(char *str)
{
    int i, count = 0, in_word = 0;

    for (i = 0; str[i]; i++)
    {
        if (str[i] != ' ')
        {
            if (!in_word)
            {
                in_word = 1;
                count++;
            }
        }
        else
        {
            in_word = 0;
        }
    }

    return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: A pointer to an array of strings (words).
 *         NULL if str == NULL or str == "" or if memory allocation fails.
 */
char **strtow(char *str)
{
    char **words;
    int i, j, k, len, n_words;

    if (str == NULL || *str == '\0')
        return (NULL);

    n_words = count_words(str);
    words = malloc((n_words + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);

    for (i = 0, j = 0; j < n_words; i++)
    {
        if (str[i] != ' ')
        {
            for (len = 0, k = i; str[k] && str[k] != ' '; k++)
                len++;

            words[j] = malloc((len + 1) * sizeof(char));
            if (words[j] == NULL)
            {
                for (j--; j >= 0; j--)
                    free(words[j]);
                free(words);
                return (NULL);
            }

            for (k = 0; k < len; k++, i++)
                words[j][k] = str[i];
            words[j++][k] = '\0';
        }
    }

    words[j] = NULL;

    return (words);
}

