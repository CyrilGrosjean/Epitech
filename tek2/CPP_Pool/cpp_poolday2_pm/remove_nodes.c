/*
** EPITECH PROJECT, 2021
** cpp_poolday2_pm
** File description:
** remove_nodes
*/

#include "double_list.h"
#include <stdbool.h>
#include <stdlib.h>

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t ptr;

    if ((*front_ptr) == NULL)
        return (false);
    ptr = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(ptr);
    return (true);
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t ptr;
    unsigned int size = double_list_get_size(*front_ptr);

    if ((*front_ptr) == NULL)
        return (false);
    ptr = *front_ptr;
    for (unsigned int i = 0; i < size - 2; i += 1) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return (true);
}

bool double_list_del_elem_at_position(double_list_t *front_ptr,
unsigned int position)
{
    double_list_t ptr;
    double_list_t ptr_next;
    unsigned int size = double_list_get_size(*front_ptr);

    if ((*front_ptr) == NULL || position > size)
        return (false);
    if (position == 0)
        return (double_list_del_elem_at_front(front_ptr));
    else if (position == size)
        return (double_list_del_elem_at_back(front_ptr));
    ptr = *front_ptr;
    for (unsigned int i = 0; i < position - 1; i += 1)
        ptr = ptr->next;
    ptr_next = ptr->next->next;
    free(ptr->next);
    ptr->next = ptr_next;
    return (true);
}