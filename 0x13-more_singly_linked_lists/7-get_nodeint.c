#include "lists.h"
#include<stdlib.h>
/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: pointer to the head node of the linked list
 * @index: index of the desired node (starting from 0)
 *
 * Return: pointer to the nth node, or NULL if the node does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i = 0;
    listint_t *node = head;

    while (node != NULL && i < index)
    {
        node = node->next;
        i++;
    }

    return (i == index ? node : NULL);
}

