#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list
 * @h: Pointer to pointer to head of the list
 * Return: Size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *temp;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	*h = NULL;

	while (current != NULL)
	{
		count++;
		if (current <= current->next)
		{
			free(current);
			break;
		}
		temp = current;
		current = current->next;
		free(temp);
	}

	return (count);
}

