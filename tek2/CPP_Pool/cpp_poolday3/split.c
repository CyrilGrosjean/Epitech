/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-cyril.grosjean
** File description:
** split
*/

#include "string.h"

int count_values(char *string, char chr_to_count)
{
    int x = 0;

    for (int i = 0; string[i]; i += 1)
        if (string[i] == chr_to_count)
            x += 1;
    return (x + 1);
}

string_t **split_s(const string_t *this, char separator)
{
    char *word = NULL;
    char *line = strdup(this->str);
    char *tmp = line;
    int len = count_values(this->str, separator);
    string_t **result = calloc(len + 1, sizeof(string_t *));
    char sep[1];

    sep[0] = separator;
    for (int x = 0; x < len; x += 1) {
        word = strsep(&line, sep);
        result[x] = malloc(sizeof(string_t));
        string_init(result[x], word);
    }
    free(tmp);
    return (result);
}

char **split_c(const string_t *this, char separator)
{
    char *word = NULL;
    char *line = strdup(this->str);
    char *tmp = line;
    int len = count_values(this->str, separator);
    char **result = calloc(len + 1, sizeof(char *));
    char sep[1];

    sep[0] = separator;
    for (int x = 0; x < len; x += 1) {
        word = strsep(&line, sep);
        result[x] = calloc(strlen(word) + 1, sizeof(char));
        strcpy(result[x], word);
    }
    free(tmp);
    return (result);
}