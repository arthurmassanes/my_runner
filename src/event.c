/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** function for working with events
*/

#include "my_runner.h"
#include <stdio.h>

int get_input(sfRenderWindow *win, sfEvent event)
{
    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        sfRenderWindow_close(win);
        return (1);
    } else if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
        return (2);
    return (0);
}

int collides(game_object_t *ply, game_object_t *obs)
{
    if (obs->pos.x <= 380 && obs->pos.x >= 260) {
        if (ply->pos.y >= 275)
            return (1);
    } else
        return (0);
}

int check_lose(game_object_t *ply, game_object_t *obs[])
{
    int i;

    for (i = 0; obs[i]; i++) {
        if (collides(ply, obs[i]) == 1)
            return (1);
    }
    if (ply->pos.x > obs[i - 1]->pos.x + 350)
        return (2);
    return (-1);
}

void move_player(game_object_t *ply, game_object_t *obs[],
                 int *speedy, sfSound *boing)
{
    sfBool space = sfKeyboard_isKeyPressed(sfKeySpace);

    ply->pos.y += 22;
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue && ply->pos.y >= 370) {
        sfSound_play(boing);
        *speedy = 70;
    } else if (space == sfTrue && ply->pos.y <= 370) {
        *speedy *= 0.88;
    } else
        *speedy *= 0.69;
    ply->pos.y -= *speedy;
    if (ply->pos.y >= 370)
        ply->pos.y = 370;
}
