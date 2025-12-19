/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains the keyboard events functions to enable/disable elements
*/

#include "my.h"
#include "events_traitment.h"

int l_touch(event_arguments_t *arguments)
{
    arguments->show_boxes = NOT(arguments->show_boxes);
    return EPITECH_SUCCESS;
}

int s_touch(event_arguments_t *arguments)
{
    arguments->show_sprites = NOT(arguments->show_sprites);
    return EPITECH_SUCCESS;
}

int t_touch(event_arguments_t *arguments)
{
    arguments->show_trajectories = NOT(arguments->show_trajectories);
    return EPITECH_SUCCESS;
}

int a_touch(event_arguments_t *arguments)
{
    arguments->show_crash = NOT(arguments->show_crash);
    return EPITECH_SUCCESS;
}
