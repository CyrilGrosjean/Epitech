/*
** EPITECH PROJECT, 2020
** test remove_stick
** File description:
** units tests for remove stick
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/matchstick.h"

Test(remove_stick_player, should_display_message)
{
    int tab[4] = {1, 3, 5, 7};
    int line = 3;
    int match = 2;

    cr_redirect_stdout();
    remove_stick_player(tab, line, match);
    cr_assert_eq(tab[2], 3);
    cr_assert_stdout_eq_str("Player removed 2 match(es) from line 3\n");
}

Test(remove_stick_bot, should_display_another_message)
{
    int tab[4] = {1, 3, 5, 7};
    int line = 3;
    int match = 2;

    cr_redirect_stdout();
    remove_stick_bot(tab, line, match);
    cr_assert_eq(tab[2], 3);
    cr_assert_stdout_eq_str("AI removed 2 match(es) from line 3\n");
}