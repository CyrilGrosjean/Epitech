/*
** EPITECH PROJECT, 2021
** cpp_poolday1
** File description:
** ex05
*/

#ifndef EX05_H_
#define EX05_H_

#include <stdint.h>

typedef union __attribute__((packed)) foo_s {
    struct {
        int16_t foo;
        union {
            int16_t bar;
            int16_t foo;
        } bar;
    } foo;
    int32_t bar;
} foo_t;

#endif /* EX05_H_ */
