/*
** EPITECH PROJECT, 2019
** main
** File description:
** main function
*/

#include "../include/hunter.h"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        documentation();
    else
        return (init());
    return (0);
}