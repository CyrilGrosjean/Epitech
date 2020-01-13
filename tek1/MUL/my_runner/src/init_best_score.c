/*
** EPITECH PROJECT, 2020
** init best scores
** File description:
** functions to init best score
*/

#include "../include/runner.h"

void init_best_score(window_t *w, sfVector2f *positions)
{
    w->best_label = init_text(w->best_label, "TOP 3", positions[5], w->font);
    w->best1 = init_text(w->best1, w->score_1, positions[6], w->font);
    w->best2 = init_text(w->best2, w->score_2, positions[7], w->font);
    w->best3 = init_text(w->best3, w->score_3, positions[8], w->font);
}