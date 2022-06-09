/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** pause_display
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <utils.h>

void pause_loop(game_t *game, node_t **object_list)
{
    while (game->display_mode == 3 && sfRenderWindow_isOpen(game->window)) {
        update_events(game, object_list);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, \
            game->pause.pause_sprite, NULL);
        sfRenderWindow_display(game->window);
    }
}
