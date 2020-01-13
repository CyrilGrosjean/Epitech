/*
** EPITECH PROJECT, 2019
** options modifications
** File description:
** functions for change options
*/

#include "../include/runner.h"

void change_difficulty(option_t *opt, int change, window_t *w)
{
    char *str;

    sfSound_play(w->mouse_click);
    opt->how_difficulty += change;
    if (opt->how_difficulty < 1)
        opt->how_difficulty = 1;
    if (opt->how_difficulty > 5)
        opt->how_difficulty = 5;
    str = my_str_nb(opt->how_difficulty);
    sfText_setString(opt->difficulty, str);
    free(str);
}

void change_sound(option_t *opt, int change, window_t *w)
{
    char *str;

    sfSound_play(w->mouse_click);
    if (opt->sound_volume == 0 && change == -5)
        return;
    if (opt->sound_volume == 100 && change == 5)
        return;
    opt->sound_volume += change;
    sfSound_setVolume(w->game_over, opt->sound_volume);
    sfSound_setVolume(w->mouse_click, opt->sound_volume);
    sfSound_setVolume(w->mouse_over, opt->sound_volume);
    sfSound_setVolume(w->jump, opt->sound_volume);
    sfSound_setVolume(w->win, opt->sound_volume);
    if (opt->sound_volume == 0)
        sfText_setString(opt->s_volume, "0");
    else {
        str = my_str_nb(opt->sound_volume);
        sfText_setString(opt->s_volume, str);
    }
    free(str);
}

void change_music(option_t *opt, int change, window_t *w)
{
    char *str;

    sfSound_play(w->mouse_click);
    if (opt->music_volume == 0 && change == -5)
        return;
    if (opt->music_volume == 100 && change == 5)
        return;
    opt->music_volume += change;
    sfMusic_setVolume(w->music, opt->music_volume);
    if (opt->music_volume == 0)
        sfText_setString(opt->m_volume, "0");
    else {
        str = my_str_nb(opt->music_volume);
        sfText_setString(opt->m_volume, str);
    }
    free(str);
}

void change_endless_mode(option_t *opt, window_t *w)
{
    sfIntRect rect = {0, 0, 120, 120};

    sfSound_play(w->mouse_click);
    if (opt->endless) {
        opt->endless = 0;
        sfSprite_setTextureRect(opt->endl_case, rect);
    } else {
        rect.left += 120;
        opt->endless = 1;
        sfSprite_setTextureRect(opt->endl_case, rect);
    }
}

void change_framerate(option_t *opt, int change, window_t *w)
{
    char *str;

    sfSound_play(w->mouse_click);
    if (opt->framerate == 60 && change == -5)
        return;
    if (opt->framerate == 120 && change == 5)
        return;
    opt->framerate += change;
    sfRenderWindow_setFramerateLimit(w->w, opt->framerate);
    str = my_str_nb(opt->framerate);
    sfText_setString(opt->t_frame, str);
    free(str);
}