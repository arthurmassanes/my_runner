/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** menu
*/

#include "my_runner.h"

void display_txt(sfRenderWindow *win)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("fonts/font.ttf");
    sfColor grey = {50, 50, 50, 255};

    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, 77);
    sfText_setString(txt, "my_runner");
    sfText_setColor(txt, sfBlack);
    sfText_setPosition(txt, (sfVector2f){220, 100});
    sfRenderWindow_drawText(win, txt, 0);
    sfText_setCharacterSize(txt, 33);
    sfText_setString(txt, "[SPACE] Play\n\n[ESC] Exit");
    sfText_setColor(txt, grey);
    sfText_setPosition(txt, (sfVector2f){285, 275});
    sfRenderWindow_drawText(win, txt, 0);
    sfText_destroy(txt);
    sfFont_destroy(font);
}

void move_clouds(sfRenderWindow *win, game_object_t **clds)
{
    sfVector2f pos;

    for (int i = 0; i < 3; i++) {
        clds[i]->pos.x += 1 + (i * 1.5);
        if (clds[i]->pos.x > 1600)
            clds[i]->pos.x = -800;
        sfSprite_setPosition(clds[i]->sprite, clds[i]->pos);
        sfRenderWindow_drawSprite(win, clds[i]->sprite, NULL);
        pos = (sfVector2f){clds[i]->pos.x - 700, 0};
        sfSprite_setPosition(clds[i]->sprite, pos);
        sfRenderWindow_drawSprite(win, clds[i]->sprite, NULL);
    }
}

game_object_t **create_clouds(void)
{
    game_object_t **clouds = malloc(sizeof(game_object_t *) * 3 + 1);
    sfIntRect rect = {0, 0, 800, 600};
    sfVector2f pos = {-50, -30};

    clouds[0] = malloc(sizeof(game_object_t));
    clouds[0] = create_object("img/cloud1.png", pos, rect);
    pos.y += 30;
    pos.x += 50;
    clouds[1] = malloc(sizeof(game_object_t));
    clouds[1] = create_object("img/cloud3.png", pos, rect);
    clouds[2] = malloc(sizeof(game_object_t));
    clouds[2] = create_object("img/cloud2.png", pos, rect);
    clouds[3] = NULL;
    return (clouds);
}

int display_menu(sfRenderWindow *win, game_object_t **clds, game_object_t *bg)
{
    sfEvent evt;
    int input = 0;
    sfMusic *music = sfMusic_createFromFile("audio/music.ogg");
    int open = 1;

    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    sfRenderWindow_setFramerateLimit(win, FPS);
    while (sfRenderWindow_isOpen(win) && open) {
        input = get_input(win, evt);
        if (input == 2)
            open = 0;
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, bg->sprite, NULL);
        move_clouds(win, clds);
        display_txt(win);
        sfRenderWindow_display(win);
    }
    sfMusic_destroy(music);
    return (input);
}

int menu(char *map)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *win = sfRenderWindow_create(mode, "My Runner", sfClose, 0);
    game_object_t **clouds = create_clouds();
    game_object_t *bg = create_object("img/grey.png", (sfVector2f){0, 0},
                                      (sfIntRect){0, 0, 800, 600});
    int replay = 2;
    result_t res;
    int menu_i;

    sfRenderWindow_setPosition(win, (sfVector2i){100, 100});
    menu_i = display_menu(win, clouds, bg);
    destroy_all_objects(clouds);
    destroy_object(bg);
    if (menu_i != 2)
        return (0);
    while (replay == 2) {
        res = my_runner(win, map);
        replay = end_screen(win, res);
    }
    return (0);
}
