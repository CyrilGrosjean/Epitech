/*
** EPITECH PROJECT, 2019
** check square
** File description:
** functions for check the square
*/

#include "includes/bsq.h"

int check_line(char *str, square_t sqr)
{
    int len = 0;

    for (int i = sqr.x_start; str[i] != '\0'; i += 1) {
        len += 1;
        if (str[i] == 'o')
            return (0);
        if (len == sqr.len)
            break;
    }
    return (1);
}

int check_mybsq(char **tab, square_t sqr, dimensions_t dim)
{
    int val = 0;
    int loops = 0;

    if (sqr.y_start + sqr.len > dim.height)
        return (0);
    for (int i = sqr.y_start; i < dim.height; i += 1) {
        val = check_line(tab[i], sqr);
        loops += 1;
        if (loops == sqr.len)
            break;
        if (!val)
            return (0);
    }
    return (1);
}

int check_square(char **tab, int i, square_t sqr, dimensions_t dim)
{
    int test_len = 0;
    int val = 0;

    sqr.y_start = i;
    sqr.x_start = -1;
    for (int j = 0; tab[i][j] != '\0'; j += 1) {
        if (tab[i][j] == '.' && sqr.x_start == -1)
            sqr.x_start = j;
        if (tab[i][j] == '.')
            test_len += 1;
        else if (tab[i][j] == 'o') {
            test_len = 0;
            sqr.x_start = -1;
        }
        if (test_len == sqr.len)
            val = check_mybsq(tab, sqr, dim);
        if (val)
            return (display_square(tab, sqr, dim));
    }
    return (0);
}