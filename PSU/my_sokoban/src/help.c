/*
** EPITECH PROJECT, 2019
** help
** File description:
** function that displays the program help
*/

#include "../include/my_popup.h"

int display_help(void)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n");
    my_putstr("\tmap file representing the warehouse map, containing '#' ");
    my_putstr("for walls, \n\t\t'P' for the player, 'X' for boxes and 'O'");
    my_putstr(" for storage locations.\n");
    return (0);
}