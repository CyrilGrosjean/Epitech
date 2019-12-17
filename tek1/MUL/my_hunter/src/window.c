/*
** EPITECH PROJECT, 2019
** window
** File description:
** Window functions
*/

#include "../include/hunter.h"

void animation_duck(window_t *window)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(window->a_duck)) > 100) {
        sfClock_restart(window->a_duck);
        anim_duck(window);
    }
}

void main_refresh(window_t *window)
{
    srand(time(0));
    if (window->spawn_dog != 1) {
        window->spawn_dog = (rand() % 20);
        if (window->spawn_dog == 1)
            sfMusic_play(window->dog_music);
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(window->clock)) > 40) {
        sfClock_restart(window->clock);
        move_duck(window);
        move_dog(window);
        while (sfRenderWindow_pollEvent(window->w, &window->event))
            analyse_event(window, window->event);
        sfRenderWindow_clear(window->w, sfBlack);
    }
}

void animation_dog(window_t *window)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(window->anim_dog)) > 70)
        if (window->spawn_dog == 1) {
            sfClock_restart(window->anim_dog);
            anim_dog(window);
        }
}

void refresh_main_menu(window_t *window)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(window->clock)) > 40) {
        sfClock_restart(window->clock);
        sfClock_restart(window->speed);
        while (sfRenderWindow_pollEvent(window->w, &window->event))
            analyse_event(window, window->event);
        sfRenderWindow_clear(window->w, sfBlack);
    }
}

void draw(window_t *window, int w)
{
    if (w == 0) {
        sfRenderWindow_drawSprite(window->w, window->sp_background, NULL);
        sfRenderWindow_drawText(window->w, window->score, NULL);
        sfRenderWindow_drawText(window->w, window->launch, NULL);
        sfRenderWindow_drawText(window->w, window->quit, NULL);
        sfRenderWindow_drawSprite(window->w, window->sp_scope, NULL);
    } else if (w == 1) {
        sfRenderWindow_drawSprite(window->w, window->sp_background, NULL);
        sfRenderWindow_drawSprite(window->w, window->sp_duck, NULL);
        sfRenderWindow_drawSprite(window->w, window->sp_dog, NULL);
        sfRenderWindow_drawText(window->w, window->score, NULL);
        sfRenderWindow_drawSprite(window->w, window->sp_scope, NULL);
        sfRenderWindow_drawSprite(window->w, window->sp_heart1, NULL);
        sfRenderWindow_drawSprite(window->w, window->sp_heart2, NULL);
        sfRenderWindow_drawSprite(window->w, window->sp_heart3, NULL);
    }
}