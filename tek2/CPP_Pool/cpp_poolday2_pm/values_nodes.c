/*
** EPITECH PROJECT, 2021
** cpp_poolday2_pm
** File description:
** list1
*/

#include "double_list.h"
#include <stdio.h>
#include <stdbool.h>

unsigned int double_list_get_size(double_list_t list)
{
    unsigned int number = 0;

    for (; list != NULL; number += 1) {
        list = list->next;
    }
    return (number);
}

bool double_list_is_empty(double_list_t list)
{
    if (list == NULL) {
        return (true);
    }
    return (false);
}

void double_list_dump(double_list_t list)
{
    for (; list != NULL;) {
        printf("%f\n", list->value);
        list = list->next;
    }
}