#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct list_s - Struct for a singly linked list
 * @str: String data stored in the node
 * @len: Length of the string
 * @next: Pointer to the next node
 *
 * Description: Structure defining a singly linked list node
 */

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

#endif
