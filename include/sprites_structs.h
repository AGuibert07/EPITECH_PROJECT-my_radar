/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this header file countains all sprites_structs tools
*/

#include <SFML/Graphics.h>
#include <math.h>

#ifndef SPRITES_STRUCTS_
    #define SPRITES_STRUCTS_

    #define MY_PI 3.14159265358979323846
    #define RAD_TO_DEGREE(a) ((180.0 * a) / MY_PI)
    #define DEGREE_TO_RAD(a) ((MY_PI * a) / 180.0)
    #include "script_data.h"

enum aircraft_status {
    NOT_STARTED,
    FLYING,
    ARRIVED,
    CRASHING,
    CRASHED
} typedef aircraft_status_t;

struct aircraft {
    aircraft_status_t status;
    sfVector2f position;
    double orientation;
    unsigned speed;
    sfVector2f start_pos;
    sfVector2f end_pos;
    sfVector2f move_vector;
    sfVector2f origin;
    unsigned int delay;
    sfSprite *sf_sprite;
    sfRectangleShape *box;
    double time_start_crash;
    sfRectangleShape *trajectory;
} typedef aircraft_t;

struct tower {
    sfVector2f position;
    unsigned int area_radius;
    sfSprite *sf_sprite;
    sfCircleShape *zone;
} typedef tower_t;

void **get_script_data_content(const char *file_name);

#endif /* SPRITES_STRUCTS_ */
