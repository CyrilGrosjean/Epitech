/*
** EPITECH PROJECT, 2019
** window
** File description:
** window functions
*/

#include "../include/my_popup.h"

int count_lines(char *str)
{
    int nb = 0;

    for (int i = 0; str[i]; i += 1)
        if (str[i] == '\n')
            nb += 1;
    return (nb);
}

int count_len_line(char *str, int i)
{
    int nb = 0;

    for (i = i + 1; str[i] != '\n' && str[i]; i += 1)
        nb += 1;
    return (nb);
}

char **str_to_wordarray(char *str)
{
    int size = count_lines(str);
    char **tab = malloc(sizeof(char *) * (size + 2));
    int index = 0;
    int x = 0;

    tab[size + 1] = NULL;
    size = count_len_line(str, -1);
    tab[0] = malloc(sizeof(char) * (size + 1));
    tab[0][size] = '\0';
    for (int i = 0; str[i]; i += 1) {
        if (str[i] == '\n') {
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

int **str_into_int_array(char **tab)
{
    int **int_tab;
    int i = 0;

    for (i = 0; tab[i] != NULL; i += 1);
    int_tab = malloc(sizeof(int *) * (i + 1));
    for (int y = 0; tab[y] != NULL; y += 1) {
        int_tab[y] = malloc(sizeof(int) * (my_strlen(tab[y]) + 1));
        for (int x = 0; tab[y][x]; x += 1) {
            int_tab[y][x] = get_int(tab[y][x]);
            if (int_tab[y][x] == 5)
                return (NULL);
        }
    }
    return (int_tab);
}

int init(char *text)
{
    player_t player;
    char **tab = str_to_wordarray(text);
    int **int_tab = str_into_int_array(tab);
    int value = 0;

    if (int_tab == NULL) {
        write(2, "Invalid character on the map.\n", 31);
        return (84);
    }
    value = render_console(tab, int_tab, &player);
    for (int i = 0; tab[i] != NULL; i += 1) {
        free(tab[i]);
        free(int_tab[i]);
    }
    free(tab);
    free(int_tab);
    return (value);
}