/*
** EPITECH PROJECT, 2019
** my_put_long
** File description:
** display a long number
*/

#include <unistd.h>

void my_putchar(char c);

long checkneg_long(long nb)
{
    long copy_nb = nb * 2;

    if (nb < 0)
    {
        nb = nb - copy_nb;
        my_putchar('-');
        return (nb);
    } else {
        return (nb);
    }
}

int my_put_long(long nb)
{
    unsigned long my_mod;

    nb = checkneg_long(nb);
    if (nb >= 10) {
        my_mod = nb % 10;
        my_put_long(nb / 10);
        my_putchar(my_mod + 48);
        return (0);
    } else {
        my_putchar(nb + 48);
    }
    return (0);
}