/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** main file of the project
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "script_data.h"

static void set_vector(sfVector2i *vector, int x_val, int y_val)
{
    (*vector).x = x_val;
    (*vector).y = y_val;
}

static aircraft_data_t *aircraft_data_create(const char **data)
{
    int size = my_word_array_len(data);
    aircraft_data_t *plane = malloc(sizeof(aircraft_data_t));

    if (plane == NULL)
        return NULL;
    if (size != 7) {
        free(plane);
        return NULL;
    }
    for (int i = 1; i < size; ++i) {
        if (my_str_isnum(data[i]) != 0) {
            free(plane);
            return NULL;
        }
    }
    set_vector(&(*plane).start_pos, my_getnbr(data[1]), my_getnbr(data[2]));
    set_vector(&(*plane).end_pos, my_getnbr(data[3]), my_getnbr(data[4]));
    (*plane).speed = my_getnbr(data[5]);
    (*plane).delay = my_getnbr(data[6]);
    return plane;
}

static tower_data_t *tower_data_create(const char **data)
{
    int size = my_word_array_len(data);
    tower_data_t *tower = malloc(sizeof(tower_data_t));

    if (tower == NULL)
        return NULL;
    if (size != 4) {
        free(tower);
        return NULL;
    }
    for (int i = 1; i < size; ++i) {
        if (my_str_isnum(data[i]) != 0) {
            free(tower);
            return NULL;
        }
    }
    set_vector(&(*tower).position, my_getnbr(data[1]), my_getnbr(data[2]));
    (*tower).area_radius = my_getnbr(data[3]);
    return tower;
}

static aircraft_data_t **get_aircraft_data(const char **script_content)
{
    int size = my_word_array_len(script_content);
    aircraft_data_t **data = malloc(sizeof(aircraft_data_t *) * (size + 1));
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

static tower_data_t **get_tower_data(const char **script_content)
{
    int size = my_word_array_len(script_content);
    tower_data_t **data = malloc(sizeof(tower_data_t *) * (size + 1));
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
    aircraft_data_t **planes = NULL;
    tower_data_t **towers = NULL;
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

void sf_vector_2i_print(sfVector2i *vector)
{
    my_putstr("( ");
    my_put_nbr((*vector).x);
    my_putstr(" ; ");
    my_put_nbr((*vector).y);
    my_putstr(" )");
}

void aircraft_data_print(aircraft_data_t *data)
{
    my_putstr("A ");
    sf_vector_2i_print(&(*data).start_pos);
    my_putstr(" -> ");
    sf_vector_2i_print(&(*data).end_pos);
    my_putstr(" - ");
    my_put_nbr((*data).speed);
    my_putstr("px/s ; ");
    my_put_nbr((*data).delay);
    my_putstr("sec");
}

void tower_data_print(tower_data_t *data)
{
    my_putstr("T ");
    sf_vector_2i_print(&(*data).position);
    my_putstr(" - ");
    my_put_nbr((*data).area_radius);
    my_putstr("px");
}
