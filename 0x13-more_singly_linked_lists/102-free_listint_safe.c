#include "lists.h"
#include<stdlib.h>
/**
 * free_listint_safe - frees a listint_t list
 * @h: double pointer to the head of the list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *tmp;
	size_t size = 0;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	*h = NULL;

	while (current != NULL)
	{
		size++;
		tmp = current;
		current = current->next;

		if (tmp <= current)
		{
			free(tmp);
			continue;
		}
		break;
	}

	return (size);
}

