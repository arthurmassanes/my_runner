/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** displaying different gorund  layers
*/

#include "my_runner.h"
#include <SFML/Window.h>

void display_obs(game_object_t *obs[], sfRenderWindow *win)
{
    for (int i = 0; obs[i]; i++) {
        sfRenderWindow_drawSprite(win, obs[i]->sprite, NULL);
        sfSprite_setPosition(obs[i]->sprite, obs[i]->pos);
        obs[i]->pos.x -= 21;
    }
}

void display_ground(game_object_t *obj[], sfRenderWindow *win)
{
    sfVector2f newpos;

    for (int i = 0; i < GROUNDS; i++) {
        sfRenderWindow_drawSprite(win, obj[i]->sprite, NULL);
        newpos = (sfVector2f){obj[i]->pos.x + 800, 0};
        sfSprite_setPosition(obj[i]->sprite, newpos);
        sfRenderWindow_drawSprite(win, obj[i]->sprite, NULL);
        obj[i]->ptr_move(obj[i], i);
    }
}
