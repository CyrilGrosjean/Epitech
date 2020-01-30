/*
** EPITECH PROJECT, 2020
** test check_player_move
** File description:
** units tests for player move error handling
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/matchstick.h"

Test(check_line_error, should_return_0)
{
    game_t param;
    int ret = 0;

    param.lines = 5;
    param.matches = 100;
    param.max_sticks_line = 9;
    ret = check_line_error(&param, 1, "1\n");
    cr_assert_eq(ret, 0);
}

Test(check_line_error, should_return_1)
{
    game_t param;
    int ret = 0;

    param.lines = 5;
    param.matches = 100;
    param.max_sticks_line = 9;
    ret = check_line_error(&param, -1, "-1\n");
    cr_assert_eq(ret, 1);
}

Test(check_line_error, should_return_1_again)
{
    game_t param;
    int ret = 0;

    param.lines = 5;
    param.matches = 100;
    param.max_sticks_line = 9;
    cr_redirect_stdout();
    ret = check_line_error(&param, 8, "8\n");
    cr_assert_stdout_eq_str("Error: this line is out of range\n");
    cr_assert_eq(ret, 1);
}

Test(check_line_error, should_return_1_again_again)
{
    game_t param;
    int ret = 0;

    param.lines = 5;
    param.matches = 100;
    param.max_sticks_line = 9;
    ret = check_line_error(&param, 8, "8    \n");
    cr_assert_eq(ret, 1);
}