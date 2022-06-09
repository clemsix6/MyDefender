/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** game_display
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <utils.h>
#include "cly_linked_list.h"
#include "cly_string.h"

void update_time(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    float total_time = time.microseconds / 1000000.0f;
    game->delta_time = total_time - game->total_time;
    game->total_time = total_time;
}

void check_pause(game_t *game, node_t **object_list)
{
    if (game->display_mode == 3)
        pause_loop(game, object_list);
}

void game_loop(game_t *game, node_t **object_list)
{
    int nextSpawn = 1;

    init_weapon(&game->weapon);
    while (game->display_mode != 0 && sfRenderWindow_isOpen(game->window)) {
        if (game->total_time > nextSpawn) {
            nextSpawn += 2;
            create_enemy(game, object_list);
        }
        game->mouse_position = sfMouse_getPositionRenderWindow(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        check_pause(game, object_list);
        update_enemies(game, object_list);
        update_animations(game, object_list);
        update_towers(game, object_list);
        update_render(game, object_list);
        update_events(game, object_list);
        update_time(game);
    }
}