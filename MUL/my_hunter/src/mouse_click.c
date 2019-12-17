/*
** EPITECH PROJECT, 2019
** mouse click
** File description:
** Get entity of mouse click
*/

#include "../include/hunter.h"

void duck_click(sfMouseButtonEvent ev, window_t *window)
{
    if (ev.x >= window->pos_duck.x && ev.x <= window->pos_duck.x + 110)
        if (ev.y >= window->pos_duck.y && ev.y <= window->pos_duck.y + 110) {
            window->pos_duck.x = -220;
            srand(time(0));
            window->pos_duck.y = (rand() % 1080);
            if (window->pos_duck.y > 600)
                window->pos_duck.y /= 2;
            window->score_point += 1;
            update_score(window);
        }
}

void dog_click(sfMouseButtonEvent ev, window_t *window)
{
    if (ev.x >= window->pos_dog.x && ev.x <= window->pos_dog.x + 320)
        if (ev.y >= window->pos_dog.y && ev.y <= window->pos_dog.y + 320) {
            window->pos_dog.x = 1920;
            window->speed_duck /= 2;
            sfMusic_stop(window->dog_music);
        }
    if (window->speed_duck <= 0)
        window->speed_duck = 5;
}

void text_click(sfMouseButtonEvent ev, window_t *window)
{
    if (ev.x >= 1700 && ev.x <= 1820)
        if (ev.y >= 700 && ev.y < 750) {
            window->window = 1;
            sfClock_restart(window->speed);
            window->score_point = 0;
            window->lives = 3;
            window->speed_duck = 10;
            change_heart(window);
            sfText_setString(window->score, "0");
        }
    if (ev.x >= 1700 && ev.x <= 1810)
        if (ev.y >= 750 && ev.y <= 800)
            sfRenderWindow_close(window->w);
}