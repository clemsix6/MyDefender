/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** help
*/

#include "cly_io.h"

int print_h(void)
{
    cly_write(1, "USAGE\n");
    cly_write(1, "Game\n");
    cly_write(1, "DESCRIPTION\n");
    cly_write(1, "    Your task is to catch as many bear as you can\n");
    cly_write(1, "    in this game.\n");
    return 0;
}
