/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** func for score/text
*/

#include "my_runner.h"

char *my_concat(char *s1, char *s2)
{
    char *dup = malloc(sizeof(char) * my_strlen(s1) + my_strlen(s2) + 1);
    int i = 0;

    if (!s1 || !s2)
        return (NULL);
    for (i = 0; s1[i]; i++)
        dup[i] = s1[i];
    for (int n = 0; s2[n]; n++) {
        dup[i] = s2[n];
        i++;
    }
    dup[i] = 0;
    return (dup);
}

char *my_revstr(char *str)
{
    char *dup = malloc(sizeof(char) * my_strlen(str) + 1);
    int target = 0;

    for (int i = my_strlen(str) - 1; i >= 0; i--) {
        dup[target] = str[i];
        target++;
    }
    dup[my_strlen(str)] = 0;
    return (dup);
}

int nb_len(int nb)
{
    int len = 0;

    if (nb == 0)
        return (1);
    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return (len);
}

char *my_getnbr(int nb)
{
    char *str = malloc(sizeof(char) * nb_len(nb) + 1);
    int i = 0;
    int neg = 0;

    if (nb < 0) {
        neg = 1;
        nb = -nb;
    }
    while (nb > 0) {
        str[i] = nb % 10 + 48;
        nb /= 10;
        i++;
    }
    if (neg == 1) {
        str[i] = '-';
        i++;
    }
    str[i] = 0;
    str = my_revstr(str);
    return (str);
}

int set_score(sfRenderWindow *win, int score)
{
    sfText *score_txt = sfText_create();
    sfFont *font = sfFont_createFromFile("fonts/font.ttf");

    sfText_setString(score_txt, my_concat("Score: ", my_getnbr(score)));
    sfText_setFont(score_txt, font);
    sfText_setCharacterSize(score_txt, 25);
    sfText_setPosition(score_txt, (sfVector2f){75, 500});
    sfRenderWindow_drawText(win, score_txt, 0);
    sfText_destroy(score_txt);
    sfFont_destroy(font);
    score++;
    return (score);
}
