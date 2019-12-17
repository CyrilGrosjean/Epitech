/*
** EPITECH PROJECT, 2019
** test my_printf
** File description:
** unit test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test(my_printf, should_return_number)
{
    int i = 10;
    int o = 20;
    int hex = 30;
    char str[] = "Bonjour";
    char stR[] = "Bonj\nour";
    short s = 12;
    long k = 800;

    cr_redirect_stdout();
    my_printf("%d,%o,%x,%s,%S,%h,%l,%X,%b", i, o, hex, str, stR, s, k, hex, i);
    cr_assert_stdout_eq_str("10,24,1e,Bonjour,Bonj\\012our,12,800,1E,1010");
}

Test(my_printf, should_return_percent)
{
    cr_redirect_stdout();
    my_printf("%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, should_return_adress)
{
    cr_redirect_stdout();
    my_printf("%p", "saluta");
    cr_assert_stdout_eq_str("0x7ffc27094cd1");
}