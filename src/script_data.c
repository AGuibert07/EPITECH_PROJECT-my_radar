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

static void set_vector(sfVector2i *vector, int x_val, int y_val)
{
    (*vector).x = x_val;
    (*vector).y = y_val;
}

static bool_t check_aircraft_arguments(const char **data)
{
    int size = my_word_array_len(data);

    if (size != 7)
        return FALSE;
    for (int i = 1; i < size; ++i) {
        if (my_str_isnum(data[i]) != 0)
            return FALSE;
    }
    return TRUE;
}

static void set_move_vector_and_orientation(aircraft_t *plane)
{
    sfVector2f move = {(*plane).end_pos.x - (*plane).start_pos.x,
        (*plane).end_pos.y - (*plane).start_pos.y};
    double rad_angle = atan2f(move.y, move.x);
    double degree_angle = RAD_TO_DEGREE(rad_angle);
    double move_norm = sqrt((move.x * move.x) + (move.y * move.y));
    double factor = (1.0 * (*plane).speed) / move_norm;

    (*plane).orientation = degree_angle;
    (*plane).move_vector.x = move.x * factor;
    (*plane).move_vector.y = move.y * factor;
}

static aircraft_t *aircraft_create(const char **data)
{
    int size = my_word_array_len(data);
    aircraft_t *plane = malloc(sizeof(aircraft_t));

    if (plane == NULL || check_aircraft_arguments(data) != TRUE) {
        nfree(1, plane);
        return NULL;
    }
    (*plane).status = NOT_STARTED;
    set_vector(&(*plane).start_pos, my_getnbr(data[1]), my_getnbr(data[2]));
    set_vector(&(*plane).end_pos, my_getnbr(data[3]), my_getnbr(data[4]));
    set_vector(&(*plane).position, (*plane).start_pos.x, (*plane).start_pos.y);
    (*plane).speed = my_getnbr(data[5]);
    set_move_vector_and_orientation(plane);
    (*plane).delay = my_getnbr(data[6]);
    (*plane).sf_sprite = sfSprite_create();
    if ((*plane).sf_sprite == NULL) {
        free(plane);
        return NULL;
    }
    return plane;
}

static bool_t check_tower_arguments(const char **data)
{
    int size = my_word_array_len(data);

    if (size != 4)
        return FALSE;
    for (int i = 1; i < size; ++i) {
        if (my_str_isnum(data[i]) != 0)
            return FALSE;
    }
    return TRUE;
}

static tower_t *tower_create(const char **data)
{
    int size = my_word_array_len(data);
    tower_t *tower = malloc(sizeof(tower_t));

    if (tower == NULL || check_tower_arguments == FALSE) {
        nfree(1, tower);
        return NULL;
    }
    set_vector(&(*tower).position, my_getnbr(data[1]), my_getnbr(data[2]));
    (*tower).area_radius = my_getnbr(data[3]);
    (*tower).sf_sprite = sfSprite_create();
    if ((*tower).sf_sprite == NULL) {
        free(tower);
        return NULL;
    }
    return tower;
}

static aircraft_t **get_aircraft_data(const char **script_content)
{
    int size = my_word_array_len(script_content);
    aircraft_t **data = malloc(sizeof(aircraft_t *) * (size + 1));
    int index = 0;
    char **splited_line = NULL;

    for (int i = 0; i < size; ++i) {
        my_replace_in_str((char *)(script_content[i]), '\t', ' ');
        splited_line = my_split_str((char *)(script_content[i]), ' ');
        if (my_strcmp(splited_line[0], "A") == 0) {
            data[index] = aircraft_data_create((const char **)(splited_line));
            index += 1;
        }
        if (my_strcmp(splited_line[0], "A") == 0 && data[index - 1] == NULL) {
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

    for (int i = 0; i < size; ++i) {
        my_replace_in_str((char *)(script_content[i]), '\t', ' ');
        splited_line = my_split_str((char *)(script_content[i]), ' ');
        if (my_strcmp(splited_line[0], "T") == 0) {
            data[index] = tower_data_create((const char **)(splited_line));
            index += 1;
        }
        if (my_strcmp(splited_line[0], "T") && data[index - 1] == NULL) {
            free_array((void **)(data), 2);
            return NULL;
        }
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
