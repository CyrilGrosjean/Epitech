/*
** EPITECH PROJECT, 2019
** main
** File description:
** main function
*/

#include "../include/my_popup.h"

int main(int ac, char **av)
{
    if (ac != 2) {
        write(2, "Please enter 1 argument only.\n", 31);
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h')
        return (display_help());
    else
        return (open_file(av[1]));
}