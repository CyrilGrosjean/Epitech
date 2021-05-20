/*
** EPITECH PROJECT, 2021
** cpp_poolday1
** File description:
** pyramid
*/

#include <stdio.h>

void get_result(int floor, const int **map, int *resultAdd)
{
    int resultA = 0;
    int resultB = 0;

    for (int i = 0; i < floor; i += 1) {
        resultA = map[floor - 1][i] + resultAdd[i];
        resultB = map[floor - 1][i] + resultAdd[i + 1];
        resultAdd[i] = (resultA < resultB) ? resultA : resultB;
    }
}

int pyramid_path(int size, const int **map)
{
    int resultAdd[size];

    for (int i = 0; i < size; i += 1) {
        resultAdd[i] = map[size - 1][i];
    }
    for (int i = size - 1; i > 0; i -= 1) {
        get_result(i, map, &resultAdd);
    }
    return (resultAdd[0]);
}