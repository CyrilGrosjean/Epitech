/*
** EPITECH PROJECT, 2019
** parallax update
** File description:
** functions for updating parallax
*/

#include "../include/runner.h"

void update_pos(sprite_t *sprite)
{
    if (sprite->pos_sprite.x <= -1920)
        sprite->pos_sprite.x = 0;
}

void update_sky(sprite_t *sprite)
{
    if (!sprite->speed)
        sprite->speed = 1;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(sprite->clock)) > 30) {
        sfClock_restart(sprite->clock);
        sprite->pos_sprite.x -= sprite->speed;
        sprite->speed += 0.0002;
    }
    update_pos(sprite);
    sfSprite_setPosition(sprite->s_sprite, sprite->pos_sprite);
}

void update_clouds(sprite_t *sprite)
{
    if (!sprite->speed)
        sprite->speed = 3;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(sprite->clock)) > 30) {
        sfClock_restart(sprite->clock);
        sprite->pos_sprite.x -= sprite->speed;
        sprite->speed += 0.0006;
    }
    update_pos(sprite);
    sfSprite_setPosition(sprite->s_sprite, sprite->pos_sprite);
}

void update_hills(sprite_t *sprite)
{
    if (!sprite->speed)
        sprite->speed = 4;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(sprite->clock)) > 30) {
        sfClock_restart(sprite->clock);
        sprite->pos_sprite.x -= sprite->speed;
        sprite->speed += 0.0008;
    }
    update_pos(sprite);
    sfSprite_setPosition(sprite->s_sprite, sprite->pos_sprite);
}

void update_trees_floor(sprite_t *sprite)
{
    if (!sprite->speed)
        sprite->speed = 15;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(sprite->clock)) > 30) {
        sfClock_restart(sprite->clock);
        sprite->pos_sprite.x -= sprite->speed;
        sprite->speed += 0.0030;
    }
    update_pos(sprite);
    sfSprite_setPosition(sprite->s_sprite, sprite->pos_sprite);
}