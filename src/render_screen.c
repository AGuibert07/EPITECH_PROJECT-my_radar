/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains all functions display the my_radar window
*/

#include <SFML/Graphics.h>
#include "sprites_structs.h"
#include "display_values.h"

int render_radar(sfRenderWindow *window, sfSprite *background,
    aircraft_t **planes, tower_t **towers)
{
    sfColor bg_color = sfColor_fromRGB(BACKGROUND_COLOR[0], BACKGROUND_COLOR[1],
        BACKGROUND_COLOR[2]);

    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window)) {
        
    }
}
