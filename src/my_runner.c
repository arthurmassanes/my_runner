/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** salut
*/

#include "my_runner.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value - offset)
        rect->left += offset;
    else
        rect->left = 0;
}

sfRenderWindow *create_window(int width, int height, char *title)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *win = sfRenderWindow_create(mode, title, sfDefaultStyle, 0);

    sfRenderWindow_setFramerateLimit(win, 24);
    return (win);
}

result_t main_loop(sfRenderWindow *win, level_t lvl, sfSound *snd, sfEvent evt)
{
    int speedy = 0;
    sfIntRect rect;
    game_object_t *player = create_player("img/kfar.png", &rect);
    result_t res = {-1, -1};

    while (sfRenderWindow_isOpen(win) && res.lose == -1) {
        sfRenderWindow_clear(win, sfBlack);
        display_ground(lvl.obj, win);
        display_player(win, player, &rect);
        display_obs(lvl.obs, win);
        get_input(win, evt);
        move_player(player, lvl.obs, &speedy, snd);
        res.lose = check_lose(player, lvl.obs);
        res.score = set_score(win, res.score);
        sfRenderWindow_display(win);
    }
    destroy_object(player);
    return (res);
}

result_t update(sfRenderWindow *win, game_object_t *obj[], game_object_t *obs[])
{
    sfEvent event;
    sound_t boing = create_sound("audio/jump.wav");
    int lose = -1;
    level_t lvl = {obj, obs};
    result_t res;

    res = main_loop(win, lvl, boing.sound, event);
    destroy_sound(boing);
    return (res);
}

result_t my_runner(sfRenderWindow *win, char *map)
{
    sfIntRect playrect = {0, 0, 110, 75};
    sfVideoMode mode = {800, 600, 32};
    game_object_t **obj = create_grounds();
    game_object_t **obs = create_obstacles(map);
    sfMusic *music = sfMusic_createFromFile("audio/main_music.ogg");
    result_t res;

    sfRenderWindow_setFramerateLimit(win, FPS);
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    sfRenderWindow_setKeyRepeatEnabled(win, sfFalse);
    res = update(win, obj, obs);
    sfMusic_destroy(music);
    destroy_all_objects(obj);
    destroy_all_objects(obs);
    return (res);
}
