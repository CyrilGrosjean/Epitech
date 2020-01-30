/*
** EPITECH PROJECT, 2020
** test display_board
** File description:
** units tests for display board
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/matchstick.h"

Test(display_board, should_display_board)
{
    game_t param;
    int *tab;

    param.lines = 3;
    param.matches = 100;
    param.max_sticks_line = 5;
    tab = get_every_line(param.lines);
    cr_redirect_stdout();
    display_board(tab, &param);
    cr_assert_stdout_eq_str("*******\n*  |  *\n* ||| *\n*|||||*\n*******\n");
    free(tab);
}