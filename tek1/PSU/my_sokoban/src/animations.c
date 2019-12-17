/*
** EPITECH PROJECT, 2019
** animations
** File description:
** functions curses
*/

#include "../include/my_popup.h"

char **reset(char **tab, int **int_tab, player_t *player)
{
    for (int y = 0; tab[y] != NULL; y += 1)
        for (int x = 0; tab[y][x]; x += 1) {
            tab[y][x] = get_char(int_tab[y][x]);
            if (tab[y][x] == 'P') {
                player->x = x;
                player->y = y;
            }
        }
    return (tab);
}

void display_map(char **tab)
{
    int lines = 0;
    int len_x = 0;
    int len_y = 0;

    curs_set(0);
    clear();
    for (int i = 0; tab[i] != NULL; i += 1) {
        len_y += 1;
        if (my_strlen(tab[i]) > len_x)
            len_x = my_strlen(tab[i]);
        mvprintw(lines, 0, tab[i]);
        lines += 1;
    }
    if (len_x > COLS || len_y > LINES)
        display_too_small();
    refresh();
}

char **change_map(char **tab, int **tab_int, int pos, player_t *player)
{
    if (pos == -2)
        tab = move_up(tab, tab_int, player);
    if (pos == -1)
        tab = move_left(tab, tab_int, player);
    if (pos == 1)
        tab = move_right(tab, tab_int, player);
    if (pos == 2)
        tab = move_down(tab, tab_int, player);
    return (tab);
}

char **get_key(int key, char **tab, int **tab_int, player_t *player)
{
    if (key == 65)
        tab = change_map(tab, tab_int, -2, player);
    if (key == 66)
        tab = change_map(tab, tab_int, 2, player);
    if (key == 67)
        tab = change_map(tab, tab_int, 1, player);
    if (key == 68)
        tab = change_map(tab, tab_int, -1, player);
    return (tab);
}

int render_console(char **tab, int **tab_int, player_t *player)
{
    int error = check_error(tab, tab_int, player);
    int key = 0;

    if (error != 0)
        return (84);
    initscr();
    while (1) {
        display_map(tab);
        if (!test_win(tab, tab_int) || test_lose(tab, tab_int))
            break;
        key = getch();
        if (key == 32)
            reset(tab, tab_int, player);
        if (key == 'x')
            return (quit());
        if (key != 27 && key != 32)
            tab = get_key(key, tab, tab_int, player);
    }
    endwin();
    return (test_win(tab, tab_int));
}