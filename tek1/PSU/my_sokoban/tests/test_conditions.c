/*
** EPITECH PROJECT, 2019
** test conditions file
** File description:
** units tests for conditions.c
*/

#include <criterion/criterion.h>
#include "../include/my_popup.h"

int **str_into_int_array(char **tab);

char **str_to_wordarray(char *str);

Test(test_win, should_return_all)
{
    char **tab_not_win = str_to_wordarray("#########\n# OO XXP#\n#########");
    int **int_tab = str_into_int_array(tab_not_win);
    char **tab_win = str_to_wordarray("#########\n# XX   P#\n#########");
    int not_win = test_win(tab_not_win, int_tab);
    int win = test_win(tab_win, int_tab);

    cr_assert_eq(not_win, 1);
    cr_assert_eq(win, 0);
    for (int i = 0; i < 3; i += 1) {
        free(tab_not_win[i]);
        free(tab_win[i]);
        free(int_tab[i]);
    }
    free(tab_win);
    free(tab_not_win);
    free(int_tab);
}

Test(test_lose, should_return_all)
{
    char **tab_n_lose = str_to_wordarray("#######\n# XXOP#\n#     #\n#######");
    int **int_tab = str_into_int_array(tab_n_lose);
    char **tab_lose = str_to_wordarray("#######\n#X  OP#\n#X    #\n#######");
    int not_lose = test_lose(tab_n_lose, int_tab);
    int lose = test_lose(tab_lose, int_tab);

    cr_assert_eq(not_lose, 0);
    cr_assert_eq(lose, 1);
    for (int i = 0; i < 3; i += 1) {
        free(tab_lose[i]);
        free(tab_n_lose[i]);
        free(int_tab[i]);
    }
    free(tab_lose);
    free(tab_n_lose);
    free(int_tab);
}