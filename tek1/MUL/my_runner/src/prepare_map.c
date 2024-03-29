/*
** EPITECH PROJECT, 2019
** prepare map
** File description:
** functions for prepare map objects
*/

#include "../include/runner.h"

void create_platform(window_t *w, char **tab, int x, int y)
{
    char path[22] = "data/img/platform.png";
    sfIntRect rect = {0, 0, 120, 120};

    if (tab[y][x] == '2') {
        w->s[w->object_numb] = create_object(path, rect, Platform, w);
        w->s[w->object_numb - 1].pos_sprite.x = 1920 + (120 * x);
        w->s[w->object_numb - 1].original_pos_x = 1920 + (120 * x);
        w->s[w->object_numb - 1].pos_sprite.y = 113 * y;
        sfSprite_setPosition(w->s[w->object_numb - 1].s_sprite,\
        w->s[w->object_numb - 1].pos_sprite);
    }
}

void create_spike(window_t *w, char **tab, int x, int y)
{
    char path[20] = "data/img/spikes.png";
    sfIntRect rect = {0, 0, 120, 120};

    if (tab[y][x] == '1') {
        w->s[w->object_numb] = create_object(path, rect, Spike, w);
        w->s[w->object_numb - 1].pos_sprite.x = 1920 + (120 * x);
        w->s[w->object_numb - 1].original_pos_x = 1920 + (120 * x);
        w->s[w->object_numb - 1].pos_sprite.y = 113 * y;
        sfSprite_setPosition(w->s[w->object_numb - 1].s_sprite,\
        w->s[w->object_numb - 1].pos_sprite);
    }
    if (tab[y][x + 1] == '\0') {
        w->end = 1920 + (130 * x);
        w->origin_end = w->end;
    }
}

window_t make_map(window_t w, char *str)
{
    char **tab = str_to_wordarray(str);

    for (int y = 0; y < 9; y += 1)
        for (int x = 0; tab[y][x]; x += 1) {
            create_spike(&w, tab, x, y);
            create_platform(&w, tab, x, y);
        }
    for (int i = 0; i < 9; i += 1)
        free(tab[i]);
    free(tab);
    return (w);
}