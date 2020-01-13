/*
** EPITECH PROJECT, 2019
** text options
** File description:
** functions to create text object
*/

#include "../include/runner.h"

void option_text_create(option_t *opt)
{
    opt->back = sfText_create();
    opt->difficulty = sfText_create();
    opt->label_diff = sfText_create();
    opt->label_m = sfText_create();
    opt->label_s = sfText_create();
    opt->s_volume = sfText_create();
    opt->m_volume = sfText_create();
    opt->label_endl = sfText_create();
    opt->label_framerate = sfText_create();
    opt->t_frame = sfText_create();
}