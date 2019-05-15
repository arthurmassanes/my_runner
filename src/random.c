/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** random funcs
*/

#include "my_runner.h"

int randint(int min, int max)
{
    return ((rand() % max) + min);
}
