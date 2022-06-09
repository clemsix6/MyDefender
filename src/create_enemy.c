/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** create_enemy.c
*/

#include "utils.h"
#include <stdlib.h>

void create_enemy(game_t *game, node_t **object_list)
{
    sfVector2f pos = {0, 4};
    sfVector2f position = {160 + pos.x * 100, 60 + pos.y * 100};
    sfIntRect rect = {0, 0, 100, 100};
    object_t *object = create_object("assets/cochon.png", position, rect, 'e');
    enemy_t *enemy = malloc(sizeof(enemy_t));
    animation_t *animation = malloc(sizeof(animation_t));

    animation->offset = 100;
    animation->max = 100;
    animation->next_time = 0;
    animation->increment_time = 0.2f;
    enemy->hp = 5;
    enemy->last_position = position;
    enemy->current_position = position;
    enemy->next_position = position;
    enemy->damage_time = -1;
    object->component = enemy;
    object->layer = 2;
    object->animation = animation;
    cly_node_push_back(object_list, object);
    sfMusic_stop(game->music);
    sfMusic_play(game->music);
}
