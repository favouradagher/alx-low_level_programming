#include"function_pointers.h"

/**
 * print_name - prints a name
 * @name: name to print
 * @f: function pointer to either print name as is or in uppercase
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
    if (name && f)
        f(name);
}


