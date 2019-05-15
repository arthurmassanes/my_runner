/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** create player function
*/

#include "my_runner.h"

void display_player(sfRenderWindow *win, game_object_t *player, sfIntRect *rect)
{
    sfSprite_setPosition(player->sprite, player->pos);
    sfRenderWindow_drawSprite(win, player->sprite, NULL);
    sfSprite_setTextureRect(player->sprite, *rect);
    move_rect(rect, 110, 660);
}

game_object_t *create_player(char *filepath, sfIntRect *rect)
{
    game_object_t *player = malloc(sizeof(game_object_t));
    sfVector2f pos ={300, 100};

    rect->top = 0;
    rect->left = 0;
    rect->height = 75;
    rect->width = 110;
    player = create_object(filepath, pos, *rect);
    return (player);
}
