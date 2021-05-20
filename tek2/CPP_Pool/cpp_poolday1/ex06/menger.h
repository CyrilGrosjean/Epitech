/*
** EPITECH PROJECT, 2021
** cpp_poolday1
** File description:
** menger
*/

#ifndef MENGER_H_
#define MENGER_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef struct co_s {
    int x;
    int y;
} co_t;

int menger(int size, int level, co_t coords, unsigned int **img);

#endif /* !MENGER_H_ */
