/*
** EPITECH PROJECT, 2021
** cpp_poolday3
** File description:
** string
*/

#ifndef STRING_H_
#define STRING_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct string_s string_t;

typedef struct string_s {
    char *str;
    void (*assign_s)(string_t *this, const string_t *str);
    void (*assign_c)(string_t *this, const char *s);
    void (*append_s)(string_t *this, const string_t *ap);
    void (*append_c)(string_t *this, const char *ap);
    char (*at)(const string_t *this, size_t pos);
    void (*clear)(string_t *this);
    int (*size)(const string_t *this);
    int (*compare_s)(const string_t *this, const string_t *str);
    int (*compare_c)(const string_t *this, const char *str);
    size_t (*copy)(const string_t *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const string_t *this);
    int (*empty)(const string_t *this);
    int (*find_s)(const string_t *this, const string_t *str, size_t pos);
    int (*find_c)(const string_t *this, const char *str, size_t pos);
    void (*insert_c)(string_t *this, size_t pos, const char *str);
    void (*insert_s)(string_t *this, size_t pos, const string_t *str);
    int (*to_int)(const string_t *this);
    char **(*split_c)(const string_t *this, char separator);
    string_t **(*split_s)(const string_t *this, char separator);
    void (*print)(const string_t *this);
    void (*join_c)(string_t *this, char delim, const char * const * tab);
    void (*join_s)(string_t *this, char delim, const string_t * const * tab);
} string_t;

/* init */

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);

/* assign */

void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);

/* append */

void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);

/* at */

char at(const string_t *this, size_t pos);

/* clear */

void clear(string_t *this);

/* size */

int size(const string_t *this);

/* compare */

int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);

/* copy */

size_t copy(const string_t *this, char *s, size_t n, size_t pos);

/* c_str */

const char *c_str(const string_t *this);

/* empty */

int empty(const string_t *this);

/* find */

int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);

/* insert */

void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);

/* to_int */

int to_int(const string_t *this);

/* split */

char **split_c(const string_t *this, char separator);
string_t **split_s(const string_t *this, char separator);

/* print */

void print(const string_t *this);

/* join */

void join_c(string_t *this, char delim, const char * const * tab);
void join_s(string_t *this, char delim, const string_t * const * tab);

#endif /* !STRING_H_ */
