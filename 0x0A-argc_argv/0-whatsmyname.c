#include "main.h"
#include <stdio.h>

/**
 * main - Prints the program's name, followed by a new line
 * @argc: The number of arguments supplied to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
    int i;

    for (i = 0; i < argc; i++)
        printf("%s\n", argv[i]);

    return (0);
}

