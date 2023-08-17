#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a doubly linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: Number of elements in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
    const dlistint_t *current = h;
    size_t node_count = 0;

    while (current != NULL)
    {
        current = current->next;
        node_count++;
    }

    return node_count;
}

