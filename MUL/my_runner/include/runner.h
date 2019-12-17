/*
** EPITECH PROJECT, 2019
** runner
** File description:
** prototypes and include for all functions
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Context.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Window.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Sensor.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

#define GRAVITY 0.96

typedef enum {
    Sky,
    Cloud,
    Hills,
    Trees,
    Floor,
    Player,
    Spike
} type_t;

typedef struct sprite_s {
    sfIntRect rect_sprite;
    sfTexture *t_sprite;
    sfSprite *s_sprite;
    sfVector2f pos_sprite;
    sfClock *clock;
    int original_pos_x;
    float speed;
    struct sprite_s (*func)(struct sprite_s);
    type_t type;
} sprite_t;

typedef struct options_s {
    sfText *s_volume;
    sfText *m_volume;
    sfText *label_m;
    sfText *label_s;
    sfText *back;

    int sound_volume;
    int music_volume;
} option_t;

typedef struct window_s {
    sfRenderWindow *w;
    sfVideoMode mode;
    char *name;
    sfEvent event;
    sprite_t *s;
    int actual_w;
    sfClock *refresh;
    int player_is_jumping;
    float velocity;
    int object_numb;

    sfFont *font;
    sfText *score;
    sfText *play;
    sfText *options;
    sfText *leave;
    sfText *win_lose;

    sfMusic *mouse_click;
    sfMusic *mouse_over;
    sfMusic *jump;
    sfMusic *music;
} window_t;

int initialisation(char *str);
int runner(window_t *w);
sprite_t update(sprite_t sprite);
void update_sky(sprite_t *sprite);
void update_trees_floor(sprite_t *sprite);
void update_hills(sprite_t *sprite);
void update_clouds(sprite_t *sprite);
void update_player(sprite_t *sprite, window_t *w);
void manage_key_pressed(sfKeyEvent event, window_t *w);
void destroy_objects(window_t *w);
void update_player_jump(window_t *w);
int count_lines(char *str);
char **str_to_wordarray(char *str);
int count_objects(char *map);
window_t make_map(window_t w, char *str);
sprite_t create_object(const char *path, sfIntRect rect, int type, window_t *w);
void update_spike(sprite_t *sprite);
int read_file(char *file);
int putstr_error(char *str);
void testing_lose(window_t *w);
sfText *init_text(sfText *sp_text, char *text, sfVector2f pos, sfFont *font);
void manage_mouse(window_t *w);
sfMusic *init_music(sfMusic *music, char *path);
void reset_speed(window_t *w);
void reset_spikes(window_t *w);

#endif
