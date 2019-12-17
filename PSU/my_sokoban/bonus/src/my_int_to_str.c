/*
** EPITECH PROJECT, 2019
** my int to str
** File description:
** return an integer into an str
*/

#include "../include/my_popup.h"

char *my_int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * 5);
    int modulo = 0;
    int index = 0;

    str[4] = '\0';
    while (nb > 0) {
        modulo = nb % 10;
        nb /= 10;
        str[index] = modulo + '0';
        index += 1;
    }
    return (my_revstr(str));
}