/*
** EPITECH PROJECT, 2019
** display menu
** File description:
** functions for displaying game menu
*/

#include "../include/runner.h"

void display_main_menu(window_t *w)
{
    sfVector2f vec = {0, 0};

    reset_spikes(w);
    update_text_score(w);
    sfSprite_setPosition(w->s[6].s_sprite, vec);
    sfRenderWindow_drawSprite(w->w, w->s[6].s_sprite, NULL);
    sfRenderWindow_drawText(w->w, w->play, NULL);
    sfRenderWindow_drawText(w->w, w->options, NULL);
    sfRenderWindow_drawText(w->w, w->leave, NULL);
    sfRenderWindow_drawText(w->w, w->best_label, NULL);
    sfRenderWindow_drawText(w->w, w->best1, NULL);
    sfRenderWindow_drawText(w->w, w->best2, NULL);
    sfRenderWindow_drawText(w->w, w->best3, NULL);
}

void display_option_menu(window_t *w, option_t *opt)
{
    reset_spikes(w);
    sfRenderWindow_drawText(w->w, opt->difficulty, NULL);
    sfRenderWindow_drawText(w->w, opt->s_volume, NULL);
    sfRenderWindow_drawText(w->w, opt->m_volume, NULL);
    sfRenderWindow_drawText(w->w, opt->back, NULL);
    sfRenderWindow_drawText(w->w, opt->label_diff, NULL);
    sfRenderWindow_drawText(w->w, opt->label_s, NULL);
    sfRenderWindow_drawText(w->w, opt->label_m, NULL);
    sfRenderWindow_drawSprite(w->w, opt->sub_diff, NULL);
    sfRenderWindow_drawSprite(w->w, opt->add_diff, NULL);
    sfRenderWindow_drawSprite(w->w, opt->add_sound, NULL);
    sfRenderWindow_drawSprite(w->w, opt->sub_sound, NULL);
    sfRenderWindow_drawSprite(w->w, opt->add_music, NULL);
    sfRenderWindow_drawSprite(w->w, opt->sub_music, NULL);
    sfRenderWindow_drawText(w->w, opt->label_endl, NULL);
    sfRenderWindow_drawSprite(w->w, opt->endl_case, NULL);
    sfRenderWindow_drawText(w->w, opt->label_framerate, NULL);
    sfRenderWindow_drawText(w->w, opt->t_frame, NULL);
    sfRenderWindow_drawSprite(w->w, opt->add_framerate, NULL);
    sfRenderWindow_drawSprite(w->w, opt->sub_framerate, NULL);
}