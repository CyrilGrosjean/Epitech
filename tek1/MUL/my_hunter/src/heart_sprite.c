/*
** EPITECH PROJECT, 2019
** heart_sprite
** File description:
** create sprites for heart
*/

#include "../include/hunter.h"

static sfVector2f vect[3] = {
    {0, 0},
    {60, 0},
    {120, 0}
};

void heart_sprite(window_t *window)
{
    sfIntRect rect = {0, 0, 75, 75};

    window->rect_heart1 = rect;
    window->rect_heart2 = rect;
    window->rect_heart3 = rect;
    window->te_heart = sfTexture_createFromFile("data/img/heart.png", NULL);
    window->sp_heart1 = sfSprite_create();
    window->sp_heart2 = sfSprite_create();
    window->sp_heart3 = sfSprite_create();
    sfSprite_setTexture(window->sp_heart1, window->te_heart, sfNone);
    sfSprite_setTexture(window->sp_heart2, window->te_heart, sfNone);
    sfSprite_setTexture(window->sp_heart3, window->te_heart, sfNone);
    sfSprite_setTextureRect(window->sp_heart1, window->rect_heart1);
    sfSprite_setTextureRect(window->sp_heart2, window->rect_heart2);
    sfSprite_setTextureRect(window->sp_heart3, window->rect_heart3);
    sfSprite_setPosition(window->sp_heart1, vect[0]);
    sfSprite_setPosition(window->sp_heart2, vect[1]);
    sfSprite_setPosition(window->sp_heart3, vect[2]);
}

void heart_refresh_texture(window_t *window)
{
    sfSprite_setTexture(window->sp_heart1, window->te_heart, sfNone);
    sfSprite_setTexture(window->sp_heart2, window->te_heart, sfNone);
    sfSprite_setTexture(window->sp_heart3, window->te_heart, sfNone);
    sfSprite_setTextureRect(window->sp_heart1, window->rect_heart1);
    sfSprite_setTextureRect(window->sp_heart2, window->rect_heart2);
    sfSprite_setTextureRect(window->sp_heart3, window->rect_heart3);
}

void change_heart(window_t *window)
{
    if (window->lives == 3) {
        window->rect_heart1.left = 0;
        window->rect_heart2.left = 0;
        window->rect_heart3.left = 0;
    }
    if (window->lives == 2) {
        window->rect_heart1.left = 0;
        window->rect_heart2.left = 0;
        window->rect_heart3.left = 75;
    }
    if (window->lives == 1) {
        window->rect_heart1.left = 0;
        window->rect_heart2.left = 75;
        window->rect_heart3.left = 75;
    }
    heart_refresh_texture(window);
}