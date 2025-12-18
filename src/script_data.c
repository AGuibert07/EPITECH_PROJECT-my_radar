/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** main file of the project
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "sprites_structs.h"
#include "display_values.h"

static void set_vector(sfVector2f *vector, int x_val, int y_val)
{
    (*vector).x = x_val;
    (*vector).y = y_val;
}

static bool_t check_script_arguments(const char **data,
    const unsigned int correct_arg_nbr)
{
    int size = my_word_array_len(data);

    if (size != correct_arg_nbr)
        return FALSE;
    for (int i = 1; i < size; ++i) {
        if (my_str_isnum(data[i]) != 0)
            return FALSE;
    }
    return TRUE;
}

static void set_origin_vector(aircraft_t *plane)
{
    double diag = sqrt(pow(PLANE_SIZE / 2.0, 2) * 2.0);
    double angle = FLOAT_MODULO(plane->orientation - 135, 360);

    if (angle < -180)
        angle += 360;
    angle = DEGREE_TO_RAD(angle);
    plane->origin.x = cos(angle) * diag;
    plane->origin.y = sin(angle) * diag;
}

static void set_plane_values(aircraft_t *plane, unsigned int speed,
    unsigned int delay)
{
    sfVector2f move = {plane->end_pos.x - plane->start_pos.x,
        plane->end_pos.y - plane->start_pos.y};
    double move_norm = sqrt(pow(move.x, 2) + pow(move.y, 2));
    double factor = 0.0;

    plane->speed = speed;
    factor = plane->speed / (FRAME_FREQ * move_norm);
    plane->status = NOT_STARTED;
    plane->orientation = RAD_TO_DEGREE(atan2f(move.y, move.x));
    plane->move_vector.x = move.x * factor;
    plane->move_vector.y = move.y * factor;
    set_origin_vector(plane);
    plane->delay = delay;
    plane->box = sfRectangleShape_create();
    plane->sf_sprite = sfSprite_create();
    plane->trajectory = sfRectangleShape_create();
    plane->crash_frame_index = -1;
}

static int aircraft_create(const char **data, aircraft_t **list,
    int index)
{
    int size = my_word_array_len(data);
    aircraft_t *plane = malloc(sizeof(aircraft_t));

    if (plane == NULL || check_script_arguments(data, 7) != TRUE) {
        nfree(1, plane);
        return EPITECH_ECHEC;
    }
    set_vector(&plane->start_pos, my_getnbr(data[1]), my_getnbr(data[2]));
    set_vector(&plane->end_pos, my_getnbr(data[3]), my_getnbr(data[4]));
    set_vector(&plane->position, plane->start_pos.x, plane->start_pos.y);
    set_plane_values(plane, my_getnbr(data[5]), my_getnbr(data[6]));
    if (plane->sf_sprite == NULL || plane->box == NULL ||
        plane->trajectory == NULL) {
        free(plane);
        return EPITECH_ECHEC;
    }
    list[index] = plane;
    return EPITECH_SUCCESS;
}

static void set_tower_values(tower_t *tower, double pos_x, double pos_y,
    unsigned int area_radius)
{
    tower->position.x = pos_x;
    tower->position.y = pos_y;
    tower->area_radius = area_radius;
    tower->sf_sprite = sfSprite_create();
    tower->zone = sfCircleShape_create();
    tower->origin.x = -TOWER_SIZE / 2.0;
    tower->origin.y = 0;
}

static int tower_create(const char **data, tower_t **list, int index)
{
    int size = my_word_array_len(data);
    tower_t *tower = malloc(sizeof(tower_t));
    sfVector2f position = {0, 0};

    if (tower == NULL || check_script_arguments(data, 4) == FALSE) {
        nfree(1, tower);
        return EPITECH_ECHEC;
    }
    set_tower_values(tower, my_getnbr(data[1]), my_getnbr(data[2]),
        my_getnbr(data[3]));
    (*tower).area_radius = my_getnbr(data[3]);
    if ((*tower).sf_sprite == NULL || (*tower).zone == NULL) {
        free(tower);
        return EPITECH_ECHEC;
    }
    set_vector(&position, (TOWER_SIZE / 2.0) - (*tower).area_radius,
        (TOWER_SIZE / 2.0) - (*tower).area_radius);
    sfCircleShape_setPosition((*tower).zone, position);
    list[index] = tower;
    return EPITECH_SUCCESS;
}

static aircraft_t **get_aircraft_data(const char **script_content)
{
    int size = my_word_array_len(script_content);
    aircraft_t **data = malloc(sizeof(aircraft_t *) * (size + 1));
    int index = 0;
    char **splited_line = NULL;
    int verif = 0;

    for (int i = 0; i < size; ++i) {
        my_replace_in_str((char *)(script_content[i]), '\t', ' ');
        splited_line = my_split_str((char *)(script_content[i]), ' ');
        if (my_strcmp(splited_line[0], "A") == 0) {
            verif = aircraft_create((const char **)(splited_line), data, index);
            index += 1;
        }
        if (verif == EPITECH_ECHEC) {
            free_array((void **)(data), 2);
            return NULL;
        }
    }
    data[index] = NULL;
    return data;
}

static tower_t **get_tower_data(const char **script_content)
{
    int size = my_word_array_len(script_content);
    tower_t **data = malloc(sizeof(tower_t *) * (size + 1));
    int index = 0;
    char **splited_line = NULL;
    int verif = 0;

    if (data == NULL)
        return NULL;
    for (int i = 0; i < size; ++i) {
        my_replace_in_str((char *)(script_content[i]), '\t', ' ');
        splited_line = my_split_str((char *)(script_content[i]), ' ');
        if (my_strcmp(splited_line[0], "T") == 0) {
            verif = tower_create((const char **)(splited_line), data, index);
            index += 1;
        }
        if (verif == EPITECH_ECHEC)
            return NULL;
    }
    data[index] = NULL;
    return data;
}

void **get_script_data_content(const char *file_name)
{
    char **content = get_file_content((char *)(file_name));
    aircraft_t **planes = NULL;
    tower_t **towers = NULL;
    void **r_data = malloc(sizeof(void *) * 3);

    if (r_data == NULL || content == NULL) {
        nfree(2, r_data, content);
        return NULL;
    }
    planes = get_aircraft_data((const char **)(content));
    towers = get_tower_data((const char **)(content));
    if (planes == NULL || towers == NULL) {
        nfree_array(2, 2, planes, towers);
        return NULL;
    }
    r_data[0] = (void *)(planes);
    r_data[1] = (void *)(towers);
    r_data[2] = NULL;
    return r_data;
}
