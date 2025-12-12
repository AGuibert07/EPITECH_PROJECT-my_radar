/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this header file countains all assets data
*/

#ifndef ASSETS_DATA_
    #define ASSETS_DATA_

    // backgrounds
    #define _BACKGROUNDS_PATHS_ ((char *[7]){"assets/backgrounds/world_map-1.png", \
        "assets/backgrounds/world_map-2.png", "assets/backgrounds/world_map-3.jpg", \
        "assets/backgrounds/world_map-4.png", "assets/backgrounds/world_map-5.png", \
        "assets/backgrounds/world_map-6.avif", 0})
    #define _BACKGROUNDS_WIDTHS_ ((int [6]){4977, 2560, 480, 740, 455, 740})
    #define _BACKGROUNDS_HEIGHTS_ ((int [6]){2515, 1280, 270, 367, 262, 423})

    // sprites
    #define _PLANES_PATHS_ ((char *[2]){"assets/sprites/plane-1.png", 0})
    #define _PLANES_WIDTHS_ ((int [1]){285})
    #define _PLANES_HEIGHTS_ ((int [1]){268})

    #define _TOWERS_PATHS_ ((char *[3]){"assets/sprites/tower-1.png", \
        "assets/sprites/tower-2.png", 0})
    #define _TOWERS_WIDTHS_ ((int [2]){512, 35})
    #define _TOWERS_HEIGHTS_ ((int [2]){512, 46})

    // selection
    #define _BACKGROUND_ID_ 4
    #define _PLANE_ID_ 1
    #define _TOWER_ID_ 2

#endif /* ASSETS_DATA_ */
