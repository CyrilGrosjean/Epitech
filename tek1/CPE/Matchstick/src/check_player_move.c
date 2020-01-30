/*
** EPITECH PROJECT, 2020
** check player move
** File description:
** functions to check every error that can try the player
*/

#include "../include/matchstick.h"

int check_positive_number(int nb, char *choice)
{
    if (nb < 0) {
        my_putstr(1, "Error: invalid input (positive number expected)\n");
        return (1);
    }
    for (int i = 0; choice[i]; i += 1)
        if ((choice[i] != '\n' && choice[i] < '0') || choice[i] > '9') {
            my_putstr(1, "Error: invalid input (positive number expected)\n");
            return (1);
        }
    return (0);
}

int check_line_error(game_t *param, int line, char *choice)
{
    if (check_positive_number(line, choice))
        return (1);
    if (line < 1 || line > param->lines) {
        my_putstr(1, "Error: this line is out of range\n");
        return (1);
    }
    my_putstr(1, "Matches: ");
    return (0);
}

int check_error_match(game_t *param, int *tab, char *choice, int line)
{
    int match = my_getnbr(choice);

    if (match > param->matches) {
        my_putstr(1, "Error: you cannot remove more than ");
        my_put_nbr(param->matches);
        my_putstr(1, " matches per turn\n");
        return (1);
    }
    if (match == 0) {
        my_putstr(1, "Error: you have to remove at least one match\n");
        return (1);
    }
    if (match > tab[line - 1]) {
        my_putstr(1, "Error: not enough matches on this line\n");
        return (1);
    }
    return (check_positive_number(match, choice));
}