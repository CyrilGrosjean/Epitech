/*
** EPITECH PROJECT, 2020
** display board
** File description:
** functions to display board
*/

#include "../include/matchstick.h"

int get_stick_line(int line)
{
    int nb = 1;

    for (int i = 1; i < line; i += 1)
        nb += 2;
    return (nb);
}

void display_line(int *tab, int index, game_t *t)
{
    int max_stick = get_stick_line(index + 1);
    int spaces = (t->max_sticks_line - max_stick) / 2;

    my_putstr(1, "*");
    for (int i = 0; i < spaces; i += 1)
        my_putstr(1, " ");
    for (int i = 0; i < max_stick; i += 1)
        if (i < tab[index])
            my_putstr(1, "|");
        else
            my_putstr(1, " ");
    for (int i = 0; i < spaces; i += 1)
        my_putstr(1, " ");
    my_putstr(1, "*\n");
}

void display_board(int *tab, game_t *t)
{
    for (int i = 0; i < t->max_sticks_line + 2; i += 1)
        my_putstr(1, "*");
    my_putstr(1, "\n");
    for (int i = 0; i < t->lines; i += 1)
        display_line(tab, i, t);
    for (int i = 0; i < t->max_sticks_line + 2; i += 1)
        my_putstr(1, "*");
    my_putstr(1, "\n");
}