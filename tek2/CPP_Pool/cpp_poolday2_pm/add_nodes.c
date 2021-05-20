/*
** EPITECH PROJECT, 2021
** cpp_poolday2_pm
** File description:
** list2
*/

#include "double_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool create_first_node(double_list_t *front_ptr, double_list_t ptr, double elem)
{
    ptr->value = elem;
    ptr->next = NULL;
    *front_ptr = ptr;
    return (true);
}

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    double_list_t node = malloc(sizeof(doublelist_node_t));

    if (!node) {
        return (false);
    }
    if (*front_ptr == NULL)
        return (create_first_node(front_ptr, node, elem));
    node->value = elem;
    node->next = (*front_ptr);
    (*front_ptr) = node;
    return (true);
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    double_list_t node = malloc(sizeof(doublelist_node_t));
    double_list_t ghost_ptr;

    if (!node)
        return (false);
    if (*front_ptr == NULL)
        return (create_first_node(front_ptr, node, elem));
    node->value = elem;
    node->next = NULL;
    ghost_ptr = *front_ptr;
    for (; ghost_ptr->next != NULL;) {
        ghost_ptr = ghost_ptr->next;
    }
    ghost_ptr->next = node;
    return (true);
}

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
unsigned int position)
{
    double_list_t node;
    double_list_t ghost_ptr;
    unsigned int size = double_list_get_size(*front_ptr);

    if (position > size)
        return (false);
    if (position == 0)
        return (double_list_add_elem_at_front(front_ptr, elem));
    else if (position == size)
        return (double_list_add_elem_at_back(front_ptr, elem));
    node = malloc(sizeof(doublelist_node_t));
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