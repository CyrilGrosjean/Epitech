/*
** EPITECH PROJECT, 2019
** my_put_nonprintable
** File description:
** Display a string with non printables chars
*/

#include "include/my.h"

void display_nonprintable(char c)
{
    my_putchar('\\');
    if (c < 8) {
        my_putstr("00");
        my_put_octal(c);
    } else if (c < 32) {
        my_putchar('0');
        my_put_octal(c);
    } else
        my_put_octal(c);
}

void my_put_nonprintable(char *str)
{
    for (int i = 0; str[i]; i += 1) {
        if (str[i] < 32 || str[i] >= 127) {
            display_nonprintable(str[i]);
        } else
            my_putchar(str[i]);
    }
}