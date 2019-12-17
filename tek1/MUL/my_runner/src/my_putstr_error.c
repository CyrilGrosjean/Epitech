/*
** EPITECH PROJECT, 2019
** my putstr error
** File description:
** Functions to display error message
*/

#include "../include/runner.h"

int putstr_error(char *str)
{
    for (int i = 0; str[i]; i += 1)
        write(2, &str[i], 1);
    return (84);
}