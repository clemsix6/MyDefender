/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** update_plot
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <utils.h>
#include "cly_linked_list.h"
#include "cly_string.h"

object_t *tower_already_exists(sfVector2f position, node_t **object_list)
{
    node_t *it = *object_list;
    object_t *object;

    while (it != NULL) { 
        object = it->value;
        if (object->type == 't' && \
            object->position.x == position.x && \
            object->position.y == position.y)
            return object;
        it = it->next;
    }
    return NULL;
}

void update_plot(game_t *game, \
                object_t *object, \
                sfVector2i mouse_pos, \
                node_t **object_list)
{
    if (mouse_pos.x > object->position.x && \
        mouse_pos.x < object->position.x + 100 && \
        mouse_pos.y > object->position.y && \
        mouse_pos.y < object->position.y + 100 &&
        tower_already_exists(object->position, object_list) == NULL)
        create_tower(game, object->position, object_list);
}

void update_plots(game_t *game, node_t **object_list)
{
    node_t *it = *object_list;
    object_t *object;

    while (it != NULL) { 
        object = it->value;
        if (object->type == 'R')
            update_plot(game, object, game->mouse_position, object_list);
        it = it->next;
    }
}
