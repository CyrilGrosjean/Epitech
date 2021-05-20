/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-cyril.grosjean
** File description:
** join
*/

#include "string.h"

void join_c(string_t *this, char delim, const char * const * tab)
{
    char delimiter[1];

    delimiter[0] = delim;
    this->assign_c(this, tab[0]);
    for (int i = 1; tab[i] != NULL; i += 1) {
        this->append_c(this, delimiter);
        this->append_c(this, tab[i]);
    }
}

void join_s(string_t *this, char delim, const string_t * const * tab)
{
    char delimiter[1];

    delimiter[0] = delim;
    this->assign_s(this, tab[0]);
    for (int i = 1; tab[i] != NULL; i += 1) {
        this->append_c(this, delimiter);
        this->append_s(this, tab[i]);
    }
}