/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this header file countains all display values (screen sizes, sprites sizes,
** ...)
*/

#ifndef DISPLAY_VALUES_
    #define DISPLAY_VALUES_

    #include "assets_data.h"

    #define SCREEN_WIDTH 1920
    #define SCREEN_HEIGHT 1080
    #define SCREEN_RATIO ((1.0 * SCREEN_WIDTH) / SCREEN_HEIGHT)
    #define SCREEN_BPP 32

    // background data
    #define BACKGROUND_PATH (_BACKGROUNDS_PATHS_[_BACKGROUND_ID_ - 1])
    #define BACKGROUND_WIDTH (_BACKGROUNDS_WIDTHS_[_BACKGROUND_ID_ - 1])
    #define BACKGROUND_HEIGHT (_BACKGROUNDS_HEIGHTS_[_BACKGROUND_ID_ - 1])
    #define BACKGROUND_RATIO ((1.0 * BACKGROUND_WIDTH) / BACKGROUND_HEIGHT)
    #define BACKGROUND_COLOR (_BACKGROUNDS_COLORS_[_BACKGROUND_ID_ - 1])

    // sprite sheets data
    #define PLANE_PATH (_PLANES_PATHS_[_PLANE_ID_ - 1])
    #define PLANE_WIDTH (_PLANES_WIDTHS_[_PLANE_ID_ - 1])
    #define PLANE_HEIGHT (_PLANES_HEIGHTS_[_PLANE_ID_ - 1])
    #define TOWER_PATH (_TOWERS_PATHS_[_TOWER_ID_ - 1])
    #define TOWER_WIDTH (_TOWERS_WIDTHS_[_TOWER_ID_ - 1])
    #define TOWER_HEIGHT (_TOWERS_HEIGHTS_[_TOWER_ID_ - 1])

    // sprites data
    #define PLANE_SIZE 24
    #define TOWER_SIZE 25
    #define PLANE_SCALE ((1.0 * PLANE_SIZE) / PLANE_WIDTH)
    #define TOWER_SCALE ((1.0 * TOWER_SIZE) / TOWER_WIDTH)

#endif /* DISPLAY_VALUES_ */
