/*
** EPITECH PROJECT, 2019
** test make_list
** File description:
** unit tests for make_list
*/

#include <criterion/criterion.h>
#include "../include/pushswap.h"

int my_getnbr(char *str);

Test(my_getnbr, should_return_int)
{
    char str[3] = "84";
    int nb = my_getnbr(str);

    cr_assert_eq(nb, 84);
}

Test(get_smallest_number, should_return_4)
{
    int list[6] = {9, 82, 1728, 4, 8, 12};
    int size = 6;
    int small = get_smallest_number(list, size);

    cr_assert_eq(small, 4);
}

Test(make_list, should_sort_numbers)
{
    char *args[5] = {"./pushswap", "103", "4", "-182", "192"};
    int size = 5;
    int ret = make_list(size, args);

    cr_assert_eq(ret, 0);
}

Test(make_list, should_return_already_sort)
{
    char *args[4] = {"./pushswap", "5", "19", "24"};
    char *args_2[2] = {"./pushswap", "3"};
    int size = 4;
    int size_2 = 2;
    int ret = make_list(size, args);
    int ret_2 = make_list(size_2, args_2);

    cr_assert_eq(ret, 0);
    cr_assert_eq(ret_2, 0);
}

Test(make_list, should_return_error)
{
    char *args[4] = {"./pushswap", "61", "Hi", "18"};
    int size = 4;
    int ret = make_list(size, args);

    cr_assert_eq(ret, 84);
}