#include "lists.h"
#include <stdlib.h>

/**
 * delete_node_at_head - deletes the head node of the list
 * @head: double pointer to the head of the doubly linked list
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_node_at_head(dlistint_t **head)
{
    if (*head == NULL)
    {
        return (-1);
    }

    dlistint_t *temp = *head;

    *head = temp->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }

    free(temp);
    return (1);
}

/**
 * delete_node_at_index - deletes a node at a specific index
 * @head: double pointer to the head of the doubly linked list
 * @index: index of the node to be deleted
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_node_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    current = *head;

    for (i = 0; current != NULL && i < index; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        return (-1);
    }

    if (current == *head)
    {
        return (delete_node_at_head(head));
    }

    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    free(current);
    return (1);
}
