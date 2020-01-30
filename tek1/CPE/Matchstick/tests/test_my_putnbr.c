/*
** EPITECH PROJECT, 2020
** test my_putnbr
** File description:
** units tests for my_putnbr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/matchstick.h"

Test(my_put_nbr, display_positive_number)
{
    int nb = 19;

    cr_redirect_stdout();
    my_put_nbr(nb);
    cr_assert_stdout_eq_str("19");
}

Test(my_put_nbr, display_round_number)
{
    int nb = 100;

    cr_redirect_stdout();
    my_put_nbr(nb);
    cr_assert_stdout_eq_str("100");
}

Test(my_put_nbr, display_negative_number)
{
    int nb = -42;

    cr_redirect_stdout();
    my_put_nbr(nb);
    cr_assert_stdout_eq_str("-42");
}