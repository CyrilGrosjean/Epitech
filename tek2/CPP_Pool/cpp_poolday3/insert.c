/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-cyril.grosjean
** File description:
** insert
*/

#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    size_t len_str = strlen(this->str);
    size_t x = 0;
    char *tmp = NULL;

    if (pos >= len_str)
        return (this->append_c(this, str));
    tmp = calloc(len_str + 1, sizeof(char));
    strcpy(tmp, this->str);
    if (this->str)
        free(this->str);
    this->str = calloc(len_str + strlen(str) + 1, sizeof(char));
    for (; x < pos; x += 1)
        this->str[x] = tmp[x];
    for (size_t i = 0; str[i]; i += 1)
        this->str[x++] = str[i];
    for (size_t i = pos; tmp[i]; i += 1)
        this->str[x++] = tmp[i];
    free(tmp);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    size_t len_str = strlen(this->str);
    size_t x = 0;
    char *tmp = NULL;

    if (pos >= len_str)
        return (this->append_s(this, str));
    tmp = calloc(len_str + 1, sizeof(char));
    strcpy(tmp, this->str);
    if (this->str)
        free(this->str);
    this->str = calloc(len_str + strlen(str->str) + 1, sizeof(char));
    for (; x < pos; x += 1)
        this->str[x] = tmp[x];
    for (size_t i = 0; str->str[i]; i += 1)
        this->str[x++] = str->str[i];
    for (size_t i = pos; tmp[i]; i += 1)
        this->str[x++] = tmp[i];
    free(tmp);
}