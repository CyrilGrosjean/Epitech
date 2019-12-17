/*
** EPITECH PROJECT, 2019
** test help
** File description:
** units test for help function
*/

#include <criterion/criterion.h>
#include "../include/my_popup.h"

Test(display_help, should_return_0)
{
    int ret = display_help();

    cr_assert_eq(ret, 0);
}