/*
** EPITECH PROJECT, 2021
** cpp_poolday2_pm
** File description:
** get_nodes
*/

#include "double_list.h"
#include <stdio.h>

double double_list_get_elem_at_front(double_list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    if (list == NULL)
        return (0);
    for (; list->next != NULL;)
        list = list->next;
    return (list->value);
}

double double_list_get_elem_at_position(double_list_t list,
unsigned int position)
{
    unsigned int size = double_list_get_size(list);

    if (list == NULL || position > size)
        return (0);
    if (position == 0)
        return (double_list_get_elem_at_front(list));
    else if (position == size)
        return (double_list_get_elem_at_back(list));
    for (unsigned int i = 0; i < position; i += 1)
        list = list->next;
    return (list->value);
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
double value)
{
    if (list == NULL)
        return (NULL);
    for (; list->next != NULL;) {
        if (list->value == value)
            return (list);
        list = list->next;
    }
    if (list->value == value)
        return (list);
    return (NULL);
}