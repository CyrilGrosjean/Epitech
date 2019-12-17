/*
** EPITECH PROJECT, 2019
** clock
** File description:
** Create clock
*/

#include "../include/hunter.h"

int create_clock(window_t *window)
{
    window->clock = sfClock_create();
    window->a_duck = sfClock_create();
    window->anim_dog = sfClock_create();
    window->rel_scope = sfClock_create();
    window->speed = sfClock_create();
    return (check_error_clock(window));
}