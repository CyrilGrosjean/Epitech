/*
** EPITECH PROJECT, 2019
** my_put_binary
** File description:
** Convert an integer into a binary number
*/

#include "include/my.h"

void my_put_binary(int nb)
{
    char *str = malloc(sizeof(char) * (31 + 1));
    int mod;
    int i = 0;

    for (i = 0; nb != 0; i += 1) {
        mod = nb % 2;
        nb /= 2;
        str[i] = mod + '0';
    }
    str[i] = '\0';
    my_putstr(my_revstr(str));
    free(str);
}

void my_put_hexa_lower(int nb)
{
    char *str = malloc(sizeof(char) * (8 + 1));
    int mod;
    int i = 0;

    for (i = 0; nb != 0; i += 1) {
        mod = nb % 16;
        nb /= 16;
        if (mod >= 10)
            str[i] = (mod - 10) + 'a';
        else
            str[i] = mod + '0';
    }
    str[i] = '\0';
    my_putstr(my_revstr(str));
    free(str);
}

void my_put_hexa_upper(int nb)
{
    char *str = malloc(sizeof(char) * (8 + 1));
    int mod;
    int i = 0;

    for (i = 0; nb != 0; i += 1) {
        mod = nb % 16;
        nb /= 16;
        if (mod >= 10)
            str[i] = (mod - 10) + 'A';
        else
            str[i] = mod + '0';
    }
    str[i] = '\0';
    my_putstr(my_revstr(str));
    free(str);
}

void my_put_octal(int nb)
{
    char *str = malloc(sizeof(char) * (11 + 1));
    int mod;
    int i = 0;

    for (i = 0; nb != 0; i += 1) {
        mod = nb % 8;
        nb /= 8;
        str[i] = mod + '0';
    }
    str[i] = '\0';
    my_putstr(my_revstr(str));
    free(str);
}