/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** update_tower
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <utils.h>
#include "cly_linked_list.h"
#include "cly_string.h"

bool get_range(sfVector2f a, sfVector2f b, int range)
{
    float dist_x = a.x - b.x;
    float dist_y = a.y - b.y;

    if (dist_x < 0) 
        dist_x = -dist_x;
    if (dist_y < 0)
        dist_y = -dist_y;
    return dist_x < range && dist_y < range;
}

object_t *get_enemy(node_t **object_list,
                    sfVector2f position,
                    int range)
{
    node_t *it = *object_list;
    object_t *object;

    while (it != NULL) {
        object = it->value;
        if (object->type == 'e' && \
            get_range(object->position, position, range)) {
            return object;
        }
        it = it->next;
    }
    return NULL;
}

void update_tower(game_t *game, object_t *object, node_t **object_list)
{
    tower_t *tower = object->component;
    object_t *enemy_object;
    enemy_t *enemy;

    if (game->total_time < tower->next_time)
        return;
    tower->next_time += tower->increment_time;
    enemy_object = get_enemy(object_list, \
        object->position, tower->range);
    if (enemy_object == NULL)
        return;
    enemy = enemy_object->component;
    enemy->hp -= tower->damage;
    enemy->damage_time = game->total_time + 0.1f;
    sfSprite_setColor(enemy_object->sprite, sfRed);
    if (enemy->hp <= 0)
        destroy_object(object_list, enemy_object);
}

void update_towers(game_t *game, node_t **object_list)
{
    node_t *it = *object_list;
    object_t *object;
    char type;

    while (it != NULL) {
        object = it->value;
        type = object->type;
        if (type == 't' || type == 'l' || type == 'b' || type == 'c') {
            update_tower(game, object, object_list);
        }
        it = it->next;
    }
}
