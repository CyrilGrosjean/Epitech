/*
** EPITECH PROJECT, 2020
** my putstr
** File description:
** function for my_putstr
*/

#include "../include/ls.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1)
        my_putchar(str[i]);
}