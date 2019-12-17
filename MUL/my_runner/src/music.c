/*
** EPITECH PROJECT, 2019
** music
** File description:
** functions to init music
*/

#include "../include/runner.h"

sfMusic *init_music(sfMusic *music, char *path)
{
    music = sfMusic_createFromFile(path);
    if (path[11] == 'm' && path[12] == 'u')
        sfMusic_setLoop(music, sfTrue);
    return (music);
}