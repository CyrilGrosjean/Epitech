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

void destroy_best(window_t *w)
{
    sfText_destroy(w->best_label);
    sfText_destroy(w->best1);
    sfText_destroy(w->best2);
    sfText_destroy(w->best3);
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
    sfSound_destroy(w->jump);
    sfSound_destroy(w->mouse_over);
    sfSound_destroy(w->mouse_click);
    sfSound_destroy(w->game_over);
    sfSound_destroy(w->win);
    sfSoundBuffer_destroy(w->win_buff);
    sfSoundBuffer_destroy(w->mouse_over_buff);
    sfSoundBuffer_destroy(w->jump_buff);
    sfSoundBuffer_destroy(w->mouse_click_buff);
    sfSoundBuffer_destroy(w->game_over_buff);
    destroy_best(w);
}

void destroy_objects(window_t *w)
{
    destroy_game_object(w);
    destroy_main_window(w);
    save_best(w);
    free(w->score_1);
    free(w->score_2);
    free(w->score_3);
}