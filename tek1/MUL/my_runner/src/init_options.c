/*
** EPITECH PROJECT, 2019
** init options
** File description:
** options functions
*/

#include "../include/runner.h"

const char *labels[10] = {
    "Back",
    "1",
    "Difficulty",
    "Music volume",
    "Sound volume",
    "100",
    "100",
    "Endless mode",
    "Framerate limit",
    "60"
};

const sfVector2f pos[19] = {
    {900, 200},
    {900, 300},
    {900, 400},
    {900, 800},
    {400, 200},
    {400, 300},
    {400, 400},

    {750, 190},
    {1000, 190},
    {750, 290},
    {1000, 290},
    {750, 390},
    {1000, 390},

    {1300, 400},
    {1350, 450},

    {900, 500},
    {400, 500},
    {750, 490},
    {1000, 490}
};

sfSprite *create_sprite_option(int add, sfIntRect rect)
{
    char path_add[24] = "data/img/add_option.png";
    char path_sub[23] = "data/img/minus_opt.png";
    char path_case[23] = "data/img/case_endl.png";
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture;

    if (add == 1) {
        texture = sfTexture_createFromFile(path_add, sfNone);
        sfSprite_setTexture(sprite, texture, sfNone);
        sfSprite_setTextureRect(sprite, rect);
    } else if (add == 0) {
        texture = sfTexture_createFromFile(path_sub, sfNone);
        sfSprite_setTexture(sprite, texture, sfNone);
        sfSprite_setTextureRect(sprite, rect);
    } else {
        texture = sfTexture_createFromFile(path_case, sfNone);
        sfSprite_setTexture(sprite, texture, sfNone);
        sfSprite_setTextureRect(sprite, rect);
    }
    return (sprite);
}

void init_sprite_option(option_t *opt)
{
    sfIntRect rect_add_sub = {0, 0, 64, 64};
    sfIntRect rect_case = {0, 0, 120, 120};

    opt->add_diff = create_sprite_option(1, rect_add_sub);
    opt->add_music = create_sprite_option(1, rect_add_sub);
    opt->add_sound = create_sprite_option(1, rect_add_sub);
    opt->sub_diff = create_sprite_option(0, rect_add_sub);
    opt->sub_music = create_sprite_option(0, rect_add_sub);
    opt->sub_sound = create_sprite_option(0, rect_add_sub);
    opt->add_framerate = create_sprite_option(1, rect_add_sub);
    opt->sub_framerate = create_sprite_option(0, rect_add_sub);
    opt->endl_case = create_sprite_option(2, rect_case);
}

void place_options(option_t *opt)
{
    sfText_setPosition(opt->difficulty, pos[0]);
    sfText_setPosition(opt->s_volume, pos[1]);
    sfText_setPosition(opt->m_volume, pos[2]);
    sfText_setPosition(opt->back, pos[3]);
    sfText_setPosition(opt->label_diff, pos[4]);
    sfText_setPosition(opt->label_s, pos[5]);
    sfText_setPosition(opt->label_m, pos[6]);
    sfSprite_setPosition(opt->sub_diff, pos[7]);
    sfSprite_setPosition(opt->add_diff, pos[8]);
    sfSprite_setPosition(opt->sub_sound, pos[9]);
    sfSprite_setPosition(opt->add_sound, pos[10]);
    sfSprite_setPosition(opt->sub_music, pos[11]);
    sfSprite_setPosition(opt->add_music, pos[12]);
    sfText_setPosition(opt->label_endl, pos[13]);
    sfSprite_setPosition(opt->endl_case, pos[14]);
    sfText_setPosition(opt->t_frame, pos[15]);
    sfText_setPosition(opt->label_framerate, pos[16]);
    sfSprite_setPosition(opt->sub_framerate, pos[17]);
    sfSprite_setPosition(opt->add_framerate, pos[18]);
}

void set_font(option_t *opt, sfFont *font)
{
    sfText_setFont(opt->back, font);
    sfText_setFont(opt->difficulty, font);
    sfText_setFont(opt->label_diff, font);
    sfText_setFont(opt->label_m, font);
    sfText_setFont(opt->label_s, font);
    sfText_setFont(opt->s_volume, font);
    sfText_setFont(opt->m_volume, font);
    sfText_setFont(opt->label_endl, font);
    sfText_setFont(opt->label_framerate, font);
    sfText_setFont(opt->t_frame, font);
    sfText_setColor(opt->back, sfBlack);
    sfText_setColor(opt->difficulty, sfBlack);
    sfText_setColor(opt->label_diff, sfBlack);
    sfText_setColor(opt->label_m, sfBlack);
    sfText_setColor(opt->label_s, sfBlack);
    sfText_setColor(opt->s_volume, sfBlack);
    sfText_setColor(opt->m_volume, sfBlack);
    sfText_setColor(opt->label_endl, sfBlack);
    sfText_setColor(opt->label_framerate, sfBlack);
    sfText_setColor(opt->t_frame, sfBlack);
}

void init_options(option_t *opt, sfFont *font)
{
    opt->sound_volume = 100;
    opt->music_volume = 100;
    opt->how_difficulty = 1;
    opt->framerate = 60;
    option_text_create(opt);
    set_font(opt, font);
    sfText_setString(opt->back, labels[0]);
    sfText_setString(opt->difficulty, labels[1]);
    sfText_setString(opt->label_diff, labels[2]);
    sfText_setString(opt->label_m, labels[3]);
    sfText_setString(opt->label_s, labels[4]);
    sfText_setString(opt->s_volume, labels[5]);
    sfText_setString(opt->m_volume, labels[6]);
    sfText_setString(opt->label_endl, labels[7]);
    sfText_setString(opt->label_framerate, labels[8]);
    sfText_setString(opt->t_frame, labels[9]);
    init_sprite_option(opt);
    place_options(opt);
}