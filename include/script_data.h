/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this header file countains all script data tools
*/

#include <SFML/Graphics.h>

struct aircraft_data {
    sfVector2i start_pos;
    sfVector2i end_pos;
    unsigned int speed;
    unsigned int delay;
} typedef aircraft_data;

struct control_tower_data {
    sfVector2i position;
    unsigned int area_radius;
} typedef control_tower_data;
