/*
** EPITECH PROJECT, 2019
** test error.c
** File description:
** units test for error.c file
*/

#include <criterion/criterion.h>
#include "../include/my_popup.h"

int **str_into_int_array(char **tab);

char **str_to_wordarray(char *str);

Test(check_error, should_return_error)
{
    player_t player;
    char **tab = str_to_wordarray("#######\n# X OO#\n#   P #\n#######");
    int **tab_int = str_into_int_array(tab);
    int error = check_error(tab, tab_int, &player);

    cr_assert_eq(error, 84);
    for (int i = 0; i < 4; i += 1) {
        free(tab[i]);
        free(tab_int[i]);
    }
    free(tab);
    free(tab_int);
}

Test(check_error, should_return_good)
{
    player_t player;
    char **tab = str_to_wordarray("#######\n# X OP#\n#######");
    int **tab_int = str_into_int_array(tab);
    int error = check_error(tab, tab_int, &player);

    cr_assert_eq(error, 0);
    for (int i = 0; i < 3; i += 1) {
        free(tab_int[i]);
        free(tab[i]);
    }
    free(tab);
    free(tab_int);
}

Test(get_char, should_return_every_char)
{
    char a = get_char(0);
    char b = get_char(1);
    char c = get_char(2);
    char d = get_char(3);
    char e = get_char(4);
    char f = get_char(9);

    cr_assert_eq(a, ' ');
    cr_assert_eq(b, '#');
    cr_assert_eq(c, 'O');
    cr_assert_eq(d, 'X');
    cr_assert_eq(e, 'P');
    cr_assert_eq(f, '?');
}

Test(get_int, should_return_every_int)
{
    int a = get_int(' ');
    int b = get_int('#');
    int c = get_int('O');
    int d = get_int('X');
    int e = get_int('P');
    int f = get_int('H');

    cr_assert_eq(a, 0);
    cr_assert_eq(b, 1);
    cr_assert_eq(c, 2);
    cr_assert_eq(d, 3);
    cr_assert_eq(e, 4);
    cr_assert_eq(f, 5);
}