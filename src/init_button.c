/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-mydefender-clement.dreiski
** File description:
** init_button
*/

#include "utils.h"

void ibtt_menu(menu_t *menu)
{
    menu->button_vector.x = 770;
    menu->button_vector.y = 605;
    menu->button_rect.width = 375;
    menu->button_rect.height = 105;
    menu->vector_htp.x = 770;
    menu->vector_htp.y = 910;
    menu->rect_htp.width = 375;
    menu->rect_htp.height = 105;
    menu->vector_quit.x = 770;
    menu->vector_quit.y = 910;
    menu->rect_quit.width = 375;
    menu->rect_quit.height = 105;
}

void ibtt_pause(pause_t *pause)
{
    pause->vector_resume.x = 640;
    pause->vector_resume.y = 230;
    pause->rect_resume.width = 635;
    pause->rect_resume.height = 105;
    pause->vector_menu.x = 640;
    pause->vector_menu.y = 430;
    pause->rect_menu.width = 635;
    pause->rect_menu.height = 105;
    pause->vector_quit.x = 640;
    pause->vector_quit.y = 630;
    pause->rect_quit.width = 635;
    pause->rect_quit.height = 105;
}

void init_weapon(weapon_t *weapon)
{
    weapon->canon_vector.x = 715;
    weapon->canon_vector.y = 930;
    weapon->canon_rect.width = 110;
    weapon->canon_rect.height = 110;
    weapon->tower_vector.x = 850;
    weapon->tower_vector.y = 930;
    weapon->tower_rect.width = 110;
    weapon->tower_rect.height = 110;
    weapon->bigtower_vector.x = 850;
    weapon->bigtower_vector.y = 930;
    weapon->bigtower_rect.width = 110;
    weapon->bigtower_rect.height = 110;
    weapon->tesla_vector.x = 950;
    weapon->tesla_vector.y = 930;
    weapon->tesla_rect.width = 110;
    weapon->tesla_rect.height = 110;
}
