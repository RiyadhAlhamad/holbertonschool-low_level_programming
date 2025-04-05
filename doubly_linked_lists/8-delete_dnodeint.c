#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index index of a doubly linked list
 * @head: double pointer to the head of the doubly linked list
 * @index: index of the node to be deleted
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (*head == NULL)
	{
		return (-1);
	}

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
		*head = current->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
	}
	else
	{
		if (current->prev != NULL)
		{
			current->prev->next = current->next;
		}

		if (current->next != NULL)
		{
			current->next->prev = current->prev;
		}
	}

	free(current);
	return (1);
}
