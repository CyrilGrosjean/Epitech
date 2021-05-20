/*
** EPITECH PROJECT, 2021
** cpp_poolday3
** File description:
** at
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    size_t str_length = strlen(this->str);

    if (pos >= str_length)
        return (-1);
    return (this->str[pos]);
}