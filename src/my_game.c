/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** my_game
*/

#include <SFML/Audio.h>
#include "utils.h"

int my_game(game_t *game, node_t **object_list)
{

    init_map(object_list);

    sfMusic_play(game->music_background);
    while (sfRenderWindow_isOpen(game->window)) {
        if (game->display_mode == 0) {
            menu_loop(game, object_list);
        }
        if (game->display_mode == 1) {
            game_loop(game, object_list);
        }
    }
    cly_node_destroy(object_list);
    return 0;
}
