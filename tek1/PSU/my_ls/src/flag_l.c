/*
** EPITECH PROJECT, 2020
** flag -l
** File description:
** functions for flag -l
*/

#include "../include/ls.h"

void flag_l(file_t *files, int count)
{
    int blocks = 0;

    for (int i = 0; i < count; i += 1)
        blocks += files[i].blksize;
    blocks /= 4096;
    my_putstr("total: ");
    my_put_nbr(blocks);
    my_putstr("\n");
    for (int i = 0; i < count; i += 1)
        if (files[i].file_name[0] != '.')
            display_l(&files[i]);
}