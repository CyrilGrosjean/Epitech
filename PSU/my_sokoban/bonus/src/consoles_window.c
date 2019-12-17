/*
** EPITECH PROJECT, 2019
** consoles window
** File description:
** Functions for differents windows
*/

#include "../include/my_popup.h"

int render_window_main_menu(void)
{
    int key = 0;
    int valide = TRUE;
    int select = 0;

    while (valide) {
        display_menu(select);
        key = getch();
        if (key == 10)
            valide = FALSE;
        else
            select = get_key_main_menu(key, select);
    }
    return (select);
}

int render_window_game(char **tab, int **tab_int, player_t *player)
{
    int key = 0;

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
    return (test_win(tab, tab_int));
}

int render_window_edit(void)
{
    int save = FALSE;
    int key = 0;
    char *str = malloc(sizeof(char) * (2501 + 1));
    object_t object = init_object();

    str = define_str(str);
    while (1) {
        display_window_editor(str);
        key = getch();
        if (key == 's') {
            save = TRUE;
            break;
        } else if (key == 'c')
            break;
        else
            str = check_key_editor(key, str, &object);
    }
    save_map(save, str);
    free(str);
    return (0);
}