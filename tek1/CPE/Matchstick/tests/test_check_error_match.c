/*
** EPITECH PROJECT, 2020
** tests check_error_match
** File description:
** units tests for error match
*/

#include <criterion/criterion.h>
#include "../include/matchstick.h"

Test(check_error_match, should_return_0)
{
    game_t param;
    int *tab;
    int ret = 0;

    param.lines = 5;
    param.matches = 100;
    param.max_sticks_line = 9;
    tab = get_every_line(param.lines);
    ret = check_error_match(&param, tab, "1\n", 1);
    cr_assert_eq(ret, 0);
    free(tab);
}

Test(check_error_match, should_return_1)
{
    game_t param;
    int *tab;
    int ret = 0;

    param.lines = 5;
    param.matches = 100;
    param.max_sticks_line = 9;
    tab = get_every_line(param.lines);
    ret = check_error_match(&param, tab, "0\n", 1);
    cr_assert_eq(ret, 1);
    free(tab);
}

Test(check_error_match, should_return_1_again)
{
    game_t param;
    int *tab;
    int ret = 0;

    param.lines = 5;
    param.matches = 5;
    param.max_sticks_line = 9;
    tab = get_every_line(param.lines);
    ret = check_error_match(&param, tab, "7\n", 5);
    cr_assert_eq(ret, 1);
    free(tab);
}

Test(check_error_match, should_return_1_again_again)
{
    game_t param;
    int *tab;
    int ret = 0;

    param.lines = 5;
    param.matches = 100;
    param.max_sticks_line = 9;
    tab = get_every_line(param.lines);
    ret = check_error_match(&param, tab, "3\n", 1);
    cr_assert_eq(ret, 1);
    free(tab);
}

Test(check_error_match, should_return_1_more_again)
{
    game_t param;
    int *tab;
    int ret = 0;

    param.lines = 5;
    param.matches = 100;
    param.max_sticks_line = 9;
    tab = get_every_line(param.lines);
    ret = check_error_match(&param, tab, "-7\n", 1);
    cr_assert_eq(ret, 1);
    free(tab);
}