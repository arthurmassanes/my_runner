/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** create object func
*/

#include "my_runner.h"
#include <stdlib.h>

void move(game_object_t *obj, int i)
{
    obj->pos.x -= 1 + i * i * 5;
    if (obj->pos.x < -800)
        obj->pos.x = 0;
    sfSprite_setPosition(obj->sprite, obj->pos);
}

game_object_t *create_object(const char *path, sfVector2f pos, sfIntRect rect)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    object->texture = sfTexture_createFromFile(path, NULL);
    object->sprite = sfSprite_create();
    object->pos = pos;
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setTextureRect(object->sprite, rect);
    sfSprite_setPosition(object->sprite, pos);
    object->ptr_move = &move;
    return (object);
}

void destroy_sound(sound_t boing)
{
    sfSound_destroy(boing.sound);
    sfSoundBuffer_destroy(boing.sb);
}

void destroy_object(game_object_t *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
}

void destroy_all_objects(game_object_t *arr[])
{
    for (int i = 0; arr[i]; i++)
        destroy_object(arr[i]);
}
