/*
** EPITECH PROJECT, 2019
** dimensions
** File description:
** return dimensions of the square
*/

#include "includes/bsq.h"

dimensions_t get_dimensions(char *str)
{
    dimensions_t dim;
    int index = 0;
    int width = 0;

    dim.height = my_getnbr(str);
    if (dim.height <= 0)
        dim.height = 0;
    for (index = 0; str[index] != '\n' && str[index] != '\0'; index += 1);
    if (str[index] == '\0')
        exit(84);
    for (index = index + 1; str[index] == '.' || str[index] == 'o'; index += 1)
        width += 1;
    dim.width = width;
    if (str[index] != '\0' && str[index] != '\n')
        dim.width = 0;
    return (dim);
}