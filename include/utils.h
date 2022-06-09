/*
** EPITECH PROJECT, 2022
** Bootstrap-Defender
** File description:
** utils graphics
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "cly_linked_list.h"

typedef struct menu {
    sfTexture* menu_texture;
    sfSprite* menu_sprite;
    sfIntRect button_rect;
    sfVector2f button_vector;
    sfIntRect rect_quit;
    sfVector2f vector_quit;
    sfIntRect rect_htp;
    sfVector2f vector_htp;
} menu_t;

typedef struct pause {
    sfTexture* pause_texture;
    sfSprite* pause_sprite;
    sfIntRect button_rect;
    sfVector2f button_vector;
    sfIntRect rect_resume;
    sfVector2f vector_resume;
    sfIntRect rect_menu;
    sfVector2f vector_menu;
    sfIntRect rect_quit;
    sfVector2f vector_quit;
} pause_t;

typedef struct weapon {
    sfIntRect canon_rect;
    sfVector2f canon_vector;
    sfIntRect tower_rect;
    sfVector2f tower_vector;
    sfIntRect bigtower_rect;
    sfVector2f bigtower_vector;
    sfIntRect tesla_rect;
    sfVector2f tesla_vector;
} weapon_t;

typedef struct game_s {
    int display_mode;
    int money;
    int life;
    float delta_time;
    float total_time;
    char tower_type;
    menu_t menu;
    pause_t pause;
    weapon_t weapon;
    sfMusic *music_intro;
    sfMusic *music_background;
    sfRenderWindow* window;
    sfColor clear_color;
    sfClock *clock;
    sfMusic *music;
    sfVector2i mouse_position;
} game_t;

typedef struct animation_s {
    int offset;
    int max;
    float next_time;
    float increment_time;
} animation_t;

typedef struct tower_s {
    float next_time;
    float increment_time;
    int damage;
    int range;
} tower_t;

typedef struct object_s {
    char type;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    animation_t *animation;
    void *component;
    int layer;
} object_t;

typedef struct enemy_s {
    sfVector2f last_position;
    sfVector2f current_position;
    sfVector2f next_position;
    float damage_time;
    int hp;
} enemy_t;

int print_h(void);
int my_game(game_t *game, node_t **object_list);
void game_loop(game_t *game, node_t **object_list);
void menu_loop(game_t *game, node_t **object_list);
void pause_loop(game_t *game, node_t **object_list);

void button_game(game_t *game);
void button_menu(game_t *game);
void button_pause(game_t *game);
void ibtt_menu(menu_t *menu);
void ibtt_pause(pause_t *pause);

void init_weapon(weapon_t *weapon);

void init_map(node_t **object_list);
char *map_buffer(const char *filepath);
char **map_to_array(char *buffer);

void update_events(game_t *game, node_t **object_list);
void update_render(game_t *game, node_t **object_list);
game_t *create_game(unsigned int width, unsigned int height);
object_t *create_object(const char *sprite_path,
                        sfVector2f pos,
                        sfIntRect rect,
                        char type);
void create_enemy(game_t *game, node_t **object_list);
void update_enemies(game_t *game, node_t **object_list);
void destroy_object(node_t **object_list, object_t *object);
void update_towers(game_t *game, node_t **object_list);
void update_animations(game_t *game, node_t **object_list);
void update_plots(game_t *game, node_t **object_list);
void create_tower(game_t *game, sfVector2f position, node_t **object_list);
void destroy_game(game_t *game);

#endif /* !UTILS_H_ */