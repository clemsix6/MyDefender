/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** map
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <utils.h>
#include "cly_linked_list.h"

void add_object(char c, sfVector2f position, node_t **object_list)
{
    sfIntRect rect = {0, 0, 100, 100};

    if (c == 'X') {
        object_t *obj = create_object("assets/grass_tile.png",\
            position, rect, 'X');
        cly_node_push_back(object_list, obj);
    }
    if (c == '0') {
        object_t *obj = create_object("assets/sand_tile.png", \
                position, rect, '0');
        cly_node_push_back(object_list, obj);
    }
    if (c == 'R') {
        object_t *obj = create_object("assets/rock.png", \
            position, rect, 'R');
        cly_node_push_back(object_list, obj);
    }
}

void map_tolist(char **map, node_t **object_list)
{
    sfVector2f position = {160, 60};

    for (int i = 0; i < 11;i++) {
        for (int j = 0; j < 16; j++) {
            add_object(map[i][j], position, object_list);
            position.x += 100;
        }
        position.y += 100;
        position.x = 160;
    }
}

void create_weapon(node_t **object_list)
{
    sfVector2f board_position = {660, 930};
    sfIntRect board_rect = {0, 0, 600, 150};

    object_t *weapon_bar = create_object("assets/board.png", board_position, board_rect, '1');
    weapon_bar->layer = 9;
    cly_node_push_back(object_list, weapon_bar);
}


void create_design(node_t **object_list)
{
    sfVector2f position_bar = {0, 0};
    sfIntRect rect_bar = {0, 0, 1920, 60};
    sfVector2f position_right = {0, 0};
    sfIntRect rect_right = {0, 0, 160, 1080};
    sfVector2f position_left = {1760, 0};
    sfIntRect rect_left = {0, 0, 160, 1080};

    object_t *obj_right = create_object("assets/right_side.png", \
        position_right, rect_right, '1');
    cly_node_push_back(object_list, obj_right);

    object_t *obj_left = create_object("assets/left_side.png", \
        position_left, rect_left, '1');
    cly_node_push_back(object_list, obj_left);

    object_t *obj_bar = create_object("assets/bar_info.png", \
        position_bar, rect_bar, '1');
    cly_node_push_back(object_list, obj_bar);

}

void init_map(node_t **object_list)
{
    char *buffer = map_buffer("assets/map1.txt");
    char **map_array = map_to_array(buffer);

    create_design(object_list);
    create_weapon(object_list);
    map_tolist(map_array, object_list);
}
