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
    Spike,
    Platform,
    Main
} type_t;

typedef struct options_s {
    sfText *s_volume;
    sfText *m_volume;
    sfText *label_m;
    sfText *label_s;
    sfText *difficulty;
    sfText *label_diff;
    sfText *back;
    sfText *label_endl;
    sfText *label_framerate;
    sfText *t_frame;

    sfSprite *add_diff;
    sfSprite *sub_diff;
    sfSprite *add_sound;
    sfSprite *sub_sound;
    sfSprite *add_music;
    sfSprite *sub_music;
    sfSprite *add_framerate;
    sfSprite *sub_framerate;
    sfSprite *endl_case;

    int framerate;
    int endless;
    int how_difficulty;
    int sound_volume;
    int music_volume;
} option_t;

typedef struct sprite_s {
    sfIntRect rect_sprite;
    sfTexture *t_sprite;
    sfSprite *s_sprite;
    sfVector2f pos_sprite;
    sfClock *clock;
    int original_pos_x;
    float speed;
    struct sprite_s (*func)(struct sprite_s, option_t *);
    type_t type;
} sprite_t;

typedef struct window_s {
    sfRenderWindow *w;
    sfVideoMode mode;
    char *name;
    sfEvent event;
    sprite_t *s;
    int actual_w;
    sfClock *refresh;
    int player_is_jumping;
    int player_is_on_platf;
    float velocity;
    int object_numb;

    int score_nb;
    int end;
    int origin_end;

    sfFont *font;
    sfText *score;
    sfText *play;
    sfText *options;
    sfText *leave;
    sfText *win_lose;

    sfText *best_label;
    sfText *best1;
    sfText *best2;
    sfText *best3;
    char *score_1;
    char *score_2;
    char *score_3;

    sfSoundBuffer *mouse_click_buff;
    sfSoundBuffer *mouse_over_buff;
    sfSoundBuffer *jump_buff;
    sfSoundBuffer *game_over_buff;
    sfSoundBuffer *win_buff;

    sfSound *game_over;
    sfSound *mouse_click;
    sfSound *mouse_over;
    sfSound *jump;
    sfMusic *music;
    sfSound *win;

    char *player_name;
} window_t;

int initialisation(char *str, char *name);
int runner(window_t *w, option_t *opt);
sprite_t update(sprite_t sprite, option_t *opt);
void update_sky(sprite_t *sprite, option_t *opt);
void update_trees_floor(sprite_t *sprite, option_t *opt);
void update_hills(sprite_t *sprite, option_t *opt);
void update_clouds(sprite_t *sprite, option_t *opt);
void update_player(sprite_t *sprite, window_t *w);
void manage_key_pressed(sfKeyEvent event, window_t *w);
void destroy_objects(window_t *w);
void update_player_jump(window_t *w);
int count_lines(char *str);
char **str_to_wordarray(char *str);
int count_objects(char *map);
window_t make_map(window_t w, char *str);
sprite_t create_object(const char *path, sfIntRect rect, int type, window_t *w);
void update_spike_platform(sprite_t *sprite, option_t *opt);
int read_file(char *file, char *name);
int putstr_error(char *str);
void testing_lose(window_t *w);
sfText *init_text(sfText *sp_text, char *text, sfVector2f pos, sfFont *font);
void manage_mouse(window_t *w);
sfMusic *init_music(sfMusic *music, char *path);
void reset_speed(window_t *w);
void reset_spikes(window_t *w);
void update_score(window_t *w);
void init_sound(window_t *w);
int selected_play(window_t *w, int button);
int selected_options(window_t *w, int button);
int selected_leave(window_t *w, int button);
int display_help(void);
void init_options(option_t *opt, sfFont *font);
void display_main_menu(window_t *w);
void display_option_menu(window_t *w, option_t *opt);
void get_event_options(window_t *w, option_t *opt);
char *my_str_nb(int nb);
void change_difficulty(option_t *opt, int change, window_t *w);
void change_sound(option_t *opt, int change, window_t *w);
void change_music(option_t *opt, int change, window_t *w);
void option_text_create(option_t *opt);
void change_endless_mode(option_t *opt, window_t *w);
void update_end(window_t *w, option_t *opt);
void change_framerate(option_t *opt, int change, window_t *w);
void update_player_jump(window_t *w);
void checking_player_platform(window_t *w);
int count_len_line(char *str, int i);
void save_best(window_t *w);
int open_best(window_t *w);
void init_best_score(window_t *w, sfVector2f *positions);
void check_best_score(window_t *w);
void update_text_score(window_t *w);
char *remalloc_and_set(char *old, char *new);

#endif