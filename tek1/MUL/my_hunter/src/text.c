/*
** EPITECH PROJECT, 2019
** text
** File description:
** text initialisation
*/

#include "../include/hunter.h"

static sfVector2f vect[3] = {
    {1700, 700},
    {1700, 750},
    {900, 0}
};

int init_text(window_t *window)
{
    window->font = sfFont_createFromFile("data/font/font.ttf");
    window->launch = sfText_create();
    window->score = sfText_create();
    window->quit = sfText_create();
    sfText_setString(window->launch, "Play");
    sfText_setString(window->quit, "Exit");
    sfText_setString(window->score, "0");
    sfText_setFont(window->launch, window->font);
    sfText_setFont(window->score, window->font);
    sfText_setFont(window->quit, window->font);
    sfText_setCharacterSize(window->launch, 50);
    sfText_setCharacterSize(window->score, 25);
    sfText_setCharacterSize(window->quit, 50);
    sfText_setPosition(window->launch, vect[0]);
    sfText_setPosition(window->quit, vect[1]);
    sfText_setPosition(window->score, vect[2]);
    return (check_error_text(window));
}

void update_score(window_t *window)
{
    char *str = my_int_to_str(window->score_point);

    sfText_setString(window->score, str);
    free(str);
}