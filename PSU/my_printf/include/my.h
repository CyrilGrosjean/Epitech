/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** protoypes of my lib
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef MY_H_
#define MY_H_

typedef struct flag {
    char *c;
    void (*pt)(void *);
} flag_t;

int checkneg(int nb);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf(char *str, ...);
int my_put_long(long nb);
long checkneg_long(long nb);
short checkneg_short(short nb);
int my_put_short(short nb);
void display_nonprintable(char c);
void my_put_nonprintable(char *str);
char *my_revstr(char *str);
void my_put_binary(int nb);
void my_put_hexa_upper(int nb);
void my_put_hexa_lower(int nb);
void my_put_octal(int nb);
void display_pointer(long long i);

#endif