/*
** EPITECH PROJECT, 2019
** prepare window
** File description:
** prepare all tiles for the window
*/

#include "../include/runner.h"

static sfVector2f text_pos[9] = {
    {1600, 700},
    {1600, 750},
    {1600, 800},
    {900, 0},
    {900, 600},
    {50, 400},
    {50, 450},
    {50, 500},
    {50, 550}
};

sprite_t player_initialisation(sprite_t player)
{
    sfVector2f scale = {1.5, 1.5};

    sfSprite_setScale(player.s_sprite, scale);
    player.pos_sprite.x = 50;
    player.pos_sprite.y = 803;
    return (player);
}

sprite_t create_object(const char *path, sfIntRect rect, int type, window_t *w)
{
    sprite_t sprite;

    sprite.t_sprite = sfTexture_createFromFile(path, NULL);
    sprite.s_sprite = sfSprite_create();
    sprite.type = type;
    sprite.func = update;
    sprite.pos_sprite.x = 0;
    sprite.pos_sprite.y = 0;
    sprite.rect_sprite = rect;
    sprite.clock = sfClock_create();
    sprite.speed = 0;
    sprite.original_pos_x = 0;
    sfSprite_setTexture(sprite.s_sprite, sprite.t_sprite, sfNone);
    sfSprite_setTextureRect(sprite.s_sprite, sprite.rect_sprite);
    w->object_numb += 1;
    return (sprite);
}

void init_window(window_t *w)
{
    sfVideoMode mode = {1920, 1080, 32};

    w->mode = mode;
    w->name = "myRunner";
    w->actual_w = 0;
    w->refresh = sfClock_create();
    w->object_numb = 0;
    w->player_is_jumping = 0;
    w->player_is_on_platf = 0;
    w->font = sfFont_createFromFile("data/font/font.ttf");
    w->play = init_text(w->play, "Play", text_pos[0], w->font);
    w->options = init_text(w->options, "Options", text_pos[1], w->font);
    w->leave = init_text(w->leave, "Quit", text_pos[2], w->font);
    w->score = init_text(w->score, "0", text_pos[3], w->font);
    w->win_lose = init_text(w->play, "You", text_pos[4], w->font);
    init_best_score(w, text_pos);
    w->music = init_music(w->music, "data/sound/music.ogg");
    init_sound(w);
    w->score_nb = 0;
}

void main_objects_creation(window_t *w)
{
    sfIntRect bg = {0, 0, 3840, 1080};
    sfIntRect p = {0, 80, 75, 75};
    sfIntRect main_bg = {0, 0, 1920, 1080};

    w->s[0] = create_object("data/img/bg.png", bg, Sky, w);
    w->s[1] = create_object("data/img/clouds.png", bg, Cloud, w);
    w->s[2] = create_object("data/img/hills.png", bg, Hills, w);
    w->s[3] = create_object("data/img/trees.png", bg, Trees, w);
    w->s[4] = create_object("data/img/floor.png", bg, Floor, w);
    w->s[5] = create_object("data/img/player.png", p, Player, w);
    w->s[5] = player_initialisation(w->s[5]);
    w->s[6] = create_object("data/img/main_menu_bg.png", main_bg, Main, w);
}

int initialisation(char *str, char *name)
{
    window_t window;
    option_t opt;
    int value = 0;
    int objects = count_objects(str);

    window.player_name = name;
    open_best(&window);
    init_window(&window);
    init_options(&opt, window.font);
    window.s = malloc(sizeof(sprite_t) * (objects + 9));
    main_objects_creation(&window);
    window = make_map(window, str);
    window.s[objects + 8].func = NULL;
    value = runner(&window, &opt);
    free(window.s);
    return (value);
}