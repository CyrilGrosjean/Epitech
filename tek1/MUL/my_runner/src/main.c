/*
** EPITECH PROJECT, 2019
** main
** File description:
** main function of the game
*/

#include "../include/runner.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    else
        return (read_file(av[1]));
}