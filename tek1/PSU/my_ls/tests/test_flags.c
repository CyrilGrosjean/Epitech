/*
** EPITECH PROJECT, 2020
** test flags
** File description:
** unit tests for my_ls
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/ls.h"

Test(my_ls, should_return_ls)
{
    char *av[1] = {"./my_ls"};
    int ac = 1;
    int ret = my_ls(ac, av);

    cr_assert_eq(ret, 0);
}

Test(my_ls, should_return_ls_with_flags)
{
    char *av[2] = {"./my_ls", "-l"};
    int ac = 2;
    int ret = my_ls(ac, av);

    cr_assert_eq(ret, 0);
    av[1] = "-r";
    ret = my_ls(ac, av);
    cr_assert_eq(ret, 0);
    av[1] = "-t";
    ret = my_ls(ac, av);
    cr_assert_eq(ret, 0);
    av[1] = "-d";
    ret = my_ls(ac, av);
    cr_assert_eq(ret, 0);
    av[1] = "-R";
    ret = my_ls(ac, av);
    cr_assert_eq(ret, 0);
}

Test(my_ls, should_return_repo_files)
{
    char *av[3] = {"./my_ls", "src"};
    int ac = 2;
    int ret = my_ls(ac, av);

    cr_assert_eq(ret, 0);
    av[1] = "Makefile";
    ret = my_ls(ac, av);
    cr_assert_eq(ret, 0);
    av[2] = "src";
    ac = 3;
    ret = my_ls(ac, av);
    cr_assert_eq(ret, 0);
    av[1] = "src/main.c";
    av[2] = "-d";
    ret = my_ls(ac, av);
    cr_assert_eq(ret, 0);
}

Test(my_ls, should_return_error)
{
    char *av[2] = {"./my_ls", "toto"};
    int ac = 2;
    int ret = my_ls(ac, av);

    cr_assert_eq(ret, 84);
    av[1] = "lol";
    ret = my_ls(ac, av);
    cr_assert_eq(ret, 84);
}