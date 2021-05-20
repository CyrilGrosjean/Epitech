/*
** EPITECH PROJECT, 2021
** cpp_poolday1
** File description:
** main
*/

#include "menger.h"

int main(int ac, char **av)
{
    int size = 0;
    int levels = 0;

    if (ac < 3) {
        return (84);
    }
    size = my_getnbr(av[1]);
    levels = my_getnbr(av[2]);
    if (size <= 0 || size % 3 != 0 || levels <= 0) {
        return (84);
    }
    menger(size, levels, 0, 0);
    return (0);
}