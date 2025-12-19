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
    #include "report.h"

struct event_arguments {
    bool_t show_sprites;
    bool_t show_boxes;
    bool_t show_trajectories;
    bool_t show_crash;
    bool_t close_at_end;
    void **script_data;
    textures_versions_t *textures;
    sfSprite *background;
    report_t *report;
} typedef event_arguments_t;

struct key_touch {
    sfKeyCode key_code;
    int (*function)(event_arguments_t *);
    struct key_touch *next;
} typedef key_touch_t;

    #define NBR_KEYBOARD_EVENTS 9

int get_events(sfRenderWindow *window, event_arguments_t *arguments);

// keyboard events functions
int l_touch(event_arguments_t *arguments);
int s_touch(event_arguments_t *arguments);
int t_touch(event_arguments_t *arguments);
int a_touch(event_arguments_t *arguments);
int p_touch(event_arguments_t *arguments);
int c_touch(event_arguments_t *arguments);
int b_touch(event_arguments_t *arguments);
int e_touch(event_arguments_t *arguments);

#endif /* EVENTS_TRAITMENT_ */
