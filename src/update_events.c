/*
** EPITECH PROJECT, 2021
** BootstrapMyRunner
** File description:
** update_events.c
*/

#include <SFML/Audio.h>
#include "utils.h"
#include "cly_linked_list.h"

void game_event(game_t *game, sfEvent event, node_t **object_list)
{
    if (event.type == sfEvtMouseButtonPressed) {
        button_game(game);
        update_plots(game, object_list);
    }
    if (event.type == sfEvtClosed)
        destroy_game(game);
    else if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape)
            destroy_game(game);
        else if (event.key.code == sfKeySpace)
            game->display_mode = 3;
    }
}

void menu_event(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed)
        destroy_game(game);
    else if (event.type == sfEvtMouseButtonPressed)
        button_menu(game);
    else if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape)
            destroy_game(game);
    }
}

void pause_event(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed)
        destroy_game(game);
    else if (event.type == sfEvtMouseButtonPressed)
        button_pause(game);
    else if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape) {
            destroy_game(game);
        }
    }
}

void update_events(game_t *game, node_t **object_list)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (game->display_mode == 0)
            menu_event(game, event);
        if (game->display_mode == 1)
            game_event(game, event, object_list);
        if (game->display_mode == 3)
            pause_event(game, event);
    }
}