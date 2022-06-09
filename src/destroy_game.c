/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** destroy_game
*/

#include "utils.h"
#include "cly_linked_list.h"

void destroy_game(game_t *game)
{
    sfMusic_destroy(game->music_intro);
    sfMusic_destroy(game->music_background);
    sfMusic_destroy(game->music);
    sfClock_destroy(game->clock);
    sfRenderWindow_close(game->window);
}
