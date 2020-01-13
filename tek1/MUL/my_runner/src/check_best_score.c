/*
** EPITECH PROJECT, 2020
** check best score
** File description:
** functions to check best score
*/

#include "../include/runner.h"

int compare_score(char *score_played, char *best_score, int index)
{
    int score_pl = count_len_line(score_played, 0);
    int score_best = count_len_line(best_score, index) + 1;

    if (score_pl > score_best)
        return (1);
    if (score_pl < score_best)
        return (0);
    for (int i = 0; score_played[i]; i += 1) {
        if (score_played[i] > best_score[index])
            return (1);
        if (score_played[i] < best_score[index])
            return (0);
        index += 1;
    }
    return (0);
}

int get_index_start_score(char *bs)
{
    int index = 0;

    for (index = 0; bs[index]; index += 1)
        if (bs[index] == '-')
            break;
    return (index += 2);
}

char *new_score_name(char *score, window_t *w)
{
    int score_len = count_len_line(score, 0);
    int name_len = count_len_line(w->player_name, 0);
    char *str = malloc(sizeof(char) * (score_len + name_len + 4));
    int index = 0;

    str[score_len + name_len + 3] = '\0';
    for (int i = 0; w->player_name[i]; i += 1) {
        str[index] = w->player_name[i];
        index += 1;
    }
    str[index] = ' ';
    str[index + 1] = '-';
    str[index + 2] = ' ';
    index += 3;
    for (int i = 0; score[i]; i += 1) {
        str[index] = score[i];
        index += 1;
    }
    update_text_score(w);
    return (str);
}

void move_places(int new_best, char *score, window_t *w)
{
    char *old_score = NULL;
    char *new_score = new_score_name(score, w);

    if (new_best == 1) {
        old_score = w->score_2;
        w->score_2 = w->score_1;
        w->score_3 = old_score;
        w->score_1 = new_score;
        return;
    } else if (new_best == 2) {
        w->score_3 = w->score_2;
        w->score_2 = new_score;
        return;
    } else
        w->score_3 = new_score;
}

void check_best_score(window_t *w)
{
    char *score = my_str_nb(w->score_nb);
    int index = get_index_start_score(w->score_1);

    if (compare_score(score, w->score_1, index)) {
        move_places(1, score, w);
        return;
    }
    index = get_index_start_score(w->score_2);
    if (compare_score(score, w->score_2, index)) {
        move_places(2, score, w);
        return;
    }
    index = get_index_start_score(w->score_3);
    if (compare_score(score, w->score_3, index)) {
        move_places(3, score, w);
        return;
    }
    free(score);
}