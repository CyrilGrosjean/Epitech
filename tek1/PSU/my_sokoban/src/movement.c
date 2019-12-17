/*
** EPITECH PROJECT, 2019
** movement
** File description:
** functions for player movement
*/

#include "../include/my_popup.h"

char get_old_tile(int **tab_int, int x, int y)
{
    switch (tab_int[y][x]) {
        case 2:
            return ('O');
        default:
            return (' ');
    }
    return (' ');
}

char **move_right(char **tab, int **tab_int, player_t *player)
{
    int x_p = player->x;
    int y_p = player->y;

    if (tab[y_p][x_p + 1] == '#')
        return (tab);
    else if (tab[y_p][x_p + 1] == 'X') {
        if (tab[y_p][x_p + 2] == 'X' || tab[y_p][x_p + 2] == '#')
            return (tab);
        else {
            tab[y_p][x_p + 1] = 'P';
            tab[y_p][x_p + 2] = 'X';
            tab[y_p][x_p] = get_old_tile(tab_int, x_p, y_p);
            player->x += 1;
        }
    } else {
        tab[y_p][x_p + 1] = 'P';
        tab[y_p][x_p] = get_old_tile(tab_int, x_p, y_p);
        player->x += 1;
    }
    return (tab);
}

char **move_left(char **tab, int **tab_int, player_t *player)
{
    int x_p = player->x;
    int y_p = player->y;

    if (tab[y_p][x_p - 1] == '#')
        return (tab);
    else if (tab[y_p][x_p - 1] == 'X') {
        if (tab[y_p][x_p - 2] == 'X' || tab[y_p][x_p - 2] == '#')
            return (tab);
        else {
            tab[y_p][x_p - 1] = 'P';
            tab[y_p][x_p - 2] = 'X';
            tab[y_p][x_p] = get_old_tile(tab_int, x_p, y_p);
            player->x -= 1;
        }
    } else {
        tab[y_p][x_p - 1] = 'P';
        tab[y_p][x_p] = get_old_tile(tab_int, x_p, y_p);
        player->x -= 1;
    }
    return (tab);
}

char **move_up(char **tab, int **tab_int, player_t *player)
{
    int x_p = player->x;
    int y_p = player->y;

    if (tab[y_p - 1][x_p] == '#')
        return (tab);
    else if (tab[y_p - 1][x_p] == 'X') {
        if (tab[y_p - 2][x_p] == 'X' || tab[y_p - 2][x_p] == '#')
            return (tab);
        else {
            tab[y_p - 1][x_p] = 'P';
            tab[y_p - 2][x_p] = 'X';
            tab[y_p][x_p] = get_old_tile(tab_int, x_p, y_p);
            player->y -= 1;
        }
    } else {
        tab[y_p - 1][x_p] = 'P';
        tab[y_p][x_p] = get_old_tile(tab_int, x_p, y_p);
        player->y -= 1;
    }
    return (tab);
}

char **move_down(char **tab, int **tab_int, player_t *player)
{
    int x_p = player->x;
    int y_p = player->y;

    if (tab[y_p + 1][x_p] == '#')
        return (tab);
    else if (tab[y_p + 1][x_p] == 'X') {
        if (tab[y_p + 2][x_p] == 'X' || tab[y_p + 2][x_p] == '#')
            return (tab);
        else {
            tab[y_p + 1][x_p] = 'P';
            tab[y_p + 2][x_p] = 'X';
            tab[y_p][x_p] = get_old_tile(tab_int, x_p, y_p);
            player->y += 1;
        }
    } else {
        tab[y_p + 1][x_p] = 'P';
        tab[y_p][x_p] = get_old_tile(tab_int, x_p, y_p);
        player->y += 1;
    }
    return (tab);
}