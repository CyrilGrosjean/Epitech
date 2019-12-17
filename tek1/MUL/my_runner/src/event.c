/*
** EPITECH PROJECT, 2019
** event
** File description:
** event functions
*/

#include "../include/runner.h"

void manage_key_pressed(sfKeyEvent event, window_t *w)
{
    if (event.code == sfKeyEscape)
        sfRenderWindow_close(w->w);
    if (event.code == sfKeySpace && w->actual_w)
        if (!w->player_is_jumping) {
            sfMusic_play(w->jump);
            w->player_is_jumping = 1;
            w->velocity = -20;
            w->s[5].rect_sprite.top = 0;
            w->s[5].rect_sprite.left = 0;
        }
}

void check_mouse_position(sfMouseMoveEvent event, window_t *w)
{
    sfText_setColor(w->play, sfWhite);
    sfText_setColor(w->leave, sfWhite);
    sfText_setColor(w->options, sfWhite);
    if (event.x >= 1600 && event.x <= 1720)
        if (event.y >= 715 && event.y <= 750) {
            sfText_setColor(w->play, sfRed);
            sfMusic_play(w->mouse_over);
        }
    if (event.x >= 1600 && event.x <= 1800)
        if (event.y >= 770 && event.y <= 800) {
            sfText_setColor(w->options, sfRed);
            sfMusic_play(w->mouse_over);
        }
    if (event.x >= 1600 && event.x <= 1705)
        if (event.y >= 820 && event.y <= 850) {
            sfText_setColor(w->leave, sfRed);
            sfMusic_play(w->mouse_over);
        }
}

void manage_click_event(sfMouseButtonEvent event, window_t *w)
{
    if (event.x >= 1600 && event.x <= 1720)
        if (event.y >= 715 && event.y <= 750) {
            w->actual_w = 1;
            sfRenderWindow_setMouseCursorVisible(w->w, sfFalse);
            reset_speed(w);
        }
    if (event.x >= 1600 && event.x <= 1800)
        if (event.y >= 770 && event.y <= 800)
            sfRenderWindow_close(w->w);
    if (event.x >= 1600 && event.x <= 1705)
        if (event.y >= 820 && event.y <= 850)
            sfRenderWindow_close(w->w);
}

void manage_mouse(window_t *w)
{
    if (!w->actual_w)
        check_mouse_position(w->event.mouseMove, w);
    if (w->event.type == sfEvtMouseButtonPressed)
        manage_click_event(w->event.mouseButton, w);
}