/*
** EPITECH PROJECT, 2019
** conditions
** File description:
** conditions of winning or losing functions
*/

#include "../include/my_popup.h"

int count_objectives(char **tab, int **tab_int)
{
    int nb = 0;

    for (int y = 0; tab[y] != NULL; y += 1)
        for (int x = 0; tab[y][x]; x += 1)
            if (tab_int[y][x] == 2)
                nb += 1;
    return (nb);
}

int test_win(char **tab, int **tab_int)
{
    int objectives = count_objectives(tab, tab_int);

    for (int y = 0; tab[y] != NULL; y += 1)
        for (int x = 0; tab[y][x]; x += 1)
            if (tab[y][x] == 'X' && tab_int[y][x] == 2)
                objectives -= 1;
    if (objectives == 0)
        return (0);
    return (1);
}

int check_blocked(int **tab_int, int x, int y)
{
    int block_up = 0;
    int block_down = 0;
    int block_left = 0;
    int block_right = 0;

    if (tab_int[y][x + 1] == 1)
        block_right = 1;
    if (tab_int[y][x - 1] == 1)
        block_left = 1;
    if (tab_int[y - 1][x] == 1)
        block_up = 1;
    if (tab_int[y + 1][x] == 1)
        block_down = 1;
    if (block_down || block_up)
        if (block_right || block_left)
            return (0);
    return (1);
}

int test_lose(char **tab, int **tab_int)
{
    int blocked = 0;

    for (int y = 0; tab[y] != NULL; y += 1)
        for (int x = 0; tab[y][x]; x += 1) {
            if (tab[y][x] == 'X')
                blocked = check_blocked(tab_int, x, y);
            if (blocked)
                return (0);
        }
    return (1);
}

int quit(void)
{
    endwin();
    return (0);
}