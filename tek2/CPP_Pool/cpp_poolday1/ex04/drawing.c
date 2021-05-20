/*
** EPITECH PROJECT, 2021
** cpp_poolday1
** File description:
** drawing
*/

#include "drawing.h"

void draw_square(uint32_t **img, const point_t *origin,
size_t size, uint32_t color)
{
    for (unsigned int y = 0; y < size; y += 1) {
        for (unsigned int x = 0; x < size; x += 1) {
            img[y + origin->y][x + origin->x] = color;
        }
    }
}