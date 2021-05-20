/*
** EPITECH PROJECT, 2021
** cpp_poolday1
** File description:
** test_z
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int main(int ac, char **av);

Test(z, should_display_z)
{
    int res = 0;

    cr_redirect_stdout();
    res = main(0, NULL);
    cr_assert_stdout_eq_str("z\n");
    cr_assert_eq(res, 0);
}