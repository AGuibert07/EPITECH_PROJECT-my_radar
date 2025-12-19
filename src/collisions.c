/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains all functions check colisions between planes
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
// #include <math.h>
#include "sprites_structs.h"
#include "display_values.h"
#include "my.h"
// #include "render_screen.h"
#include "collisions.h"
#include "textures.h"
#include "report.h"

static bool_t is_plane_in_tower_zone(aircraft_t *plane, tower_t **towers)
{
    double dist_x = 0.0;
    double dist_y = 0.0;

    for (int i = 0; towers[i] != NULL; ++i) {
        dist_x = (*plane).position.x - (*towers[i]).position.x;
        dist_y = (*plane).position.y - (*towers[i]).position.y;
        if (sqrt(pow(dist_x, 2) + pow(dist_y, 2)) <= (*towers[i]).area_radius)
            return TRUE;
    }
    return FALSE;
}

static double get_square_radius(sfVector2f *vector, double angle_vector,
    double plane_orientation)
{
    double cos_val = 0.0;
    double angle_plane =
        FLOAT_MODULO(ABS(plane_orientation - angle_vector), 90);

    while (angle_plane >= 90) {
        angle_plane -= 90;
    }
    cos_val = cos(angle_plane);
    return (PLANE_SIZE / (cos_val * 2.0));
}

static bool_t is_collision_between_planes(aircraft_t *plane1,
    aircraft_t *plane2)
{
    sfVector2f vector = {(*plane2).position.x - (*plane1).position.x,
        (*plane2).position.y - (*plane1).position.y};
    double dist_centers = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
    double diag = sqrt(2 * pow(PLANE_BOX_SIZE, 2));
    double angle_vector = atan2(vector.y, vector.x);
    double dist1 = 0;
    double dist2 = 0;

    if (dist_centers > diag)
        return FALSE;
    dist1 = get_square_radius(&vector, angle_vector, (*plane1).orientation);
    dist2 = get_square_radius(&vector, angle_vector, (*plane2).orientation);
    if (dist_centers > (dist1 + dist2))
        return FALSE;
    return TRUE;
}

static bool_t check_collision_between_plane(aircraft_t *plane1,
    aircraft_t *plane2)
{
    if (plane1->status == NOT_STARTED || plane1->status == CRASHED ||
        plane1->status == ARRIVED)
        return FALSE;
    if (plane2->status == NOT_STARTED || plane2->status == CRASHED ||
        plane2->status == ARRIVED)
        return FALSE;
    return is_collision_between_planes(plane1, plane2);
}

static void crash_plane(aircraft_t *plane, element_textures_t *textures)
{
    if (plane->status == FLYING) {
        plane->status = CRASHING;
        set_crash_texture(plane, textures);
    }
}

static void check_plane(aircraft_t **planes, const int index,
    element_textures_t *textures)
{
    for (int i = (index + 1); planes[i] != NULL; ++i) {
        if (check_collision_between_plane(planes[index], planes[i])) {
            crash_plane(planes[index], textures);
            crash_plane(planes[i], textures);
        }
    }
}

void check_collisions(aircraft_t **planes, tower_t **towers,
    element_textures_t *textures)
{
    for (int i = 0; planes[i] != NULL; ++i) {
        if (is_plane_in_tower_zone(planes[i], towers) != TRUE)
            check_plane(planes, i, textures);
    }
}
