/*
** EPITECH PROJECT, 2019
** music
** File description:
** functions to init music
*/

#include "../include/runner.h"

const char *path[5] = {
    "data/sound/jump.ogg",
    "data/sound/mouse click.ogg",
    "data/sound/mouse over.ogg",
    "data/sound/game over.ogg",
    "data/sound/win.ogg"
};

void init_sound(window_t *w)
{
    w->mouse_click = sfSound_create();
    w->jump = sfSound_create();
    w->mouse_over = sfSound_create();
    w->game_over = sfSound_create();
    w->win = sfSound_create();
    w->mouse_click_buff = sfSoundBuffer_createFromFile(path[1]);
    w->jump_buff = sfSoundBuffer_createFromFile(path[0]);
    w->mouse_over_buff = sfSoundBuffer_createFromFile(path[2]);
    w->game_over_buff = sfSoundBuffer_createFromFile(path[3]);
    w->win_buff = sfSoundBuffer_createFromFile(path[4]);
    sfSound_setBuffer(w->mouse_click, w->mouse_click_buff);
    sfSound_setBuffer(w->mouse_over, w->mouse_over_buff);
    sfSound_setBuffer(w->jump, w->jump_buff);
    sfSound_setBuffer(w->game_over, w->game_over_buff);
    sfSound_setBuffer(w->win, w->win_buff);
}

sfMusic *init_music(sfMusic *music, char *path)
{
    music = sfMusic_createFromFile(path);
    if (path[11] == 'm' && path[12] == 'u')
        sfMusic_setLoop(music, sfTrue);
    return (music);
}