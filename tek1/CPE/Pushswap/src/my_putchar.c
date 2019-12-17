/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** write a character
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}
