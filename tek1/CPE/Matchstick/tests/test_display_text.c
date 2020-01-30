/*
** EPITECH PROJECT, 2020
** test display_text
** File description:
** units tests for display_text
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/matchstick.h"

Test(my_putstr, should_display_stdout)
{
    cr_redirect_stdout();
    my_putstr(1, "Hello!");
    cr_assert_stdout_eq_str("Hello!");
}

Test(my_putstr, should_display_stderr)
{
    cr_redirect_stderr();
    my_putstr(2, "Oh no !\n");
    cr_assert_stderr_eq_str("Oh no !\n");
}

Test(my_putstr, should_display_nothing)
{
    cr_redirect_stdout();
    my_putstr(5, "Nothing will be displayed");
    cr_assert_stdout_neq_str("Nothing will be displayed");
}