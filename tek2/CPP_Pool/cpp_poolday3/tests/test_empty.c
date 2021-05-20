/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-cyril.grosjean
** File description:
** test_empty
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(empty, should_return_1_cause_null)
{
    int ret = empty(NULL);

    cr_assert_eq(ret, 1);
}

Test(empty, should_return_1_cause_str_null)
{
    string_t string;
    int ret = 0;

    string.str = NULL;
    ret = empty(&string);
    cr_assert_eq(ret, 1);
}

Test(empty, should_return_1_cause_str_size_zero)
{
    string_t string;
    int ret = 0;

    string.str = strdup("\0");
    ret = empty(&string);
    cr_assert_eq(ret, 1);
    free(string.str);
}

Test(empty, should_return_0)
{
    string_t string;
    int ret = 0;

    string.str = strdup("")
}