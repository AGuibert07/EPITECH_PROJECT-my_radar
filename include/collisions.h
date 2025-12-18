/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this header file countains all display values (screen sizes, sprites sizes,
** ...)
*/

#ifndef COLLISIONS_
    #define COLLISIONS_

    #include <SFML/Graphics.h>
    #include "textures.h"
    #include "sprites_structs.h"
    #include "report.h"

struct segment {
    sfVector2f point1;
    sfVector2f point2;
    sfVector2f vector;
    double direction;
    double dist;
} typedef segment_t;

// void check_collisions(aircraft_t **planes, tower_t **towers,
//     sfTexture *texture_crash, sfClock *timer);
void check_collisions(aircraft_t **planes, tower_t **towers,
    element_textures_t *textures, report_t *report);

#endif /* COLLISIONS_ */
