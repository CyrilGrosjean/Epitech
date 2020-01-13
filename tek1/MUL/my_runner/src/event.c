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
    if (event.code == sfKeySpace && w->actual_w == 1)
        if (!w->player_is_jumping) {
            sfSound_play(w->jump);
            w->player_is_jumping = 1;
            w->player_is_on_platf = 0;
            w->velocity = -20;
            w->s[5].rect_sprite.top = 0;
            w->s[5].rect_sprite.left = 0;
        }
}

void check_mouse_position(sfMouseMoveEvent event, window_t *w)
{
    static int button = -1;

    sfText_setColor(w->play, sfWhite);
    sfText_setColor(w->leave, sfWhite);
    sfText_setColor(w->options, sfWhite);
    if (event.x >= 1600 && event.x <= 1720)
        if (event.y >= 715 && event.y <= 750)
            button = selected_play(w, button);
    if (event.x >= 1600 && event.x <= 1800)
        if (event.y >= 770 && event.y <= 800)
            button = selected_options(w, button);
    if (event.x >= 1600 && event.x <= 1705)
        if (event.y >= 820 && event.y <= 850)
            button = selected_leave(w, button);
}

void manage_click_event(sfMouseButtonEvent event, window_t *w) // POSSIBLE C1
{
    if (!w->actual_w) {
        if (event.x >= 1600 && event.x <= 1720 && !w->actual_w)
            if (event.y >= 715 && event.y <= 750) {
                sfSound_play(w->mouse_click);
                sfRenderWindow_setMouseCursorVisible(w->w, sfFalse);
                reset_speed(w);
            }
        if (event.x >= 1600 && event.x <= 1800 && !w->actual_w)
            if (event.y >= 770 && event.y <= 800) {
                sfSound_play(w->mouse_click);
                w->actual_w = -1;
            }
        if (event.x >= 1600 && event.x <= 1705 && !w->actual_w)
            if (event.y >= 820 && event.y <= 850) {
                sfSound_play(w->mouse_click);
                sfRenderWindow_close(w->w);
            }
    }
}

void manage_mouse(window_t *w)
{
    if (!w->actual_w)
        check_mouse_position(w->event.mouseMove, w);
    if (w->event.type == sfEvtMouseButtonPressed)
        manage_click_event(w->event.mouseButton, w);
}