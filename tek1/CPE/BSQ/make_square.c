/*
** EPITECH PROJECT, 2019
** make square
** File description:
** creating square for my_bsq
*/

#include "includes/bsq.h"

char **make_strstr(char *str, dimensions_t dim)
{
    char **tab = malloc(sizeof(char *) * (dim.height + 1));
    int index = 0;
    int j = 0;

    for (j = 0; str[j] != '\n'; j += 1);
    j += 1;
    for (int i = 0; i < dim.height && str[j] != '\0'; i += 1) {
        tab[i] = malloc(sizeof(char) * (dim.width + 1));
        for (index = 0; str[j] != '\n' && str[j] != '\0'; index += 1) {
            tab[i][index] = str[j];
            j += 1;
        }
        tab[i][index] = '\0';
        j += 1;
    }
    return (tab);
}

char **write_square(char **tab, square_t sqr, dimensions_t dim)
{
    for (int y = sqr.y_start; y < dim.height; y += 1) {
        for (int x = sqr.x_start; x != sqr.x_start + sqr.len; x += 1)
            tab[y][x] = 'x';
        if (y == sqr.y_start + (sqr.len - 1))
            break;
    }
    return (tab);
}

int display_square(char **tab, square_t sqr, dimensions_t dim)
{
    tab = write_square(tab, sqr, dim);
    for (int y = 0; y < dim.height; y += 1) {
        my_putstr(tab[y]);
        my_putchar('\n');
    }
    return (1);
}

int generate_square(char *str)
{
    dimensions_t dim = get_dimensions(str);
    square_t sqr;
    char **tab = make_strstr(str, dim);
    int val = 0;

    if (dim.width == 0 || dim.height == 0)
        return (84);
    sqr.len = (dim.height >= dim.width) ? dim.width : dim.height;
    for (sqr.len = sqr.len; sqr.len > 0; sqr.len -= 1) {
        for (int i = 0; i < dim.height && !val; i += 1)
            val = check_square(tab, i, sqr, dim);
        if (val)
            break;
    }
    for (int i = 0; i < dim.height; i += 1)
        free(tab[i]);
    free(tab);
    return (0);
}