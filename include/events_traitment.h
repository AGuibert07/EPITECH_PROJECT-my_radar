/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this header file countains all events traitment tools
*/

#ifndef EVENTS_TRAITMENT_
    #define EVENTS_TRAITMENT_

    #include "my.h"
    #include "textures.h"

struct event_arguments
{
    bool_t show_sprites;
    bool_t show_boxes;
    bool_t show_trajectories;
    void **script_data;
    textures_versions_t *textures;
    sfSprite *background;
} typedef event_arguments_t;

int get_events(sfRenderWindow *window, event_arguments_t *arguments);

#endif /* EVENTS_TRAITMENT_ */
