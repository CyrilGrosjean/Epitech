/*
** EPITECH PROJECT, 2019
** my_put_pointer
** File description:
** display a pointer adress
*/

#include "include/my.h"

void display_pointer(long long nb)
{
    char *str = malloc(sizeof(char) * (18 + 1));
    int mod = 0;
    int i = 0;

    for (i = 0; nb != 0; i += 1) {
        mod = nb % 16;
        nb /= 16;
        if (mod >= 10)
            str[i] = (mod - 10) + 'a';
        else
            str[i] = mod + '0';
    }
    str[i] = 'x';
    str[i + 1] = '0';
    str[i + 2] = '\0';
    my_putstr(my_revstr(str));
    free(str);
}