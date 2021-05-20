/*
** EPITECH PROJECT, 2021
** cpp_poolday3
** File description:
** append
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    char *tmp = NULL;

    if (!this->str)
        return (assign_s(this, ap));
    tmp = calloc((strlen(this->str) + 1), sizeof(char));
    strcpy(tmp, this->str);
    free(this->str);
    this->str = (char *) calloc(strlen(tmp) + strlen(ap->str) + 1,
    sizeof(char *));
    strcpy(this->str, tmp);
    free(tmp);
    strcat(this->str, ap->str);
}

void append_c(string_t *this, const char *ap)
{
    char *tmp = NULL;

    if (!this->str)
        return (assign_c(this, ap));
    tmp = calloc((strlen(this->str) + 1), sizeof(char));
    strcpy(tmp, this->str);
    free(this->str);
    this->str = (char *) calloc(strlen(tmp) + strlen(ap) + 1,
    sizeof(char *));
    strcpy(this->str, tmp);
    free(tmp);
    strcat(this->str, ap);
}