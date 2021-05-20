/*
** EPITECH PROJECT, 2021
** cpp_poolday3
** File description:
** size
*/

#include "string.h"

int size(const string_t *this)
{
    if (this->str == NULL)
        return (-1);
    return (strlen(this->str));
}