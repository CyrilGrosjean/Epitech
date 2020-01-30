/*
** EPITECH PROJECT, 2020
** get game params
** File description:
** Functions to get nb lines and matches
*/

#include "../include/matchstick.h"

int get_max_stick(int line)
{
    int number = 1;

    for (int i = 1; i < line; i += 1)
        number += 2;
    return (number);
}

int *get_every_line(int line)
{
    int *tab = malloc(sizeof(int) * (line));
    int number = 1;

    for (int i = 0; i < line; i += 1) {
        tab[i] = number;
        number += 2;
    }
    return (tab);
}

int display_who_win(int lose)
{
    if (lose == 2)
        my_putstr(1, "You lost, too bad...\n");
    else if (lose == 1)
        my_putstr(1, "I lost... snif... but I'll get you next time!!\n");
    return (lose);
}

int get_params(char *lines, char *matches)
{
    int line = my_getnbr(lines);
    int match = my_getnbr(matches);
    int *tab;
    int lose = 0;
    game_t params;

    if (line < 2 || line > 99) {
        my_putstr(2, "The number of lines must be between 2 and 99 lines.\n");
        return (84);
    }
    if (match < 1) {
        my_putstr(2, "The number of matches must be greater than 0.\n");
        return (84);
    }
    params.lines = line;
    params.matches = match;
    params.max_sticks_line = get_max_stick(line);
    tab = get_every_line(line);
    lose = in_game(tab, &params);
    return (display_who_win(lose));
}