/*
** EPITECH PROJECT, 2019
** destroy
** File description:
** functions to destroy every object in the game
*/

#include "../include/runner.h"

void destroy_game_object(window_t *w)
{
    for (int i = 0; i < w->object_numb; i += 1) {
        sfSprite_destroy(w->s[i].s_sprite);
        sfTexture_destroy(w->s[i].t_sprite);
        sfClock_destroy(w->s[i].clock);
    }
}

void destroy_main_window(window_t *w)
{
    sfClock_destroy(w->refresh);
    sfText_destroy(w->play);
    sfText_destroy(w->leave);
    sfText_destroy(w->options);
    sfText_destroy(w->score);
    sfText_destroy(w->win_lose);
    sfFont_destroy(w->font);
    sfMusic_destroy(w->music);
    sfMusic_destroy(w->jump);
    sfMusic_destroy(w->mouse_over);
    sfMusic_destroy(w->mouse_click);
}

void destroy_objects(window_t *w)
{
    destroy_game_object(w);
    destroy_main_window(w);
}