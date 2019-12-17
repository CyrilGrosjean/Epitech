/*
** EPITECH PROJECT, 2019
** reset
** File description:
** reset functions when start
*/

#include "../include/runner.h"

void reset_speed(window_t *w)
{
    for (int i = 0; i < w->object_numb; i += 1) {
        if (w->s[i].type == Spike || w->s[i].type == Floor)
            w->s[i].speed = 15;
        if (w->s[i].type == Trees)
            w->s[i].speed = 15;
        if (w->s[i].type == Hills)
            w->s[i].speed = 4;
        if (w->s[i].type == Cloud)
            w->s[i].speed = 3;
        if (w->s[i].type == Sky)
            w->s[i].speed = 1;
    }
}

void reset_spikes(window_t *w)
{
    for (int i = 6; i < w->object_numb; i += 1) {
        w->s[i].pos_sprite.x = w->s[i].original_pos_x;
        sfSprite_setPosition(w->s[i].s_sprite, w->s[i].pos_sprite);
        sfRenderWindow_drawSprite(w->w, w->s[i].s_sprite, NULL);
    }
}