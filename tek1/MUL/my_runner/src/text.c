/*
** EPITECH PROJECT, 2019
** text
** File description:
** functions for text object
*/

#include "../include/runner.h"

void update_text_score(window_t *w)
{
    sfText_setString(w->best1, w->score_1);
    sfText_setString(w->best2, w->score_2);
    sfText_setString(w->best3, w->score_3);
}

sfText *set_color_text(sfText *sp_text, char *text)
{
    if (text[0] == 'Y')
        sfText_setColor(sp_text, sfYellow);
    return (sp_text);
}

sfText *init_text(sfText *sp_text, char *text, sfVector2f pos, sfFont *font)
{
    sp_text = sfText_create();
    sfText_setString(sp_text, text);
    sfText_setFont(sp_text, font);
    sfText_setCharacterSize(sp_text, 50);
    sfText_setPosition(sp_text, pos);
    sp_text = set_color_text(sp_text, text);
    return (sp_text);
}