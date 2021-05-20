/*
** EPITECH PROJECT, 2021
** cpp_poolday3
** File description:
** assign
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (this->str)
        free(this->str);
    this->str = (char *) calloc(strlen(str->str) + 1, sizeof(char));
    strcpy(this->str, str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (this->str)
        free(this->str);
    this->str = (char *) calloc(strlen(s) + 1, sizeof(char));
    strcpy(this->str, s);
}