/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains all functions display the my_radar window
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "sprites_structs.h"
#include "display_values.h"
#include "my.h"
#include "render_screen.h"

static void get_keyboard_events(sfEvent *event, sfRenderWindow *window,
    bool_t *show_boxes)
{
    if (event->key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event->key.code == sfKeyL)
        *show_boxes = NOT(*show_boxes);
}

static void get_events(sfRenderWindow *window, bool_t *show_boxes)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return;
        }
        if (event.type == sfEvtKeyPressed)
            get_keyboard_events(&event, window, show_boxes);
    }
}

static void update_planes_display(aircraft_t **planes, sfClock *timer)
{
    sfVector2f vector = {0, 0};

    for (int i = 0; planes[i] != NULL; ++i) {
        if ((*planes[i]).status == NOT_STARTED &&
            sfClock_getElapsedTime(timer).microseconds >=
            SEC_TO_MICRO_SEC((*planes[i]).delay))
            (*planes[i]).status = FLYING;
        if ((*planes[i]).status == FLYING) {
            (*planes[i]).position.x += (*planes[i]).move_vector.x;
            (*planes[i]).position.y += (*planes[i]).move_vector.y;
            vector = (*planes[i]).position;
            vector.x -= (PLANE_SIZE / 2.0);
            vector.y -= (PLANE_SIZE / 2.0);
            sfSprite_setPosition((*planes[i]).sf_sprite, vector);
        }
    }
}

static void check_crash_time(aircraft_t *plane, sfClock *timer)
{
    if (MICRO_SEC_TO_SEC(sfClock_getElapsedTime(timer).microseconds -
            (*plane).time_start_crash) >= TIME_TO_CRASH)
        (*plane).status = CRASHED;
}

static void render_sprites(sfRenderWindow *window, void **script_data,
    bool_t *show_boxes, sfClock *timer)
{
    aircraft_t **planes = script_data[0];
    tower_t **towers = script_data[1];

    for (int i = 0; planes[i] != NULL; ++i) {
        if ((*planes[i]).status == CRASHING)
            check_crash_time(planes[i], timer);
        if (*show_boxes)
            sfRenderWindow_drawRectangleShape(window, (*planes[i]).box, NULL);
        if ((*planes[i]).status == FLYING || (*planes[i]).status == CRASHING)
            sfRenderWindow_drawSprite(window, (*planes[i]).sf_sprite, NULL);
    }
    for (int i = 0; towers[i] != NULL; ++i) {
        if (*show_boxes)
            sfRenderWindow_drawCircleShape(window, (*towers[i]).zone, NULL);
        sfRenderWindow_drawSprite(window, (*towers[i]).sf_sprite, NULL);
    }
}

int render_radar(sfRenderWindow *window, sfSprite *background,
    void **script_data, sfTexture **textures)
{
    sfColor bg_color = sfColor_fromRGB(BACKGROUND_COLOR[0], BACKGROUND_COLOR[1],
        BACKGROUND_COLOR[2]);
    sfClock *timer = sfClock_create();
    sfClock *frame_timer = sfClock_create();
    bool_t show_boxes = TRUE;

    if (timer == NULL || frame_timer == NULL)
        return EPITECH_ECHEC;
    sfRenderWindow_setFramerateLimit(window, FRAME_FREQ_MAX);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, bg_color);
        sfRenderWindow_drawSprite(window, background, NULL);
        if (sfClock_getElapsedTime(frame_timer).microseconds >=
            SEC_TO_MICRO_SEC(FRAME_TIME)) {
            update_planes_display(script_data[0], timer);
            check_collisions(script_data[0], script_data[1], textures[3], timer);
        }
        render_sprites(window, script_data[0], script_data[1], timer);
        sfRenderWindow_display(window);
        get_events(window, &show_boxes);
    }
    sfClock_destroy(timer);
    return EPITECH_SUCCESS;
}
