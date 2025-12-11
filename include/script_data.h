/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this header file countains all script data tools
*/

#include <SFML/Graphics.h>

#ifndef SRCIPT_DATA_
    #define SRCIPT_DATA_

struct aircraft_data {
    sfVector2i start_pos;
    sfVector2i end_pos;
    unsigned int speed;
    unsigned int delay;
} typedef aircraft_data_t;

struct control_tower_data {
    sfVector2i position;
    unsigned int area_radius;
} typedef tower_data_t;

void **get_script_data_content(const char *file_name);
void sf_vector_2i_print(sfVector2i *vector);
void aircraft_data_print(aircraft_data_t *data);
void tower_data_print(tower_data_t *data);

#endif /* SRCIPT_DATA_ */
