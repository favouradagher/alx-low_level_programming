#include <stdio.h>

void __attribute__ ((constructor)) hare_and_tortoise(void);

/**
 * hare_and_tortoise - Prints "You're beat! and yet, you must allow,\n"
 *                      "I bore my house upon my back!\n" before the main function is executed.
 */
void hare_and_tortoise(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

