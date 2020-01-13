/*
** EPITECH PROJECT, 2019
** main
** File description:
** main function of the game
*/

#include "../include/runner.h"

int main(int ac, char **av)
{
    if (ac < 2 || ac > 3) {
        putstr_error("Wrong launch !\nPlease type './my_runner -h' for ");
        putstr_error("help.\n");
        return (84);
    } else if (av[1][0] == '-' && av[1][1] == 'h')
        return (display_help());
    else {
        if (ac == 3)
            return (read_file(av[1], av[2]));
        else
            return (read_file(av[1], "Guest"));
    }
}