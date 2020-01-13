/*
** EPITECH PROJECT, 2019
** display help
** File description:
** functions for displaying help
*/

#include "../include/runner.h"

void my_putstr(char *str)
{
    for (int i = 0; str[i]; i += 1)
        write(1, &str[i], 1);
}

int display_help(void)
{
    my_putstr("USAGE:\n\t./my_runner map_file (optionnal: <player_name>)\n\n");
    my_putstr("DESCRIPTION:\n");
    my_putstr("\tUse your mouse to select an option on main menu.\n\t");
    my_putstr("Use SPACE to jump when you're playing.\n\nHOW TO CREATE MAP:");
    my_putstr("\n\t0 for void, 1 for spike and 2 for platform.\n\t");
    my_putstr("The ground is automatically generated\n\n\t");
    my_putstr("WARNING: The file map must have 9 lines, not less, not more !");
    my_putstr("\n\tInfos: To add a spike at the ground, place a '1' ");
    my_putstr("character at line 8\n\nHave fun !\n");
    return (0);
}