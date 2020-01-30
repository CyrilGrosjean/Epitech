/*
** EPITECH PROJECT, 2020
** remove stick
** File description:
** functions to remove stick
*/

#include "../include/matchstick.h"

void remove_stick_player(int *tab, int line, int match)
{
    tab[line - 1] -= match;
    my_putstr(1, "Player removed ");
    my_put_nbr(match);
    my_putstr(1, " match(es) from line ");
    my_put_nbr(line);
    my_putstr(1, "\n");
}

void remove_stick_bot(int *tab, int line, int match)
{
    tab[line - 1] -= match;
    my_putstr(1, "AI removed ");
    my_put_nbr(match);
    my_putstr(1, " match(es) from line ");
    my_put_nbr(line);
    my_putstr(1, "\n");
}