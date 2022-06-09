/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** create_tower
*/

#include <stdlib.h>
#include <stdio.h>
#include <utils.h>
#include "cly_linked_list.h"
#include "cly_string.h"

void create_big_tower(game_t *game, sfVector2f position, node_t **object_list)
{
    sfIntRect rect = {0, 0, 100, 100};
    object_t *object;
    tower_t *tower;

    if (game->money < 300)
        return;
    game->money -= 300;
    object = create_object("assets/big_tower.png", \
        position, rect, game->tower_type);
    tower = malloc(sizeof(tower_t));
    tower->range = 300;
    tower->damage = 1;
    tower->next_time = 0;
    tower->increment_time = 1;
    object->component = tower;
    cly_node_push_back(object_list, object);
}

void create_canon_tower(game_t *game,
sfVector2f position,
node_t **object_list)
{
    sfIntRect rect = {0, 0, 100, 100};
    object_t *object;
    tower_t *tower;

    if (game->money < 50)
        return;
    game->money -= 50;
    object = create_object("assets/canon.png", \
        position, rect, game->tower_type);
    tower = malloc(sizeof(tower_t));
    tower->range = 300;
    tower->damage = 2;
    tower->next_time = 0;
    tower->increment_time = 2;
    object->component = tower;
    cly_node_push_back(object_list, object);
}

void create_mid_tower(game_t *game, sfVector2f position, node_t **object_list)
{
    sfIntRect rect = {0, 0, 100, 100};
    object_t *object;
    tower_t *tower;

    if (game->money < 200)
        return;
    game->money -= 200;
    object = create_object("assets/tesla.png", \
        position, rect, game->tower_type);
    tower = malloc(sizeof(tower_t));
    tower->range = 500;
    tower->damage = 3;
    tower->next_time = 0;
    tower->increment_time = 1.5f;
    object->component = tower;
    cly_node_push_back(object_list, object);
}

void create_basic_tower(game_t *game,
sfVector2f position,
node_t **object_list)
{
    sfIntRect rect = {0, 0, 100, 100};
    object_t *object;
    tower_t *tower;

    if (game->money < 100)
        return;
    game->money -= 100;
    object = create_object("assets/tower.png", \
        position, rect, game->tower_type);
    tower = malloc(sizeof(tower_t));
    tower->range = 700;
    tower->damage = 1;
    tower->next_time = 0;
    tower->increment_time = 1;
    object->component = tower;
    cly_node_push_back(object_list, object);
}

void create_tower(game_t *game, sfVector2f position, node_t **object_list)
{
    if (game->tower_type == 'n')
        return;
    if (game->tower_type == 't')
        create_basic_tower(game, position, object_list);
    if (game->tower_type == 'c')
        create_canon_tower(game, position, object_list);
    if (game->tower_type == 'l')
        create_mid_tower(game, position, object_list);
    if (game->tower_type == 'b')
        create_big_tower(game, position, object_list);
}
