/*
** EPITECH PROJECT, 2019
** init code
** File description:
** Initialisation code
*/

#include "../include/hunter.h"

void display_window(window_t *window)
{
    if (window->window == 0) {
        refresh_main_menu(window);
        move_scope(window);
        draw(window, window->window);
    } else if (window->window == 1) {
        animation_duck(window);
        main_refresh(window);
        animation_dog(window);
        move_scope(window);
        if (sfTime_asSeconds(sfClock_getElapsedTime(window->speed)) > 8) {
            sfClock_restart(window->speed);
            window->speed_duck += 10;
        }
        draw(window, window->window);
    }
}

int settexture_and_sprites(window_t *window)
{
    heart_sprite(window);
    window->te_duck = sfTexture_createFromFile("data/img/duck.png", NULL);
    window->sp_duck = sfSprite_create();
    sfSprite_setTexture(window->sp_duck, window->te_duck, sfNone);
    sfSprite_setTextureRect(window->sp_duck, window->rect_duck);
    window->te_background = sfTexture_createFromFile("data/img/bg.png", NULL);
    window->sp_background = sfSprite_create();
    sfSprite_setTexture(window->sp_background, window->te_background, sfNone);
    sfSprite_setTextureRect(window->sp_background, window->rect_background);
    window->te_scope = sfTexture_createFromFile("data/img/scope.png", NULL);
    window->sp_scope = sfSprite_create();
    sfSprite_setTexture(window->sp_scope, window->te_scope, sfNone);
    sfSprite_setTextureRect(window->sp_scope, window->rect_scope);
    window->te_dog = sfTexture_createFromFile("data/img/dog.png", NULL);
    window->sp_dog = sfSprite_create();
    sfSprite_setTexture(window->sp_dog, window->te_dog, sfNone);
    sfSprite_setTextureRect(window->sp_dog, window->rect_dog);
    return (check_error_texture_sprite(window));
}

int variable_initialisation(window_t *window)
{
    int error = 0;

    error += init_music(window);
    error += create_clock(window);
    error += settexture_and_sprites(window);
    error += init_text(window);
    return (error);
}

int main_window(window_t *window)
{
    srand(time(0));
    window->window = 0;
    window->pos_duck.x = 0;
    window->pos_duck.y = (rand() % 1080);
    if (window->pos_duck.y > 600)
        window->pos_duck.y /= 2;
    window->pos_dog.x = -320;
    window->pos_dog.y = 725;
    if (variable_initialisation(window) != 0)
        return (84);
    sfSprite_setPosition(window->sp_dog, window->pos_dog);
    sfRenderWindow_setFramerateLimit(window->w, 60);
    while (sfRenderWindow_isOpen(window->w)) {
        display_window(window);
        sfRenderWindow_display(window->w);
    }
    destroy(window);
    sfRenderWindow_destroy(window->w);
    return (0);
}

int init(void)
{
    window_t window;
    sfVideoMode mode = {1920, 1080, 32};
    sfIntRect rect_duck = {0, 0, 110, 110};
    sfIntRect rect_bg = {0, 30, 1920, 1080};
    sfIntRect rect_scope = {0, 0, 90, 90};
    sfIntRect rect_dog = {0, 0, 320, 320};

    window.speed_duck = 30;
    window.rect_duck = rect_duck;
    window.rect_background = rect_bg;
    window.rect_scope = rect_scope;
    window.rect_dog = rect_dog;
    window.n = "myHunter";
    window.mode = mode;
    window.w = sfRenderWindow_create(mode, window.n, sfResize | sfClose, NULL);
    if (!window.w)
        return (84);
    sfRenderWindow_setMouseCursorVisible(window.w, sfFalse);
    return (main_window(&window));
}