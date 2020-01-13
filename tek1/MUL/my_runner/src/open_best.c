/*
** EPITECH PROJECT, 2020
** open best score
** File description:
** functions to open and get the 3 bests scores
*/

#include "../include/runner.h"

void fill_str(char *str)
{
    for (int i = 0; i <= 32000; i += 1)
        str[i] = '\0';
}

char **word_array_best(char *str)
{
    char **tab = malloc(sizeof(char *) * 4);
    int index = -1;
    int x = 0;
    int size = 0;

    for (int i = 0; str[i]; i += 1) {
        if (str[i] == '\n' || i == 0) {
            x = 0;
            index += 1;
            size = count_len_line(str, i);
            tab[index] = malloc(sizeof(char) * (size + 1));
            tab[index][size] = '\0';
        } else if (index == 3)
            break;
        if (str[i] != '\n') {
            tab[index][x] = str[i];
            x += 1;
        }
    }
    return (tab);
}

int open_best(window_t *w)
{
    int fd = open("data/best.txt", O_RDONLY);
    int rd = 0;
    char *str = malloc(sizeof(char) * (32000 + 1));
    char **scores = NULL;

    if (fd == -1) {
        putstr_error("Error on best score file open.\n");
        return (84);
    }
    fill_str(str);
    rd = read(fd, str, 32000);
    if (rd == -1)
        return (84);
    close(fd);
    scores = word_array_best(str);
    w->score_1 = scores[0];
    w->score_2 = scores[1];
    w->score_3 = scores[2];
    free(scores);
    return (0);
}