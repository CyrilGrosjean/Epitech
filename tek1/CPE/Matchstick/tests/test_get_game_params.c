/*
** EPITECH PROJECT, 2020
** test get_game_params
** File description:
** units tests for get_game_params
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/matchstick.h"

int display_who_win(int lose);
int get_max_stick(int line);

Test(display_who_win, should_return_2)
{
    int ret = 0;

    cr_redirect_stdout();
    ret = display_who_win(2);
    cr_assert_eq(ret, 2);
    cr_assert_stdout_eq_str("You lost, too bad...\n");
}

Test(display_who_win, should_return_1)
{
    int ret = 0;

    cr_redirect_stdout();
    ret = display_who_win(1);
    cr_assert_eq(ret, 1);
    cr_assert_stdout_eq_str("I lost... snif... \
but I'll get you next time!!\n");
}

Test(get_max_stick, should_return_7)
{
    int ret = get_max_stick(4);

    cr_assert_eq(ret, 7);
}