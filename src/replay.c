/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** replay screen
*/

#include "my_runner.h"

void print_end_score(sfRenderWindow *win, int score)
{
    sfText *score_txt = sfText_create();
    sfFont *font = sfFont_createFromFile("fonts/font.ttf");

    sfText_setString(score_txt, my_concat("Score: ", my_getnbr(score - 1)));
    sfText_setFont(score_txt, font);
    sfText_setCharacterSize(score_txt, 30);
    sfText_setPosition(score_txt, (sfVector2f){310, 500});
    sfRenderWindow_drawText(win, score_txt, 0);
    sfText_destroy(score_txt);
    sfFont_destroy(font);
}

void print_res(sfRenderWindow *win, char *result, int score)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("fonts/font.ttf");

    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, 77);
    sfText_setString(txt, result);
    sfText_setPosition(txt, (sfVector2f){220, 100});
    sfRenderWindow_drawText(win, txt, 0);
    sfText_setCharacterSize(txt, 33);
    sfText_setString(txt, "[SPACE] Play Again\n\n[ESC] Exit");
    sfText_setPosition(txt, (sfVector2f){285, 275});
    sfRenderWindow_drawText(win, txt, 0);
    sfText_destroy(txt);
    sfFont_destroy(font);
}

void display_two_obj(sfRenderWindow *wn, game_object_t *kfr, game_object_t *scr)
{
    sfRenderWindow_clear(wn, sfBlack);
    sfRenderWindow_drawSprite(wn, scr->sprite, 0);
    if (kfr)
        sfRenderWindow_drawSprite(wn, kfr->sprite, 0);
}

void set_two_rect(game_object_t *kfar, game_object_t *screen, sfIntRect rect)
{
    sfSprite_setTextureRect(kfar->sprite, rect);
    sfSprite_setTextureRect(screen->sprite, rect);
}

int end_screen(sfRenderWindow *win, result_t res)
{
    sfIntRect rect = {0, 0, 800, 600};
    sfVector2f pos = {0, 0};
    char *path = my_strdup(res.lose == 1 ? "img/game_over.png" : "img/win.png");
    game_object_t *screen = create_object(path, pos, rect);
    game_object_t *kfar = create_object("img/kfar_joyeux.png", pos, rect);
    int inpt = 0;
    sfEvent event;

    while (sfRenderWindow_isOpen(win) && inpt == 0) {
        display_two_obj(win, res.lose != 1 ? kfar : 0, screen);
        move_rect(&rect, 800, 4000);
        print_res(win, res.lose == 1 ? "Game Over!" : "YOU WIN !!!", res.score);
        set_two_rect(kfar, screen, rect);
        print_end_score(win, res.score);
        inpt = get_input(win, event);
        sfRenderWindow_display(win);
    }
    destroy_object(screen);
    destroy_object(kfar);
    return (inpt);
}
