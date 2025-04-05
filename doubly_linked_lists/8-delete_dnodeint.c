#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index index of a doubly linked list
 * @head: Double pointer to the head of the list
 * @index: Index of the node to delete
 * 
 * Return: 1 if succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int i = 0;

    if (current == NULL)  // Case when the list is empty
        return (-1);

    // Deleting the head node
    if (index == 0)
    {
        *head = current->next;
        if (current->next != NULL)
            current->next->prev = NULL;
        free(current);
        return (1);
    }

    // Traverse the list to find the node to delete
    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    // If the node doesn't exist
    if (current == NULL)
        return (-1);

    // Adjust the previous node to skip the current node
    if (current->next != NULL)
        current->next->prev = current->prev;

    // Adjust the next node of the previous node
    if (current->prev != NULL)
        current->prev->next = current->next;

    free(current);
    return (1);
}
