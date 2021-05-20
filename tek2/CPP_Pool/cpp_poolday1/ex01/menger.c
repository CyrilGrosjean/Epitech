/*
** EPITECH PROJECT, 2021
** cpp_poolday1
** File description:
** menger
*/

#include "menger.h"

int my_getnbr(const char *str)
{
    int nb = 0;
    int neg = 0;
    int index = 0;

    for (; str[index]; index += 1) {
        if (str[index] >= '0' && str[index] <= '9')
            break;
        if (str[index] == '-')
            neg = (neg) ? 0 : 1;
    }
    for (; str[index]; index += 1) {
        if (str[index] < '0' || str[index] > '9')
            break;
        nb = nb * 10 + str[index] - '0';
    }
    nb = (neg) ? -nb : nb;
    return (nb);
}

int mengercalc(int level, int sizeSquare, int x, int y)
{
    int nextx = 0;
    int nexty = 0;

    for (int sqx = 0; sqx < 3; sqx += 1) {
        for (int sqy = 0; sqy < 3; sqy += 1) {
            if (sqx != 1 || sqy != 1) {
                nextx = sqx * sizeSquare + x;
                nexty = sqy * sizeSquare + y;
                menger(sizeSquare, level - 1, nextx, nexty);
            }
        }
    }
    return (0);
}

int menger(int size, int level, int x, int y)
{
    int sizeSquare = size / 3;

    printf("%03d %03d %03d\n", sizeSquare, sizeSquare + x, sizeSquare + y);
    if (level > 1) {
        mengercalc(level, sizeSquare, x, y);
    }
    return (0);
}