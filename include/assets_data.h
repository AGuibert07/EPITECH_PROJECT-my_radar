/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this header file countains all assets data
*/

#ifndef ASSETS_DATA_
    #define ASSETS_DATA_

    #include <SFML/Graphics.h>

    // backgrounds colors
    #define BC1 ((int [3]){182, 220, 244})
    #define BC2 ((int [3]){218, 240, 253})
    #define BC3 ((int[3]){0, 3, 6})
    #define BC4 ((int[3]){176, 175, 181})
    #define BC5 ((int[3]){255, 255, 255})
    #define BC6 ((int[3]){248, 248, 248})

    // backgrounds
    //      backgrounds paths
    #define BP1 "assets/backgrounds/world_map-1.png"
    #define BP2 "assets/backgrounds/world_map-2.png"
    #define BP3 "assets/backgrounds/world_map-3.png"
    #define BP4 "assets/backgrounds/world_map-4.png"
    #define BP5 "assets/backgrounds/world_map-5.png"
    #define BP6 "assets/backgrounds/world_map-6.png"

    #define _BACKGROUNDS_PATHS_ ((char *[7]){BP1, BP2, BP3, BP4, BP5, BP6, 0})
    #define _BACKGROUNDS_WIDTHS_ ((int [6]){4977, 2560, 480, 740, 455, 740})
    #define _BACKGROUNDS_HEIGHTS_ ((int [6]){2515, 1280, 270, 367, 262, 423})
    #define _BACKGROUNDS_COLORS_ ((int *[6]){BC1, BC2, BC3, BC4, BC5, BC6})

    // sprites
    //      planes
    //          planes paths
    #define PP1 "assets/sprites/plane-1.png"
    //          crash paths
    #define CP1 "assets/sprites/crash-1.png"

    #define _PLANES_PATHS_ ((char *[2]){PP1, 0})
    #define _PLANES_WIDTHS_ ((int [1]){285})
    #define _PLANES_HEIGHTS_ ((int [1]){268})
    #define _CRASHS_PATHS_ ((char *[2]){CP1, 0})

    //      towers
    //          towers paths
    #define TP1 "assets/sprites/tower-1.png"
    #define TP2 "assets/sprites/tower-2.png"

    #define _TOWERS_PATHS_ ((char *[3]){TP1, TP2, 0})
    #define _TOWERS_WIDTHS_ ((int [2]){512, 35})
    #define _TOWERS_HEIGHTS_ ((int [2]){512, 46})

    // selection
    //      versions number
    #define _BACKGROUNDS_NBR_ 6
    #define _PLANES_NBR_ 1
    #define _TOWERS_NBR_ 2
    #define _CRASHS_NBR_ 1
    //      selected version id
    #define _BACKGROUND_ID_ 3
    #define _PLANE_ID_ 1
    #define _TOWER_ID_ 2
    #define _CRASH_ID_ 1

#endif /* ASSETS_DATA_ */
