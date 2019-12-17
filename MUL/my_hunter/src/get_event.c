/*
** EPITECH PROJECT, 2019
** get event
** File description:
** Event gestion for the game
*/

#include "../include/hunter.h"

int manage_mouse_click(sfMouseButtonEvent ev, window_t *window)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(window->rel_scope)) < 1.1)
        return (0);
    sfClock_restart(window->rel_scope);
    sfMusic_play(window->shoot_sound);
    if (window->window == 1) {
        duck_click(ev, window);
        dog_click(ev, window);
    } else {
        text_click(ev, window);
    }
    return (0);
}

void manage_key_pressed(sfKeyEvent event, window_t *window)
{
    if (event.code == sfKeyEscape)
        sfRenderWindow_close(window->w);
}

void analyse_event(window_t *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window->w);
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, window);
    if (event.type == sfEvtKeyPressed)
        manage_key_pressed(event.key, window);
}