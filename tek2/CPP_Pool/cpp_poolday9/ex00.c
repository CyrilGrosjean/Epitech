/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** ex00
*/

#include "ex00.h"

static void cthulhu_initializer(cthulhu_t *this)
{
    if (this)
        free(this);
    this = new_cthulhu();
}

cthulhu_t *new_cthulhu(void)
{
    cthulhu_t *this = NULL;
    char *name = strdup("Cthulhu");

    printf("----\n");
    this = malloc(sizeof(cthulhu_t));
    this->m_name = name;
    this->m_power = 42;
    printf("Building Cthulhu\n");
    return (this);
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void sleeping(cthulhu_t *this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
        return;
    }
    printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

static void koala_initializer(koala_t *this, char *name, char _is_A_Legend)
{
    if (this)
        free(this);
    this = new_koala(name, _is_A_Legend);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *this = NULL;

    this = malloc(sizeof(koala_t));
    this->m_parent = *(new_cthulhu());
    this->m_is_a_legend = is_a_legend;
    free(this->m_parent.m_name);
    this->m_parent.m_name = strdup(name);
    if (!is_a_legend) {
        this->m_parent.m_power = 0;
    }
    printf("Building %s\n", this->m_parent.m_name);
    return (this);
}

void eat(koala_t *this)
{
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.m_name);
}