/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** update_enemy.c
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "utils.h"

object_t *get_case(node_t **object_list, sfVector2f pos)
{
    node_t *it = *object_list;
    object_t *obj;

    while (it != NULL) {
        obj = it->value;
        if (obj->type == '0' && \
            obj->position.x == pos.x && \
            obj->position.y == pos.y)
            return obj;
        it = it->next;
    }

    return NULL;
}

bool next_case(object_t *object,
enemy_t *enemy, node_t **object_list)
{
    sfVector2f next[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    sfVector2f next_pos;
    object_t *next_case;

    object->position = enemy->current_position;
    for (int i = 0; i < 4; i++) {
        next_pos = next[i];
        next_pos.x = next_pos.x * 100 + object->position.x;
        next_pos.y = next_pos.y * 100 + object->position.y;
        if (next_pos.x == enemy->last_position.x && \
            next_pos.y == enemy->last_position.y)
            continue;
        next_case = get_case(object_list, next_pos);
        if (next_case != NULL) {
            enemy->last_position = enemy->current_position;
            enemy->current_position = enemy->next_position;
            enemy->next_position = next_case->position;
            return true;
        }
    }

    return false;
}

void move_enemy(game_t *game, object_t *object, enemy_t *enemy)
{
    const int speed = 2;
    
    if (enemy->current_position.x < enemy->next_position.x) {
        object->position.x += 100 * speed * game->delta_time;
        if (object->position.x > enemy->next_position.x)
            enemy->current_position = enemy->next_position;
    } else if (enemy->current_position.x > enemy->next_position.x) {
        object->position.x -= 100 * speed  * game->delta_time;
        if (object->position.x < enemy->next_position.x)
            enemy->current_position = enemy->next_position;
    } else if (enemy->current_position.y < enemy->next_position.y) {
        object->position.y += 100 * speed  * game->delta_time;
        if (object->position.y > enemy->next_position.y)
            enemy->current_position = enemy->next_position;
    } else if (enemy->current_position.y > enemy->next_position.y) {
        object->position.y -= 100 * speed  * game->delta_time;
        if (object->position.y < enemy->next_position.y)
            enemy->current_position = enemy->next_position;
    }
}

void update_enemy(game_t *game, object_t *object, node_t **object_list)
{
    enemy_t *enemy = object->component;

    if (enemy->current_position.x == enemy->next_position.x && \
        enemy->current_position.y == enemy->next_position.y) {
        if (!next_case(object, enemy, object_list)) {
            game->life--;
            destroy_object(object_list, object);
        }
    } else {
        move_enemy(game, object, enemy);
    }
}

void update_enemies(game_t *game, node_t **object_list)
{
    node_t *it = *object_list;
    object_t *obj;

    while (it != NULL) {
        obj = it->value;
        if (obj->type == 'e')
            update_enemy(game, obj, object_list);
        it = it->next;
    }
}
