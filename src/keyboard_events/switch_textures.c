/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains the keyboard events functions to switch textures
*/

#include "my.h"
#include "textures.h"
#include "events_traitment.h"

int p_touch(event_arguments_t *arguments)
{
    update_plane_texture(arguments->script_data[0], arguments->textures);
    return EPITECH_SUCCESS;
}

int c_touch(event_arguments_t *arguments)
{
    update_tower_texture(arguments->script_data[1], arguments->textures);
    return EPITECH_SUCCESS;
}

int b_touch(event_arguments_t *arguments)
{
    update_background_texture(arguments->background, arguments->textures,
        arguments->script_data);
    return EPITECH_SUCCESS;
}
