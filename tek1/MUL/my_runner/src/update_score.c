/*
** EPITECH PROJECT, 2019
** update score
** File description:
** update score for runner
*/

#include "../include/runner.h"

char *my_str_nb(int nb)
{
    int n = 0;
    int nb_save = nb;
    char *str;

    for (n = 0; nb_save != 0; n += 1)
        nb_save /= 10;
    str = malloc(sizeof(char) * (n + 1));
    str[n] = '\0';
    for (n = n - 1; n >= 0; n -= 1) {
        str[n] = (nb % 10) + '0';
        nb /= 10;
    }
    return (str);
}

void update_score(window_t *w)
{
    char *str;

    if (w->score_nb == 0)
        sfText_setString(w->score, "0");
    else {
        str = my_str_nb(w->score_nb);
        sfText_setString(w->score, str);
        free(str);
    }
}