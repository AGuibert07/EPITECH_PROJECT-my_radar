/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains all functions display the my_radar window
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include "sprites_structs.h"
#include "display_values.h"
#include "my.h"
#include "render_screen.h"

static void get_keyboard_events(sfEvent *event, sfRenderWindow *window,
    bool_t *show_boxes, bool_t *show_trajectories)
{
    if (event->key.code == sfKeyEscape || event->key.code == sfKeyQ)
        sfRenderWindow_close(window);
    if (event->key.code == sfKeyL)
        *show_boxes = NOT(*show_boxes);
    if (event->key.code == sfKeyT)
        *show_trajectories = NOT(*show_trajectories);
}

static void get_events(sfRenderWindow *window, bool_t *show_boxes,
    bool_t *show_trajectories)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return;
        }
        if (event.type == sfEvtKeyPressed)
            get_keyboard_events(&event, window, show_boxes, show_trajectories);
    }
}

static bool_t is_aircraft_arrived(aircraft_t *plane)
{
    sfVector2f vector = {plane->end_pos.x - plane->position.x,
        plane->end_pos.y - plane->position.y};
    double norm_move = sqrt(pow(plane->move_vector.x, 2) +
        pow(plane->move_vector.y, 2));
    double dist = sqrt(pow(vector.x, 2) + pow(vector.y, 2));

    return (dist < norm_move);
}

static void update_plane_position(aircraft_t *plane)
{
    sfVector2f vector = {0, 0};

    plane->position.x += plane->move_vector.x;
    plane->position.y += plane->move_vector.y;
    vector = plane->position;
    vector.x += plane->origin.x;
    vector.y += plane->origin.y;
    sfSprite_setPosition(plane->sf_sprite, vector);
    sfRectangleShape_setPosition(plane->box, vector);
}

static void update_planes_display(aircraft_t **planes, sfClock *timer)
{
    sfVector2f vector = {0, 0};

    for (int i = 0; planes[i] != NULL; ++i) {
        if (planes[i]->status == NOT_STARTED &&
            sfClock_getElapsedTime(timer).microseconds >=
            SEC_TO_MICRO_SEC(planes[i]->delay))
            planes[i]->status = FLYING;
        if (is_aircraft_arrived(planes[i]))
            planes[i]->status = ARRIVED;
        if (planes[i]->status == FLYING)
            update_plane_position(planes[i]);
    }
}

static void check_crash_time(aircraft_t *plane, sfClock *timer)
{
    if (MICRO_SEC_TO_SEC(sfClock_getElapsedTime(timer).microseconds -
            (*plane).time_start_crash) >= TIME_TO_CRASH)
        (*plane).status = CRASHED;
}

static void render_towers(sfRenderWindow *window, tower_t **towers,
    bool_t *bool_options)
{
    for (int i = 0; towers[i] != NULL; ++i) {
        if (bool_options[0])
            sfRenderWindow_drawCircleShape(window, towers[i]->zone, NULL);
        sfRenderWindow_drawSprite(window, towers[i]->sf_sprite, NULL);
    }
}

static void render_planes(sfRenderWindow *window, aircraft_t **planes,
    bool_t *bool_options, sfClock *timer)
{
    bool_t status = FALSE;

    for (int i = 0; planes[i] != NULL; ++i) {
        status = (planes[i]->status == FLYING ||
            planes[i]->status == CRASHING);
        if (planes[i]->status == CRASHING)
            check_crash_time(planes[i], timer);
        if (bool_options[1] && status) {
            sfRenderWindow_drawRectangleShape(window, planes[i]->trajectory,
                NULL);
        }
        if (bool_options[0] && status)
            sfRenderWindow_drawRectangleShape(window, planes[i]->box, NULL);
        if (status)
            sfRenderWindow_drawSprite(window, planes[i]->sf_sprite, NULL);
    }
}

static void render_sprites(sfRenderWindow *window, void **script_data,
    bool_t *bool_options, sfClock *timer)
{
    render_towers(window, script_data[1], bool_options);
    render_planes(window, script_data[0], bool_options, timer);
    
}

static void refresh_screen(void **script_data, sfTexture **textures,
    sfClock *timer, sfClock *frame_timer)
{
    aircraft_t **planes = script_data[0];
    if (sfClock_getElapsedTime(frame_timer).microseconds >= FRAME_TIME) {
        update_planes_display(script_data[0], timer);
        check_collisions(script_data[0], script_data[1], textures[3], timer);
        sfClock_restart(frame_timer);
    }
}

int render_radar(sfRenderWindow *window, sfSprite *background,
    void **script_data, sfTexture **textures)
{
    sfColor bg_color = sfColor_fromRGB(BACKGROUND_COLOR[0], BACKGROUND_COLOR[1],
        BACKGROUND_COLOR[2]);
    sfClock *timer = sfClock_create();
    sfClock *frame_timer = sfClock_create();
    bool_t bool_options[2] = {TRUE, FALSE};

    if (timer == NULL || frame_timer == NULL)
        return EPITECH_ECHEC;
    sfRenderWindow_setFramerateLimit(window, FRAME_FREQ_MAX);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, bg_color);
        sfRenderWindow_drawSprite(window, background, NULL);
        refresh_screen(script_data, textures, timer, frame_timer);
        render_sprites(window, script_data, bool_options, timer);
        sfRenderWindow_display(window);
        get_events(window, &bool_options[0], &bool_options[1]);
    }
    sfClock_destroy(timer);
    return EPITECH_SUCCESS;
}
