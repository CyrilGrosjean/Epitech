/*
** EPITECH PROJECT, 2019
** error
** File description:
** Check if the program can be run
*/

#include "../include/my_popup.h"

int check_error(char **tab, int **tab_int, player_t *player)
{
    int player_p = 0;
    int boxes = 0;
    int objectives = 0;

    for (int y = 0; tab[y] != NULL; y += 1) {
        for (int x = 0; tab[y][x]; x += 1) {
            if (tab_int[y][x] == 2)
                objectives += 1;
            if (tab_int[y][x] == 3)
                boxes += 1;
            if (tab_int[y][x] == 4) {
                player_p += 1;
                player->y = y;
                player->x = x;
            }
        }
    }
    if (player_p != 1 || boxes == 0 || objectives == 0 || boxes < objectives)
        return (84);
    return (0);
}

int get_int(char c)
{
    switch (c) {
        case ' ':
            return (0);
        case '#':
            return (1);
        case 'O':
            return (2);
        case 'X':
            return (3);
        case 'P':
            return (4);
        default:
            return (5);
    }
}

char get_char(int i)
{
    switch (i) {
        case 0:
            return (' ');
        case 1:
            return ('#');
        case 2:
            return ('O');
        case 3:
            return ('X');
        case 4:
            return ('P');
        default:
            return ('?');
    }
}

void display_too_small(void)
{
    char too_small[17] = "Screen too small";

    clear();
    mvprintw((LINES / 2), ((COLS / 2) - (17 / 2)), too_small);
}