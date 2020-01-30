/*
** EPITECH PROJECT, 2020
** display text
** File description:
** display text at given output
*/

#include "../include/matchstick.h"

void my_putstr(int output, char *str)
{
    if (output != 1 && output != 2)
        return;
    for (int i = 0; str[i]; i += 1)
        write(output, &str[i], 1);
}