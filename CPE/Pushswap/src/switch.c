/*
** EPITECH PROJECT, 2019
** switch
** File description:
** functions for switch list
*/

#include "../include/pushswap.h"

void switch_to_list_b(int *list_a, int *list_b, int size_a, int size_b)
{
    rotate_right(list_b, size_b);
    rotate_left(list_a, size_a);
    list_b[size_b] = list_a[size_a - 1];
    my_putstr("pb ");
}

void switch_to_list_a(int *list_a, int *list_b, int size_a, int size_b)
{
    rotate_right(list_a, size_a);
    rotate_left(list_b, size_b);
    list_a[size_a] = list_b[size_b - 1];
    my_putstr("pa");
}