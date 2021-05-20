/*
** EPITECH PROJECT, 2021
** cpp_poolday2_pm
** File description:
** values_nodes
*/

#include "generic_list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

unsigned int list_get_size(list_t list)
{
    unsigned int number = 0;

    for (; list != NULL; number += 1) {
        list = list->next;
    }
    return (number);
}

bool list_is_empty(list_t list)
{
    if (list == NULL) {
        return (true);
    }
    return (false);
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    for (; list != NULL;) {
        val_disp(list->value);
        list = list->next;
    }
}

void list_clear(list_t *front_ptr)
{
    list_t tmp = (*front_ptr)->next;

    while ((*front_ptr) != NULL) {
        free(*front_ptr);
        *front_ptr = tmp;
        if (tmp == NULL)
            break;
        tmp = tmp->next;
    }
    *front_ptr = NULL;
}