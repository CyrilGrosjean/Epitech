/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** create sprite and animations
*/

#include "../include/hunter.h"

void move_duck(window_t *window)
{
    if (window->pos_duck.x >= 1920) {
        window->pos_duck.x = -100;
        srand(time(0));
        window->pos_duck.y = (rand() % 1080);
        if (window->pos_duck.y > 600)
            window->pos_duck.y /= 2;
        window->lives -= 1;
        if (window->lives == 0)
            window->window = 0;
        change_heart(window);
    } else
        window->pos_duck.x += window->speed_duck;
    sfSprite_setPosition(window->sp_duck, window->pos_duck);
}

void anim_duck(window_t *window)
{
    if (window->rect_duck.left >= 220)
        window->rect_duck.left = 0;
    else
        window->rect_duck.left += 110;
    sfSprite_setTexture(window->sp_duck, window->te_duck, sfNone);
    sfSprite_setTextureRect(window->sp_duck, window->rect_duck);
}

void anim_dog(window_t *window)
{
    if (window->rect_dog.left >= 12800)
        window->rect_dog.left = 0;
    else
        window->rect_dog.left += 320;
    sfSprite_setTexture(window->sp_dog, window->te_dog, sfNone);
    sfSprite_setTextureRect(window->sp_dog, window->rect_dog);
}

int move_dog(window_t *window)
{
    if (window->spawn_dog != 1) {
        window->pos_dog.x = -320;
        return (0);
    }
    window->pos_dog.y = 725;
    if (window->pos_dog.x >= 1920) {
        window->pos_dog.x = -320;
        window->spawn_dog = 0;
    } else
        window->pos_dog.x += 30;
    sfSprite_setPosition(window->sp_dog, window->pos_dog);
    return (0);
}

void move_scope(window_t *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->w);

    window->pos_scope.x = mouse.x - 45;
    window->pos_scope.y = mouse.y - 45;
    sfSprite_setPosition(window->sp_scope, window->pos_scope);
}