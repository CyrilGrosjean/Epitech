/*
** EPITECH PROJECT, 2019
** jump
** File description:
** jump functions
*/

#include "../include/runner.h"

void checking_platf_jump(window_t *w, sprite_t sp, sprite_t *player)
{
    int player_y = player->pos_sprite.y;
    int sprite_y = sp.pos_sprite.y;

    if (sp.pos_sprite.x >= 40 && sp.pos_sprite.x <= 145 && w->velocity >= 0)
        if (player_y >= sprite_y - 30 && player_y <= sprite_y) {
            player->pos_sprite.y = sp.pos_sprite.y - 60;
            w->velocity = 0;
            w->player_is_jumping = 0;
            w->player_is_on_platf = 1;
            player->rect_sprite.left = 0;
            player->rect_sprite.top = 80;
        }
}

void checking_ground_jump(window_t *w, sprite_t *player)
{
    if (player->pos_sprite.y >= 803) {
        player->pos_sprite.y = 803;
        w->velocity = 0;
        w->player_is_jumping = 0;
        player->rect_sprite.left = 0;
        player->rect_sprite.top = 80;
    }
}

void update_player_jump(window_t *w)
{
    w->s[5].pos_sprite.y += w->velocity;
    w->velocity += GRAVITY;
    for (int i = 6; i < w->object_numb; i += 1)
        if (w->s[i].type == Platform)
            checking_platf_jump(w, w->s[i], &w->s[5]);
    checking_ground_jump(w, &w->s[5]);
}

int check_player_isonplatf(sprite_t sp, sprite_t spp, sprite_t player)
{
    if (sp.pos_sprite.x >= 40 && sp.pos_sprite.x <= 145) {
        if (player.pos_sprite.y <= sp.pos_sprite.y - 60)
            return (1);
        return (0);
    } else if (spp.pos_sprite.x >= 140 && spp.pos_sprite.x <= 245) {
        if (spp.pos_sprite.y == sp.pos_sprite.y)
            return (1);
        return (0);
    }
    return (0);
}

void checking_player_platform(window_t *w)
{
    int on_plat = 0;

    if (!w->player_is_on_platf || w->player_is_jumping)
        return;
    for (int i = 7; i < w->object_numb; i += 1) {
        if (w->s[i].type == Platform)
            on_plat = check_player_isonplatf(w->s[i - 1], w->s[i], w->s[5]);
        if (on_plat)
            return;
    }
    if (!on_plat) {
        w->player_is_jumping = 1;
        w->player_is_on_platf = 0;
        w->s[5].rect_sprite.top = 0;
        w->s[5].rect_sprite.left = 0;
    }
}