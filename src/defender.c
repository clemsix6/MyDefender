/*
** EPITECH PROJECT, 2022
** Bootstrap-Defender
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <utils.h>
#include "cly_linked_list.h"
#include "cly_string.h"

int main(int argc, char **argv)
{
    node_t *null_node = NULL;
    node_t **object_list = &null_node;
    game_t *game = create_game(1920, 1080);

    if (argc == 1) {
        return my_game(game, object_list);
    } else if (cly_strcmp(argv[1], "-h") == 0 && argc == 2) {
        return print_h();
    } else {
        return 84;
    }
    return 0;
}
