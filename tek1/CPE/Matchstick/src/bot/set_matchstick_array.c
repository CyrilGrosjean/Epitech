/*
** EPITECH PROJECT, 2020
** set matchstick array
** File description:
** functions to make a matchstick array
*/

#include "../../include/matchstick.h"

stick_t *set_array_stick(game_t *param, int *tab)
{
    stick_t *array = malloc(sizeof(stick_t) * (param->lines));
    int count = 0;

    for (int i = 0; i < param->lines; i += 1)
        if (tab[i] != 0) {
            array[count].line = i + 1;
            array[count].nb_stick = tab[i];
            count += 1;
        }
    array[0].count = count;
    return (array);
}