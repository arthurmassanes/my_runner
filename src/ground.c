/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** creates grounds
*/

#include "my_runner.h"

int is_char(char *str, char c)
{
    int nb = 0;

    if (!str)
        return (-1);
    for (int i = 0; str[i]; i++)
        nb = (str[i] == c ? nb + 1 : nb);
    return (nb);
}

game_object_t **create_obstacles(char *map)
{
    char path[] = OBSTACLE_PATH;
    sfIntRect rec = {0, 0, 80, 110};
    sfVector2f pos = {0, 340};
    int nb = is_char(map, 'O');
    game_object_t **obs;
    int current = 0;

    obs = malloc(sizeof(game_object_t *) * (nb + 1));
    for (int c = 0; map[c] && map[c] != '\n'; c++) {
        if (map[c] == 'O') {
            pos.x = c * 100 + 850;
            obs[current] = malloc(sizeof(game_object_t));
            obs[current] = create_object(path, pos, rec);
            current++;
        }
    }
    obs[current] = NULL;
    return (obs);
}

game_object_t **create_grounds(void)
{
    sfVector2f pos = {0, 0};
    game_object_t **obj = malloc(sizeof(game_object_t *) * 4);
    int i;
    sfIntRect rect = {0, 0, 800, 600};
    game_object_t *bg = create_object("img/bg.png", pos, rect);
    game_object_t *mg = create_object("img/mg.png", pos, rect);
    game_object_t *fg = create_object("img/fg.png", pos, rect);

    for (i = 0; i < 4; i++)
        obj[i] = malloc(sizeof(game_object_t));
    obj[i] = 0;
    obj[0] = bg;
    obj[1] = mg;
    obj[2] = fg;
    return (obj);
}
