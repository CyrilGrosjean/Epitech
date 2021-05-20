/*
** EPITECH PROJECT, 2021
** cpp_poolday3
** File description:
** clear
*/

#include "string.h"

void clear(string_t *this)
{
    memset(this->str, 0, strlen(this->str));
}