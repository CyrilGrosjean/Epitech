/*
** EPITECH PROJECT, 2019
** runner
** File description:
** main function for display window
*/

#include "../include/runner.h"

sprite_t update(sprite_t sprite, option_t *opt)
{
    if (sprite.type == Sky)
        update_sky(&sprite, opt);
    if (sprite.type == Cloud)
        update_clouds(&sprite, opt);
    if (sprite.type == Hills)
        update_hills(&sprite, opt);
    if (sprite.type == Trees || sprite.type == Floor)
        update_trees_floor(&sprite, opt);
    if (sprite.type == Spike || sprite.type == Platform)
        update_spike_platform(&sprite, opt);
    return (sprite);
}

void display_window(window_t *w, option_t *opt)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(w->refresh)) > 30) {
        sfClock_restart(w->refresh);
        update_end(w, opt);
        sfRenderWindow_clear(w->w, sfBlack);
    }
    for (int i = 0; i < w->object_numb; i += 1) {
        if (i == 5)
            update_player(&w->s[i], w);
        else if ((w->actual_w < 1 && w->s[i].type != Spike) || w->actual_w == 1)
            w->s[i] = w->s[i].func(w->s[i], opt);
        sfRenderWindow_drawSprite(w->w, w->s[i].s_sprite, NULL);
    }
    if (!w->actual_w)
        display_main_menu(w);
    if (w->actual_w == -1)
        display_option_menu(w, opt);
    update_score(w);
    sfRenderWindow_drawText(w->w, w->score, NULL);
    testing_lose(w);
}

void get_event(window_t *w, option_t *opt) // C1 possible
{
    while (sfRenderWindow_pollEvent(w->w, &w->event)) {
        if (w->event.type == sfEvtClosed)
            sfRenderWindow_close(w->w);
        if (w->event.type == sfEvtKeyPressed && w->actual_w > -1)
            manage_key_pressed(w->event.key, w);
        if (w->actual_w > -1)
            manage_mouse(w);
        else
            get_event_options(w, opt);
    }
}

int runner(window_t *w, option_t *opt)
{
    w->w = sfRenderWindow_create(w->mode, w->name, sfResize | sfClose, NULL);
    if (!w->w)
        return (84);
    sfRenderWindow_setFramerateLimit(w->w, 60);
    sfMusic_play(w->music);
    while (sfRenderWindow_isOpen(w->w)) {
        display_window(w, opt);
        get_event(w, opt);
        sfRenderWindow_display(w->w);
    }
    destroy_objects(w);
    sfRenderWindow_destroy(w->w);
    return (0);
}