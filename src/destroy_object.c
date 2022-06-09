/*
** EPITECH PROJECT, 2021
** BootstrapMyRunner
** File description:
** destroy_object.c
*/

#include <stdlib.h>
#include "utils.h"

void destroy_object(node_t **object_list, object_t *object)
{
    if (object->component != NULL)
        free(object->component);
    sfTexture_destroy(object->texture);
    sfSprite_destroy(object->sprite);
    cly_node_pop_item(object_list, object);
    free(object);
}
