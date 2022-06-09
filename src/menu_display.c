/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** display_menu
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "utils.h"

void menu_loop(game_t *game, node_t **object_list)
{
    while (game->display_mode == 0 && sfRenderWindow_isOpen(game->window)) {
        update_events(game, object_list);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->menu.menu_sprite, NULL);
        sfRenderWindow_display(game->window);
    }
}
