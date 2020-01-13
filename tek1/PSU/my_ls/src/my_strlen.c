/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** function my_strlen
*/

#include "../include/ls.h"

int my_strlen(char *text)
{
    int len = 0;

    for (len = 0; text[len]; len += 1);
    return (len);
}