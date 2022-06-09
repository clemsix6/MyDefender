/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** menu_button
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int button_is_hover(game_t *game, sfIntRect rect, sfVector2f vector)
{
    game->mouse_position = sfMouse_getPositionRenderWindow(game->window);

    if (game->mouse_position.x >= vector.x &&\
    game->mouse_position.x <= vector.x + rect.width\
    && game->mouse_position.y >= vector.y &&\
    game->mouse_position.y <= vector.y + rect.height)
        return 1;
    else
        return 0;
}

void button_game(game_t *game)
{
    if (button_is_hover(game, game->weapon.canon_rect,\
    game->weapon.canon_vector)) {
        game->tower_type = 'c';
    }
    else if (button_is_hover(game, game->weapon.tesla_rect,\
    game->weapon.tesla_vector)) {
        game->tower_type = 'l';
    }
    else if (button_is_hover(game, game->weapon.bigtower_rect,\
    game->weapon.bigtower_vector)) {
        game->tower_type = 'b';
    }
    else if (button_is_hover(game, game->weapon.tower_rect,\
    game->weapon.tower_vector)) {
        game->tower_type = 't';
    }
}

void button_pause(game_t *game)
{
    if (button_is_hover(game, game->pause.rect_resume,\
    game->pause.vector_resume)) {
        game->display_mode = 1;
    }
    else if (button_is_hover(game, game->pause.rect_menu,\
    game->pause.vector_menu)) {
        game->display_mode = 0;
    }
    else if (button_is_hover(game, game->pause.rect_quit,\
    game->pause.vector_quit)) {
        sfRenderWindow_close(game->window);
    }
}

void button_menu(game_t *game)
{
    if (button_is_hover(game, game->menu.button_rect,\
    game->menu.button_vector)) {
        game->display_mode = 1;
    }
    else if (button_is_hover(game, game->menu.rect_quit,\
    game->menu.vector_quit)) {
        sfRenderWindow_close(game->window);
    }
}
