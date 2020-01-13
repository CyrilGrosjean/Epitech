/*
** EPITECH PROJECT, 2019
** option event
** File description:
** event functions for options
*/

#include "../include/runner.h"

void return_main_menu(window_t *w)
{
    sfSound_play(w->mouse_click);
    w->actual_w = 0;
}

void manage_click_options(window_t *w, sfMouseButtonEvent mouse, option_t *opt)
{
    if (mouse.x >= 755 && mouse.x <= 810 && mouse.y >= 195 && mouse.y <= 250)
        change_difficulty(opt, -1, w);
    if (mouse.x >= 1000 && mouse.x <= 1060 && mouse.y >= 195 && mouse.y <= 250)
        change_difficulty(opt, 1, w);
    if (mouse.x >= 755 && mouse.x <= 810 && mouse.y >= 295 && mouse.y <= 350)
        change_sound(opt, -5, w);
    if (mouse.x >= 1000 && mouse.x <= 1060 && mouse.y >= 295 && mouse.y <= 350)
        change_sound(opt, 5, w);
    if (mouse.x >= 755 && mouse.x <= 810 && mouse.y >= 395 && mouse.y <= 450)
        change_music(opt, -5, w);
    if (mouse.x >= 1000 && mouse.x <= 1060 && mouse.y >= 395 && mouse.y <= 450)
        change_music(opt, 5, w);
    if (mouse.x >= 755 && mouse.x <= 810 && mouse.y >= 495 && mouse.y <= 550)
        change_framerate(opt, -5, w);
    if (mouse.x >= 1000 && mouse.x <= 1060 && mouse.y >= 495 && mouse.y <= 550)
        change_framerate(opt, 5, w);
    if (mouse.x >= 1355 && mouse.x <= 1465 && mouse.y >= 455 && mouse.y <= 565)
        change_endless_mode(opt, w);
    if (mouse.x >= 900 && mouse.x <= 980 && mouse.y >= 810 && mouse.y <= 830)
        return_main_menu(w);
}

void manage_key_options(window_t *w, sfKeyEvent key)
{
    if (key.code == sfKeyEscape)
        sfRenderWindow_destroy(w->w);
}

void get_event_options(window_t *w, option_t *opt)
{
    if (w->event.type == sfEvtMouseButtonPressed)
        manage_click_options(w, w->event.mouseButton, opt);
    if (w->event.type == sfEvtKeyPressed)
        manage_key_options(w, w->event.key);
}