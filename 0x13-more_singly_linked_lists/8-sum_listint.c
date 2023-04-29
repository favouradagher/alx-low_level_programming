#include "lists.h"
#include <stdlib.h>

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t list
 * @head: pointer to the head node of the list
 *
 * Return: sum of all data in the list, or 0 if list is empty
 */
int sum_listint(listint_t *head)
{
    int sum = 0;

    while (head)
    {
        sum += head->n;
        head = head->next;
    }

    return (sum);
}

