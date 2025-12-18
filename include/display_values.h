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
    #define CRASH_PATH (_CRASHS_PATHS_[_CRASH_ID_ - 1])

    // sprites data
    #define PLANE_SIZE 16
    #define PLANE_BOX_SIZE 20
    #define TOWER_SIZE 20
    #define PLANE_SCALE ((1.0 * PLANE_SIZE) / PLANE_WIDTH)
    #define TOWER_SCALE ((1.0 * TOWER_SIZE) / TOWER_WIDTH)
    #define BOX_LINE_SIZE 4
    #define NBR_VERSIONS ((int [3]){_PLANES_NBR_, _TOWERS_NBR_, _BG_NBR_})

    // frames
    #define FRAME_FREQ 25
    #define FRAME_FREQ_MAX 60
    #define FRAME_TIME (1000000.0 / FRAME_FREQ)
    #define TIME_TO_CRASH 1

    // colors
    #define PLANE_BOX_COLOR ((int [3]){252, 220, 119})
    #define TOWER_AREA_COLOR ((int [3]){186, 217, 165})
    #define TRAJECTORIES_COLOR ((int [3]){255, 255, 255})

    // crash animation
    #define CRASH_FRAME_NBR (_F_NBR_)
    #define FRAME_WIDTH (_FRAME_WIDTH_)
    #define FRAME_HEIGHT (_FRAME_HEIGHT_)
    #define CRASH_FILE_NAME "assets/sprites/crash-1.png"
    #define FRAMES_AREAS_COORDS (_FRAME_COORDS_)
    #define CRASH_SIZE ((PLANE_SIZE * FRAME_WIDTH) / _FRAME_PLANE_PART_SIZE_)

#endif /* DISPLAY_VALUES_ */
