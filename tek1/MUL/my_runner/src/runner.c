/*
** EPITECH PROJECT, 2019
** runner
** File description:
** main function for display window
*/

#include "../include/runner.h"

sprite_t update(sprite_t sprite)
{
    if (sprite.type == Sky)
        update_sky(&sprite);
    if (sprite.type == Cloud)
        update_clouds(&sprite);
    if (sprite.type == Hills)
        update_hills(&sprite);
    if (sprite.type == Trees || sprite.type == Floor)
        update_trees_floor(&sprite);
    if (sprite.type == Spike)
        update_spike(&sprite);
    return (sprite);
}

void display_window(window_t *w)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(w->refresh)) > 40) {
        sfClock_restart(w->refresh);
        sfRenderWindow_clear(w->w, sfBlack);
    }
    for (int i = 0; i < w->object_numb; i += 1) {
        if (i == 5)
            update_player(&w->s[i], w);
        else if ((!w->actual_w && w->s[i].type != Spike) || w->actual_w)
            w->s[i] = w->s[i].func(w->s[i]);
        sfRenderWindow_drawSprite(w->w, w->s[i].s_sprite, NULL);
    }
    if (!w->actual_w) {
        reset_spikes(w);
        sfRenderWindow_drawText(w->w, w->play, NULL);
        sfRenderWindow_drawText(w->w, w->options, NULL);
        sfRenderWindow_drawText(w->w, w->leave, NULL);
    }
    sfRenderWindow_drawText(w->w, w->score, NULL);
    testing_lose(w);
}

void get_event(window_t *w)
{
    while (sfRenderWindow_pollEvent(w->w, &w->event)) {
        if (w->event.type == sfEvtClosed)
            sfRenderWindow_close(w->w);
        if (w->event.type == sfEvtKeyPressed)
            manage_key_pressed(w->event.key, w);
        manage_mouse(w);
    }
}

int runner(window_t *w)
{
    w->w = sfRenderWindow_create(w->mode, w->name, sfResize | sfClose, NULL);
    if (!w->w)
        return (84);
    sfRenderWindow_setFramerateLimit(w->w, 60);
    sfMusic_play(w->music);
    while (sfRenderWindow_isOpen(w->w)) {
        display_window(w);
        get_event(w);
        sfRenderWindow_display(w->w);
    }
    destroy_objects(w);
    sfRenderWindow_destroy(w->w);
    return (0);
}