#include "lists.h"
#include<stdlib.h>
/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current;
	size_t count = 0;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		count++;
		printf("[%p] %d\n", (void *)current, current->n);
		if (current <= head)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			exit(98);
		}
	}
	return (count);
}

