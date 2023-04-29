#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list in a safe manner
 * @head: pointer to the head node of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *tortoise, *hare;
    size_t count = 0;

    if (head == NULL)
        exit(98);

    tortoise = head;
    hare = head;

    while (hare != NULL && hare->next != NULL)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare)
        {
            printf("[%p] %d\n", (void *)tortoise, tortoise->n);
            count++;
            break;
        }
    }

    if (hare == NULL || hare->next == NULL)
    {
        for (; head != NULL; head = head->next)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            count++;
        }
    }
    else
    {
        for (; head != tortoise; head = head->next)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            count++;
        }
        printf("[%p] %d\n", (void *)tortoise, tortoise->n);
        count++;
        for (hare = tortoise->next; hare != tortoise; hare = hare->next)
        {
            printf("[%p] %d\n", (void *)hare, hare->n);
            count++;
        }
    }

    return (count);
}

