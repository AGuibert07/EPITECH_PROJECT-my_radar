/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this header file countains all events traitment tools
*/

#ifndef EVENTS_TRAITMENT_
    #define EVENTS_TRAITMENT_

    #include <SFML/Graphics.h>
    #include "my.h"
    #include "textures.h"

struct event_arguments {
    bool_t show_sprites;
    bool_t show_boxes;
    bool_t show_trajectories;
    bool_t show_crash;
    void **script_data;
    textures_versions_t *textures;
    sfSprite *background;
} typedef event_arguments_t;

struct key_touch {
    sfKeyCode key_code;
    void (*function)(event_arguments_t *);
    struct key_touch *next;
} typedef key_touch_t;

    #define NBR_TOUCH_EVENTS 8

int get_events(sfRenderWindow *window, event_arguments_t *arguments);

#endif /* EVENTS_TRAITMENT_ */
