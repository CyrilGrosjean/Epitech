/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function for this program
*/

#include "../include/matchstick.h"

int main(int ac, char **av)
{
    if (ac == 3)
        return (get_params(av[1], av[2]));
    else {
        my_putstr(2, "Please enter 2 arguments.\n");
        return (84);
    }
}