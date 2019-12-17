/*
** EPITECH PROJECT, 2019
** main
** File description:
** main file for BSQ project
*/

#include "includes/bsq.h"

int main(int ac, char **av)
{
    int output;

    if (ac != 2) {
        write(2, "Please enter 1 argument only.", 30);
        return (84);
    }
    output = my_bsq(av[1]);
    return (output);
}