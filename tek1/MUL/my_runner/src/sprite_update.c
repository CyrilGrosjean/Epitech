/*
** EPITECH PROJECT, 2019
** sprite update
** File description:
** update functions for others sprites
*/

#include "../include/runner.h"

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
    checking_player_platform(w);
    sfSprite_setTexture(sprite->s_sprite, sprite->t_sprite, sfNone);
    sfSprite_setTextureRect(sprite->s_sprite, sprite->rect_sprite);
    sfSprite_setPosition(sprite->s_sprite, sprite->pos_sprite);
}

void update_spike_platform(sprite_t *sprite, option_t *opt)
{
    if (!sprite->speed)
        sprite->speed = 15;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(sprite->clock)) > 30) {
        sfClock_restart(sprite->clock);
        sprite->pos_sprite.x -= sprite->speed;
        sprite->speed += (0.0030 * opt->how_difficulty);
    }
    if (sprite->pos_sprite.x <= -240 && opt->endless)
        sprite->pos_sprite.x = 1920 + sprite->original_pos_x;
    sfSprite_setPosition(sprite->s_sprite, sprite->pos_sprite);
}

void update_end(window_t *w, option_t *opt)
{
    if (w->actual_w == 1)
        w->score_nb += 1;
    if (!opt->endless && w->actual_w == 1) {
        w->end -= w->s[3].speed;
        if (w->end < -500) {
            sfSound_play(w->win);
            check_best_score(w);
            w->actual_w = 0;
            sfRenderWindow_setMouseCursorVisible(w->w, sfTrue);
        }
    }
}

void lose_conditions(window_t *w, int ob_x, int ob_y, int player_y)
{
    if (ob_x - 60 <= 50 && ob_x + 100 >= 45)
        if (ob_y <= player_y && ob_y + 15 >= player_y) {
            sfSound_play(w->game_over);
            w->actual_w = 0;
            check_best_score(w);
            sfRenderWindow_setMouseCursorVisible(w->w, sfTrue);
        }
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
        lose_conditions(w, ob_x, ob_y, player_y);
    }
}