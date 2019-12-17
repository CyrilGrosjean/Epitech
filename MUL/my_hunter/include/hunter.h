/*
** EPITECH PROJECT, 2019
** hunter.h
** File description:
** prototypes of function hunter
*/

#ifndef HUNTER_H_
#define HUNTER_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Context.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Window.h>
#include <SFML/Window/Mouse.h>
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

typedef struct window_s {
    sfVideoMode mode;
    sfRenderWindow *w;
    sfEvent event;
    char *n;
    sfClock *clock;
    int actual_w;
    sfMusic *ambiance_sound;
    sfMusic *duck;
    sfText *launch;
    sfText *quit;
    sfText *score;
    int score_point;
    sfFont *font;
    int window;
    int lives;

    sfIntRect rect_duck;
    sfTexture *te_duck;
    sfSprite *sp_duck;
    sfVector2f pos_duck;
    sfClock *a_duck;

    sfIntRect rect_dog;
    sfTexture *te_dog;
    sfSprite *sp_dog;
    sfVector2f pos_dog;
    sfClock *anim_dog;
    sfMusic *dog_music;
    int spawn_dog;

    sfTexture *te_background;
    sfSprite *sp_background;
    sfIntRect rect_background;

    sfTexture *te_scope;
    sfSprite *sp_scope;
    sfIntRect rect_scope;
    sfVector2f pos_scope;
    sfClock *rel_scope;
    sfMusic *shoot_sound;

    int speed_duck;
    sfClock *speed;

    sfTexture *te_heart;
    sfSprite *sp_heart1;
    sfSprite *sp_heart2;
    sfSprite *sp_heart3;
    sfIntRect rect_heart1;
    sfIntRect rect_heart2;
    sfIntRect rect_heart3;
} window_t;

void analyse_event(window_t *window, sfEvent event);
int manage_mouse_click(sfMouseButtonEvent event, window_t *window);
void anim_duck(window_t *window);
void move_duck(window_t *window);
void move_scope(window_t *window);
int move_dog(window_t *window);
void anim_dog(window_t *window);
void destroy(window_t *window);
void manage_key_pressed(sfKeyEvent event, window_t *window);
int create_clock(window_t *window);
void animation_duck(window_t *window);
void main_refresh(window_t *window);
void animation_dog(window_t *window);
int bonus(window_t *window);
int init_music(window_t *window);
int init(void);
int check_error_texture_sprite(window_t *window);
int check_error_clock(window_t *window);
int check_error_music(window_t *window);
int check_error_text(window_t *window);
int init_text(window_t *window);
void refresh_main_menu(window_t *window);
void draw(window_t *window, int w);
void duck_click(sfMouseButtonEvent ev, window_t *window);
void dog_click(sfMouseButtonEvent ev, window_t *window);
void text_click(sfMouseButtonEvent ev, window_t *window);
void update_score(window_t *window);
char *my_int_to_str(int nb);
void heart_sprite(window_t *window);
void change_heart(window_t *window);
void my_putchar(char c);
int my_putstr(char const *str);
void documentation(void);

#endif