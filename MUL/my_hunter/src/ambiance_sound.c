/*
** EPITECH PROJECT, 2019
** music
** File description:
** Init sounds of graphical project
*/

#include "../include/hunter.h"

int init_music(window_t *window)
{
    window->shoot_sound = sfMusic_createFromFile("data/music/shoot.ogg");
    window->duck = sfMusic_createFromFile("data/music/duck.ogg");
    window->ambiance_sound = sfMusic_createFromFile("data/music/nature.ogg");
    window->dog_music = sfMusic_createFromFile("data/music/dog.ogg");
    sfMusic_setLoop(window->ambiance_sound, sfTrue);
    sfMusic_setLoop(window->duck, sfTrue);
    sfMusic_play(window->ambiance_sound);
    sfMusic_play(window->duck);
    return (check_error_music(window));
}