/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Displays the number given as a parameter
*/

#include <unistd.h>

void my_putchar(char c);

int checkneg(int nb)
{
    int copy_nb = nb * 2;

    if (nb < 0)
    {
        nb = nb - copy_nb;
        my_putchar('-');
        return (nb);
    } else {
        return (nb);
    }
}

int my_put_nbr(int nb)
{
    int my_mod;

    nb = checkneg(nb);
    if (nb >= 10) {
        my_mod = nb % 10;
        my_put_nbr(nb / 10);
        my_putchar(my_mod + 48);
        return (0);
    } else {
        my_putchar(nb + 48);
    }
    return (0);
}