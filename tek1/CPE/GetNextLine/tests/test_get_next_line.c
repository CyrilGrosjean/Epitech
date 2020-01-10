/*
** EPITECH PROJECT, 2019
** test get next line
** File description:
** units tests for get next line
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_next_line(int fd);

int fd = -1;

void open_f(void)
{
    fd = open("tests/test_file.txt", O_RDONLY);
    cr_redirect_stdout();
}

void close_f(void)
{
    if (fd != -1)
        close(fd);
}

Test(get_next_line, should_return_one_line, .init = open_f, .fini = close_f)
{
    char except[22] = "This is a normal text";
    char *got = get_next_line(fd);

    cr_assert_not_null(got);
    cr_assert_str_eq(got, except);

}

Test(get_next_line, should_return_mult_line, .init = open_f, .fini = close_f)
{
    char except_1[22] = "This is a normal text";
    char except_2[13] = "For our best";
    char except_3[11] = "Forgive us";
    char *got = get_next_line(fd);

    cr_assert_str_eq(got, except_1);
    got = get_next_line(fd);
    cr_assert_str_eq(got, except_2);
    got = get_next_line(fd);
    cr_assert_str_eq(got, except_3);
    got = get_next_line(fd);
    cr_assert_null(got);
}

Test(get_next_line, should_return_null)
{
    int fd = open("tests", O_RDONLY);
    char *got = get_next_line(fd);

    cr_assert_null(got);
    got = get_next_line(-1);
    cr_assert_null(got);
}