/*
** EPITECH PROJECT, 2019
** select menu
** File description:
** functions for select menu
*/

#include "../include/runner.h"

int selected_play(window_t *w, int button)
{
    if (button != 0)
        sfSound_play(w->mouse_over);
    sfText_setColor(w->play, sfRed);
    button = 0;
    return (button);
}

int selected_options(window_t *w, int button)
{
    if (button != 1)
        sfSound_play(w->mouse_over);
    sfText_setColor(w->options, sfRed);
    button = 1;
    return (button);
}

int selected_leave(window_t *w, int button)
{
    if (button != 2)
        sfSound_play(w->mouse_over);
    sfText_setColor(w->leave, sfRed);
    button = 2;
    return (button);
}