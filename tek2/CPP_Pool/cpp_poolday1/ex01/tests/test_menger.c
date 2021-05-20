/*
** EPITECH PROJECT, 2021
** cpp_poolday1
** File description:
** test_menger
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../menger.h"

Test(my_getnbr, should_return_positive)
{
    char positiveNumber[2] = "3";
    int res = my_getnbr(positiveNumber);

    cr_assert_eq(res, 3);
}

Test(menger, should_display_menger_square_9_2)
{
    int res = 0;

    res = menger(9, 2, 0, 0);
    cr_assert_eq(res, 0);
}