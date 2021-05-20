/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** my_cat
*/

#include "../my_cat.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(get_cat, should_display_error_nofile)
{
    char *files[2] = {"./my_cat", "fake"};

    cr_redirect_stderr();
    get_cat(2, files);
    cr_assert_stderr_eq_str("my_cat: fake: No such file or directory\n");
}