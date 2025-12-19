/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains all functions to display the my_radar window
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include "sprites_structs.h"
#include "display_values.h"
#include "my.h"
#include "render_screen.h"
#include "textures.h"
#include "events_traitment.h"
#include "collisions.h"
#include "report.h"

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
    vector.x = (plane->position.x) + (plane->origin.x);
    vector.y = (plane->position.y) + (plane->origin.y);
    sfSprite_setPosition(plane->sf_sprite, vector);
    sfRectangleShape_setPosition(plane->box, plane->position);
}

static void update_planes_display(aircraft_t **planes, sfClock *timer,
    report_t *report)
{
    sfVector2f vector = {0, 0};

    for (int i = 0; planes[i] != NULL; ++i) {
        if (planes[i]->status == NOT_STARTED &&
            sfClock_getElapsedTime(timer).microseconds >=
            SEC_TO_MICRO_SEC(planes[i]->delay))
            planes[i]->status = FLYING;
        if (is_aircraft_arrived(planes[i]) && planes[i]->status == FLYING) {
            planes[i]->status = ARRIVED;
            report->plane_arrived += 1;
        }
        if (planes[i]->status == FLYING)
            update_plane_position(planes[i]);
    }
}

static void render_plane(sfRenderWindow *window, aircraft_t *plane,
    event_arguments_t *event_arguments, textures_versions_t *textures)
{
    if (plane->status == CRASHING) {
        if (plane->crash_frame_index + 1 >=
            textures->crash_textures->versions_nbr) {
            plane->status = CRASHED;
            return;
        }
        update_crash_texture(plane, textures->crash_textures);
    }
    if (event_arguments->show_trajectories && plane->status == FLYING)
        sfRenderWindow_drawRectangleShape(window, plane->trajectory, NULL);
    if (event_arguments->show_boxes && plane->status == FLYING)
        sfRenderWindow_drawRectangleShape(window, plane->box, NULL);
    if (event_arguments->show_sprites)
        sfRenderWindow_drawSprite(window, plane->sf_sprite, NULL);
}

static void render_sprites(sfRenderWindow *window, void **script_data,
    event_arguments_t *event_arguments, textures_versions_t *textures)
{
    aircraft_t **planes = script_data[0];
    tower_t **towers = script_data[1];

    for (int i = 0; towers[i] != NULL; ++i) {
        if (event_arguments->show_boxes)
            sfRenderWindow_drawCircleShape(window, towers[i]->zone, NULL);
        if (event_arguments->show_sprites)
            sfRenderWindow_drawSprite(window, towers[i]->sf_sprite, NULL);
    }
    for (int i = 0; planes[i] != NULL; ++i) {
        if (planes[i]->status == FLYING || (planes[i]->status == CRASHING &&
                event_arguments->show_crash))
            render_plane(window, planes[i], event_arguments, textures);
    }
}

static void refresh_screen(void **script_data, textures_versions_t *textures,
    sfClock **timers, report_t *report)
{
    if (sfClock_getElapsedTime(timers[1]).microseconds >= FRAME_TIME) {
        update_planes_display(script_data[0], timers[0], report);
        check_collisions(script_data[0], script_data[1],
            textures->crash_textures, report);
        sfClock_restart(timers[1]);
    }
}

static unsigned int count_sprites(const void **list)
{
    unsigned int nbr = 0;

    for (int i = 0; list[i] != NULL; ++i) {
        nbr += 1;
    }
    return nbr;
}

static int end_of_execution(report_t *report, sfClock **timers)
{
    sfClock_destroy(timers[0]);
    sfClock_destroy(timers[1]);
    print_report(report);
    return EPITECH_SUCCESS;
}

static void frame_reset(sfRenderWindow *window, event_arguments_t *arguments,
    sfSprite *background, textures_versions_t *textures)
{
    get_events(window, arguments);
    sfRenderWindow_clear(window, textures->bg_textures->textures[textures->
            bg_textures->version_id].colors.background_color);
    sfRenderWindow_drawSprite(window, background, NULL);
}

int render_radar(sfRenderWindow *window, sfSprite *background,
    void **script_data, textures_versions_t *textures)
{
    sfColor bg_color = sfColor_fromRGB(BACKGROUND_COLOR[0], BACKGROUND_COLOR[1],
        BACKGROUND_COLOR[2]);
    sfClock *timers[2] = {sfClock_create(), sfClock_create()};
    event_arguments_t arguments = {TRUE, TRUE, FALSE, TRUE, TRUE, script_data,
        textures, background};
    report_t report = {count_sprites((const void **)(script_data[1])),
        count_sprites((const void **)(script_data[0])), 0, 0};

    if (timers[0] == NULL || timers[1] == NULL)
        return EPITECH_ECHEC;
    sfRenderWindow_setFramerateLimit(window, FRAME_FREQ_MAX);
    while (sfRenderWindow_isOpen(window) &&
        ((report.plane_arrived + report.plane_crashed) < report.plane_nbr ||
            arguments.close_at_end == FALSE)) {
        frame_reset(window, &arguments, background, textures);
        refresh_screen(script_data, textures, timers, &report);
        render_sprites(window, script_data, &arguments, textures);
        sfRenderWindow_display(window);
    }
    return end_of_execution(&report, timers);
}
