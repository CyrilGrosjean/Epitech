/*
** EPITECH PROJECT, 2019
** rotate
** File description:
** set the corner of int array to the other corner
*/

#include "../include/pushswap.h"

void rotate_left(int *array, int size)
{
    if (size > 1) {
        for (int i = 1; i < size; i += 1)
            swap_elem(array, i - 1, i);
    }
}

void rotate_right(int *array, int size)
{
    if (size > 1)
        for (int i = size - 1; i > 0; i -= 1)
            swap_elem(array, i - 1, i);
}