#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all data in a doubly linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: Sum of all data (n) in the list.
 */
int sum_dlistint(dlistint_t *head)
{
    dlistint_t *current = head;
    int sum = 0;

    while (current != NULL)
    {
        sum += current->n;
        current = current->next;
    }

    return sum;
}

