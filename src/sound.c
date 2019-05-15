/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** bonsoir
*/

#include "my_runner.h"

sound_t create_sound(char *filepath)
{
    sound_t boing;

    boing.sb = sfSoundBuffer_createFromFile(filepath);
    if (!boing.sb)
        return (boing);
    boing.sound = sfSound_create();
    sfSound_setBuffer(boing.sound, boing.sb);
    return (boing);
}
