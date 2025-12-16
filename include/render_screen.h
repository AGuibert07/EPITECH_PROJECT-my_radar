/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this header file countains all display values (screen sizes, sprites sizes,
** ...)
*/

#ifndef RENDER_SCREEN_
    #define RENDER_SCREEN_

    #include "SFML/Graphics.h"
    #include "sprites_structs.h"

    #define MICRO_SEC_TO_SEC(t) (t * 1000000)
    #define SEC_TO_MICRO_SEC(t) (t * 0.000001)

void check_collisions(aircraft_t **planes, tower_t **towers,
    sfTexture *texture_crash, sfClock *timer);
int render_radar(sfRenderWindow *window, sfSprite *background,
    void **script_data, sfTexture **textures);

#endif /* RENDER_SCREEN_ */
