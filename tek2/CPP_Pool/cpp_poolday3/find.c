/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-cyril.grosjean
** File description:
** find
*/

#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    int x = 0;
    int save = 0;

    if (!this->str || strlen(str->str) > strlen(this->str) ||
    pos >= strlen(this->str))
        return (-1);
    for (size_t i = pos; this->str[i]; i += 1) {
        if (this->str[i] != str->str[x++]) {
            x = 0;
            save = 0;
        }
        if (x == 1)
            save = i;
        if (!str->str[x])
            return (save);
    }
    return (-1);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    int x = 0;
    int save = 0;

    if (!this->str || strlen(str) > strlen(this->str) ||
    pos >= strlen(this->str))
        return (-1);
    for (size_t i = pos; this->str[i]; i += 1) {
        if (this->str[i] != str[x++]) {
            x = 0;
            save = 0;
        }
        if (x == 1)
            save = i;
        if (!str[x])
            return (save);
    }
    return (-1);
}