/*
** EPITECH PROJECT, 2021
** cpp_poolday3
** File description:
** copy
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    unsigned int i = 0;
    size_t len = 0;

    if (this->str == NULL || s == NULL)
        return (0);
    len = strlen(this->str);
    if (pos >= len)
        return (0);

    for (; (i == 0 || this->str[i - 1] != '\0') && i < n; i += 1) {
        s[i] = this->str[i + pos];
    }
    return (i);
}