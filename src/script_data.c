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

static int script_line_traitment_for_plane(const char *script_line,
    aircraft_t **data, int *index)
{
    char **splited_line = NULL;
    int verif = 0;

    my_replace_in_str((char *)(script_line), '\t', ' ');
    splited_line = my_split_str((char *)(script_line), ' ');
    if (splited_line == NULL) {
        free_array((void **)(data), 2);
        return EPITECH_ECHEC;
    }
    if (my_strcmp(splited_line[0], "A") == 0) {
        verif = aircraft_create((const char **)(splited_line), data, *index);
        *index += 1;
    }
    free_array((void **)(splited_line), 2);
    if (verif == EPITECH_ECHEC) {
        free_array((void **)(data), 2);
        return EPITECH_ECHEC;
    }
    return EPITECH_SUCCESS;
}

static aircraft_t **get_aircraft_data(const char **script_content)
{
    int size = my_word_array_len(script_content);
    aircraft_t **data = malloc(sizeof(aircraft_t *) * (size + 1));
    int index = 0;
    int verif = 0;

    for (int i = 0; i < size; ++i) {
        verif = script_line_traitment_for_plane(script_content[i], data,
            &index);
        if (verif != EPITECH_SUCCESS)
            return NULL;
    }
    data[index] = NULL;
    return data;
}

static int script_line_traitment_for_tower(const char *script_line,
    tower_t **data, int *index)
{
    char **splited_line = NULL;
    int verif = 0;

    my_replace_in_str((char *)(script_line), '\t', ' ');
    splited_line = my_split_str((char *)(script_line), ' ');
    if (splited_line == NULL) {
        free_array((void **)(data), 2);
        return EPITECH_ECHEC;
    }
    if (my_strcmp(splited_line[0], "T") == 0) {
        verif = tower_create((const char **)(splited_line), data, *index);
        *index += 1;
    }
    free_array((void **)(splited_line), 2);
    if (verif == EPITECH_ECHEC) {
        free_array((void **)(data), 2);
        return EPITECH_ECHEC;
    }
    return EPITECH_SUCCESS;
}

static tower_t **get_tower_data(const char **script_content)
{
    int size = my_word_array_len(script_content);
    tower_t **data = malloc(sizeof(tower_t *) * (size + 1));
    int index = 0;
    int verif = 0;

    if (data == NULL)
        return NULL;
    for (int i = 0; i < size; ++i) {
        verif = script_line_traitment_for_tower(script_content[i], data,
            &index);
        if (verif != EPITECH_SUCCESS)
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
