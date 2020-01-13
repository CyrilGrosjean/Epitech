/*
** EPITECH PROJECT, 2020
** save bests scores
** File description:
** functions to save the best score
*/

#include "../include/runner.h"

int my_strlen(char *str)
{
    int nb = 0;

    for (nb = 0; str[nb]; nb += 1);
    return (nb);
}

void save_best(window_t *w)
{
    int fd = open("data/best.txt", O_WRONLY | O_CREAT, S_IRWXU);

    if (fd == -1)
        return;
    write(fd, w->score_1, my_strlen(w->score_1));
    write(fd, "\n", 1);
    write(fd, w->score_2, my_strlen(w->score_2));
    write(fd, "\n", 1);
    write(fd, w->score_3, my_strlen(w->score_3));
    close(fd);
}