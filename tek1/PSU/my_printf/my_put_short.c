/*
** EPITECH PROJECT, 2019
** my_put_short
** File description:
** display a short number
*/

#include <unistd.h>

void my_putchar(char c);

short checkneg_short(short nb)
{
    short copy_nb = nb * 2;

    if (nb < 0)
    {
        nb = nb - copy_nb;
        my_putchar('-');
        return (nb);
    } else {
        return (nb);
    }
}

int my_put_short(short nb)
{
    unsigned short my_mod;

    nb = checkneg_short(nb);
    if (nb >= 10) {
        my_mod = nb % 10;
        my_put_short(nb / 10);
        my_putchar(my_mod + 48);
        return (0);
    } else
        my_putchar(nb + 48);
    return (0);
}