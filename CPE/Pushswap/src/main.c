/*
** EPITECH PROJECT, 2019
** main
** File description:
** main file for the program
*/

#include "../include/pushswap.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        write(2, "Wrong launch, please give numbers in parameters.\n", 50);
        return (84);
    }
    return (make_list(ac, av));
}