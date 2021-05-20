/*
** EPITECH PROJECT, 2021
** cpp_poolday2_am
** File description:
** tab_to_2dtab
*/

#include <string.h>
#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int size = 0;

    *res = malloc(sizeof(int *) * (length + 1));
    for (int i = 0; i < length; i += 1) {
        (*res)[i] = malloc(sizeof(int) * (width + 1));
        for (int x = 0; x < width; x += 1) {
            (*res)[i][x] = tab[size++];
        }
    }
}