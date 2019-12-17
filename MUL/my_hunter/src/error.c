/*
** EPITECH PROJECT, 2019
** error
** File description:
** Check load errors
*/

#include "../include/hunter.h"

int check_error_texture_sprite(window_t *window)
{
    int error = 0;

    if (!window->te_duck || !window->sp_duck || !window->te_background)
        error += 1;
    if (!window->sp_background || !window->te_scope || !window->sp_scope)
        error += 1;
    if (!window->te_dog || !window->sp_dog)
        error += 1;
    return (error);
}

int check_error_music(window_t *window)
{
    int error = 0;

    if (!window->shoot_sound || !window->duck || !window->dog_music)
        error += 1;
    if (!window->ambiance_sound)
        error += 1;
    return (error);
}

int check_error_clock(window_t *window)
{
    int error = 0;

    if (!window->clock || !window->a_duck || !window->anim_dog)
        error += 1;
    if (!window->rel_scope || !window->speed)
        error += 1;
    return (error);
}

int check_error_text(window_t *window)
{
    int error = 0;
    if (!window->font || !window->launch || !window->score)
        error += 1;
    if (!window->quit)
        error += 1;
    return (error);
}