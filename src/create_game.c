/*
** EPITECH PROJECT, 2021
** MyHunter
** File description:
** create_game.c
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "utils.h"

void create_pause(pause_t *pause)
{
    pause->pause_texture = \
        sfTexture_createFromFile("assets/my_pause.jpeg", NULL);
    pause->pause_sprite = sfSprite_create();
    sfSprite_setTexture(pause->pause_sprite, pause->pause_texture, sfTrue);
    ibtt_pause(pause);
}

void create_menu(menu_t *menu)
{
    menu->menu_texture = sfTexture_createFromFile("assets/my_menu.jpeg", NULL);
    menu->menu_sprite = sfSprite_create();
    sfSprite_setTexture(menu->menu_sprite, menu->menu_texture, sfTrue);
    ibtt_menu(menu);
}

game_t *create_game(unsigned int width, unsigned int height)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *win;
    game_t *game = malloc(sizeof(game_t));

    win = sfRenderWindow_create(mode, "My Defender", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win, 60);
    game->window = win;
    game->clear_color = sfBlack;
    game->clock = sfClock_create();
    game->display_mode = 0;
    game->life = 100;
    game->money = 500;
    game->music_intro = sfMusic_createFromFile("assets/intro_sound.ogg");
    game->music_background = \
    sfMusic_createFromFile("assets/sound_background.ogg");
    game->music = sfMusic_createFromFile("assets/pig.wav");
    game->tower_type = 'c';
    create_menu(&game->menu);
    create_pause(&game->pause);
    return game;
}
