/*
** EPITECH PROJECT, 2021
** cpp_poolday2_pm
** File description:
** get_nodes
*/

#include "generic_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

void *list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return (0);
    for (; list->next != NULL;)
        list = list->next;
    return (list->value);
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    unsigned int size = list_get_size(list);

    if (list == NULL || position > size)
        return (0);
    if (position == 0)
        return (list_get_elem_at_front(list));
    else if (position == size)
        return (list_get_elem_at_back(list));
    for (unsigned int i = 0; i < position; i += 1)
        list = list->next;
    return (list->value);
}

node_t *list_get_first_node_with_value(list_t list, void *value,
value_comparator_t val_comp)
{
    if (list == NULL)
        return (NULL);
    for (; list->next != NULL;) {
        if (val_comp(list->value, value) == 0)
            return (list);
        list = list->next;
    }
    if (val_comp(list->value, value) == 0)
        return (list);
    return (NULL);
}