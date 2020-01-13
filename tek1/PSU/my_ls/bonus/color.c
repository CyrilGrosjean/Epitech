/*
** EPITECH PROJECT, 2020
** color
** File description:
** functions for output name
*/

#include "../include/ls.h"

void green(void)
{
    my_putstr("\033[1;32m");
}

void blue(void)
{
    my_putstr("\033[1;34m");
}

void reset(void)
{
    my_putstr("\033[0m");
}