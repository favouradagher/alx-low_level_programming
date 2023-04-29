#include "lists.h"
#include<stdlib.h>

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Pointer to pointer of first node of listint_t list.
 * @idx: Index of the list where the new node should be added.
 * @n: Integer to be included in the new node.
 *
 * Return: Address of the new node or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    unsigned int i = 0;
    listint_t *new, *current;

    if (head == NULL)
        return (NULL);

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);
    new->n = n;

    current = *head;
    if (idx == 0)
    {
        new->next = current;
        *head = new;
        return (new);
    }

    while (current != NULL && i < idx - 1)
    {
        current = current->next;
        i++;
    }

    if (current == NULL)
    {
        free(new);
        return (NULL);
    }

    new->next = current->next;
    current->next = new;

    return (new);
}

