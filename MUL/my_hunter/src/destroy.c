/*
** EPITECH PROJECT, 2019
** destroy
** File description:
** destroy sprites and textures
*/

#include "../include/hunter.h"

void destroy_sprites(window_t *window)
{
    sfSprite_destroy(window->sp_dog);
    sfSprite_destroy(window->sp_background);
    sfSprite_destroy(window->sp_scope);
    sfSprite_destroy(window->sp_duck);
    sfSprite_destroy(window->sp_heart1);
    sfSprite_destroy(window->sp_heart2);
    sfSprite_destroy(window->sp_heart3);
}

void destroy_textures(window_t *window)
{
    sfTexture_destroy(window->te_dog);
    sfTexture_destroy(window->te_background);
    sfTexture_destroy(window->te_scope);
    sfTexture_destroy(window->te_duck);
    sfTexture_destroy(window->te_heart);
}

void destroy_music(window_t *window)
{
    sfMusic_destroy(window->dog_music);
    sfMusic_destroy(window->shoot_sound);
    sfMusic_destroy(window->ambiance_sound);
    sfMusic_destroy(window->duck);
}

void destroy_clock(window_t *window)
{
    sfClock_destroy(window->clock);
    sfClock_destroy(window->anim_dog);
    sfClock_destroy(window->a_duck);
    sfClock_destroy(window->speed);
}

void destroy(window_t *window)
{
    destroy_textures(window);
    destroy_sprites(window);
    destroy_clock(window);
    destroy_music(window);
    sfFont_destroy(window->font);
    sfText_destroy(window->quit);
    sfText_destroy(window->launch);
    sfText_destroy(window->score);
}