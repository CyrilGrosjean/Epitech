/*
** EPITECH PROJECT, 2020
** test game
** File description:
** units tests for game file function
*/

#include <criterion/criterion.h>
#include "../include/matchstick.h"

Test(check_end, should_return_1)
{
    game_t param;
    int tab[4] = {0, 0, 0, 0};
    int ret = 0;

    param.lines = 4;
    param.matches = 100;
    param.max_sticks_line = 7;
    ret = check_end(tab, &param);
    cr_assert_eq(ret, 1);
}

Test(check_end, should_return_0)
{
    game_t param;
    int *tab = get_every_line(4);
    int ret = 0;

    param.lines = 4;
    param.matches = 100;
    param.max_sticks_line = 7;
    ret = check_end(tab, &param);
    cr_assert_eq(ret, 0);
    free(tab);
}