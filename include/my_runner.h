/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** include
*/

#ifndef MY_RUNNER_H
#define MY_RUNNER_H

#define GROUNDS 3
#define OBST 1
#define EXIT_ERROR 84
#define READ_SIZE 5
#define OBSTACLE_PATH "img/conserve.png"
#define FPS 24

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Window/Window.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Music.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

typedef struct result {
    int score;
    int lose;
} result_t;

typedef struct game_object {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    void (*ptr_move)(struct game_object *, int i);
} game_object_t;

typedef struct sound {
    sfSound *sound;
    sfSoundBuffer *sb;
} sound_t;

typedef struct level {
    game_object_t **obj;
    game_object_t **obs;
} level_t;

game_object_t **create_obstacles(char *map);
int my_strlen(char *str);
result_t my_runner(sfRenderWindow *win, char *str);
game_object_t *create_object(const char *path, sfVector2f pos, sfIntRect rect);
void destroy_object(game_object_t *object);
void destroy_sound(sound_t);
void destroy_all_objects(game_object_t *arr[]);
void display_ground(game_object_t *obj[], sfRenderWindow *win);
int get_input(sfRenderWindow *win, sfEvent event);
void move_player(game_object_t *, game_object_t *obs[], int *, sfSound *);
sfRenderWindow *create_window(int width, int height, char *title);
void display_obs(game_object_t *obs[], sfRenderWindow *win);
sound_t create_sound(char *filepath);
game_object_t **create_grounds(void);
void print_help(void);
int my_cmp(char *, char *);
int check_lose(game_object_t *ply, game_object_t *obs[]);
void my_putstr(char *str);
char *get_next_line(int fd);
int is_char(char *str, char c);
game_object_t *create_player(char *filepath, sfIntRect *rect);
int set_score(sfRenderWindow *win, int score);
char *my_getnbr(int);
int menu(char *map);
int randint(int min, int max);
int end_screen(sfRenderWindow *win, result_t res);
char *my_strdup(char *);
void move_rect(sfIntRect *rect, int offset, int max_value);
char *my_concat(char *, char *);
void display_player(sfRenderWindow *win, game_object_t *player, sfIntRect *);

#endif
