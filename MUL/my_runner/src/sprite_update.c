/*
** EPITECH PROJECT, 2019
** sprite update
** File description:
** update functions for others sprites
*/

#include "../include/runner.h"

void update_player_jump(window_t *w)
{
    w->s[5].pos_sprite.y += w->velocity;
    w->velocity += GRAVITY;
    if (w->s[5].pos_sprite.y >= 803) {
        w->s[5].pos_sprite.y = 803;
        w->velocity = 0;
        w->player_is_jumping = 0;
        w->s[5].rect_sprite.left = 0;
        w->s[5].rect_sprite.top = 80;
    }
}

void update_player(sprite_t *sprite, window_t *w)
{
    if (w->player_is_jumping) {
        update_player_jump(w);
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(sprite->clock)) > 90) {
            sfClock_restart(sprite->clock);
            sprite->rect_sprite.left += 80;
        }
        if (sprite->rect_sprite.left > 485)
            sprite->rect_sprite.left = 0;
    } else {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(sprite->clock)) > 70) {
            sfClock_restart(sprite->clock);
            sprite->rect_sprite.left += 80;
        }
        if (sprite->rect_sprite.left > 565)
            sprite->rect_sprite.left = 0;
    }
    sfSprite_setTexture(sprite->s_sprite, sprite->t_sprite, sfNone);
    sfSprite_setTextureRect(sprite->s_sprite, sprite->rect_sprite);
    sfSprite_setPosition(sprite->s_sprite, sprite->pos_sprite);
}

void update_spike(sprite_t *sprite)
{
    if (!sprite->speed)
        sprite->speed = 15;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(sprite->clock)) > 30) {
        sfClock_restart(sprite->clock);
        sprite->pos_sprite.x -= sprite->speed;
        sprite->speed += 0.0030;
    }
    if (sprite->pos_sprite.x <= -240)
        sprite->pos_sprite.x = sprite->original_pos_x;
    sfSprite_setPosition(sprite->s_sprite, sprite->pos_sprite);
}

void testing_lose(window_t *w)
{
    int player_y = w->s[5].pos_sprite.y;
    int ob_x = 0;
    int ob_y = 0;

    for (int i = 0; i < w->object_numb; i += 1) {
        if (w->s[i].type == Spike) {
            ob_x = w->s[i].pos_sprite.x;
            ob_y = w->s[i].pos_sprite.y;
        }
        if (ob_x - 60 <= 50 && ob_x + 100 >= 50)
            if (ob_y <= player_y && ob_y + 15 >= player_y) {
                w->actual_w = 0;
                sfRenderWindow_setMouseCursorVisible(w->w, sfTrue);
            }
    }
}