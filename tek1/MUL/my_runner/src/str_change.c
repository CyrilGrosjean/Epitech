/*
** EPITECH PROJECT, 2019
** str change
** File description:
** functions for make a word array
*/

#include "../include/runner.h"

int count_lines(char *str)
{
    int lines = 0;

    for (int i = 0; str[i]; i += 1)
        if (str[i] == '\n')
            lines += 1;
    return (lines);
}

int count_len_line(char *str, int i)
{
    int nb = 0;

    if (i == 0)
        i -= 1;
    for (i = i + 1; str[i] != '\n' && str[i]; i += 1)
        nb += 1;
    return (nb);
}

char **str_to_wordarray(char *str)
{
    char **tab = malloc(sizeof(char *) * (9 + 1));
    int index = -1;
    int x = 0;
    int size = 0;

    tab[9] = NULL;
    for (int i = 0; str[i]; i += 1) {
        if (str[i] == '\n' || i == 0) {
            x = 0;
            index += 1;
            size = count_len_line(str, i);
            tab[index] = malloc(sizeof(char) * (size + 1));
            tab[index][size] = '\0';
        } else {
            tab[index][x] = str[i];
            x += 1;
        }
    }
    return (tab);
}