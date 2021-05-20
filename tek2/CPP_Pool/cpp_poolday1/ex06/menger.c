/*
** EPITECH PROJECT, 2021
** cpp_poolday1
** File description:
** menger
*/

#include "menger.h"
#include "drawing.h"

int mengercalc(int level, int sizeSquare, co_t coords, unsigned int **img)
{
    co_t ncoords;

    for (int sqx = 0; sqx < 3; sqx += 1) {
        for (int sqy = 0; sqy < 3; sqy += 1) {
            if (sqx != 1 || sqy != 1) {
                ncoords.x = sqx * sizeSquare + coords.x;
                ncoords.y = sqy * sizeSquare + coords.y;
                menger(sizeSquare / 3, level - 1, ncoords, img);
            }
        }
    }
    return (0);
}

int menger(int size, int level, co_t coords, unsigned int **img)
{
    point_t point = {size + coords.x, size + coords.y};
    int col = 0xFF / level;
    int color = ((col & 0xff) << 16) + ((col & 0xff) << 8) + (col & 0xff);

    draw_square(img, &point, size, color);
    if (level > 1) {
        mengercalc(level, size, coords, img);
    }
    return (0);
}