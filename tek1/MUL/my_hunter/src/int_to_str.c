/*
** EPITECH PROJECT, 2019
** int to str
** File description:
** turn an int into an str
*/

#include "../include/hunter.h"

char *my_int_to_str(int nb)
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