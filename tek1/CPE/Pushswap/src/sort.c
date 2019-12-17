/*
** EPITECH PROJECT, 2019
** sort
** File description:
** sort functions for pushswap
*/

#include "../include/pushswap.h"

int *what_swap(int *list_a, int size_a, int index, int small)
{
    if (size_a > 1 && list_a[1] == small) {
        swap_elem(list_a, 0, 1);
        my_putstr("sa ");
        return (list_a);
    }
    if (size_a > 0 && index <= size_a / 2) {
        rotate_left(list_a, size_a);
        my_putstr("ra ");
        return (list_a);
    }
    if (size_a > 0 && index > size_a / 2) {
        rotate_right(list_a, size_a);
        my_putstr("rra ");
        return (list_a);
    }
    return (list_a);
}

int sort_list_b(int *list_a, int *list_b, int size_a)
{
    int size_b = 0;
    int small = get_smallest_number(list_a, size_a);
    int index = get_index_smallest(list_a, size_a);

    for (int nb = 0; size_a > 0; nb += 1) {
        if (small == list_a[0]) {
            switch_to_list_b(list_a, list_b, size_a, size_b);
            size_a -= 1;
            size_b += 1;
            small = get_smallest_number(list_a, size_a);
            index = get_index_smallest(list_a, size_a);
        } else
            list_a = what_swap(list_a, size_a, index, small);
    }
    rotate_right(list_b, size_b);
    return (size_b);
}

int check_sort_array(int *list_a, int size_a)
{
    for (int i = 1; i < size_a; i += 1)
        if (list_a[i - 1] > list_a[i])
            return (0);
    return (1);
}

int my_sort_int_array(int *list_a, int *list_b, int size_a)
{
    int size_b = 0;
    int check_sort = check_sort_array(list_a, size_a);

    if (check_sort)
        return (my_putchar('\n'));
    size_b = sort_list_b(list_a, list_b, size_a);
    size_a = 0;
    for (int nb = 0; size_b > 0; nb += 1) {
        switch_to_list_a(list_a, list_b, size_a, size_b);
        size_a += 1;
        size_b -= 1;
        if (size_b > 0)
            my_putchar(' ');
    }
    rotate_right(list_a, size_a);
    my_putchar('\n');
    return (0);
}