/*
** EPITECH PROJECT, 2021
** cpp_poolday2_pm
** File description:
** add_nodes
*/

#include "generic_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

bool create_first_node_list(list_t *front_ptr, list_t ptr, void *elem)
{
    ptr->value = elem;
    ptr->next = NULL;
    *front_ptr = ptr;
    return (true);
}

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t node = malloc(sizeof(node_t));

    if (!node) {
        return (false);
    }
    if (*front_ptr == NULL)
        return (create_first_node_list(front_ptr, node, elem));
    node->value = elem;
    node->next = (*front_ptr);
    (*front_ptr) = node;
    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t node = malloc(sizeof(node_t));
    list_t ghost_ptr;

    if (!node)
        return (false);
    if (*front_ptr == NULL)
        return (create_first_node_list(front_ptr, node, elem));
    node->value = elem;
    node->next = NULL;
    ghost_ptr = *front_ptr;
    for (; ghost_ptr->next != NULL;) {
        ghost_ptr = ghost_ptr->next;
    }
    ghost_ptr->next = node;
    return (true);
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
unsigned int position)
{
    list_t node;
    list_t ghost_ptr;
    unsigned int size = list_get_size(*front_ptr);

    if (position > size)
        return (false);
    if (position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    else if (position == size)
        return (list_add_elem_at_back(front_ptr, elem));
    node = malloc(sizeof(node_t));
    if (!node)
        return (false);
    ghost_ptr = *front_ptr;
    node->value = elem;
    for (unsigned int i = 0; i + 1 < position && ghost_ptr->next != NULL;
    i += 1)
        ghost_ptr = ghost_ptr->next;
    node->next = ghost_ptr->next;
    ghost_ptr->next = node;
    return (true);
}