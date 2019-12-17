/*
** EPITECH PROJECT, 2019
** test my_bsq branches
** File description:
** unit tests for branches of my_bsq
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/stat.h>
#include "../includes/bsq.h"

Test(check_line, should_return_0)
{
    square_t sqr;
    char str[] = "...............";
    int i;

    sqr.len = 5;
    sqr.x_start = 0;
    i = check_line(str, sqr);
    cr_assert_eq(i, 1);
}