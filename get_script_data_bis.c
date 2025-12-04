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


struct aircraft_data *get_aircraft_data_struct(char **script_line)
{
    struct aircraft_data *data = malloc(sizeof(struct aircraft_data));

    if (data == NULL)
        return NULL;
    if (my_word_array_len(script_line) != 7) {
        free(data);
        return NULL;
    }
    (*data).start_pos.x = my_getnbr(script_line[1]);
    (*data).start_pos.y = my_getnbr(script_line[2]);
    (*data).end_pos.x = my_getnbr(script_line[3]);
    (*data).end_pos.y = my_getnbr(script_line[4]);
    (*data).speed = my_getnbr(script_line[5]);
    (*data).delay = my_getnbr(script_line[6]);
    if ((*data).speed == 0) {
        free(data);
        return NULL;
    }
    return data;
}

struct control_tower_data *get_control_tower_data_struct(char **script_line)
{
    struct control_tower_data *data =
        malloc(sizeof(struct control_tower_data));

    if (data == NULL)
        return NULL;
    if (my_word_array_len(script_line) != 4) {
        free(data);
        return NULL;
    }
    (*data).position.x = my_getnbr(script_line[1]);
    (*data).position.y = my_getnbr(script_line[2]);
    (*data).area_radius = my_getnbr(script_line[3]);
    return data;
}

/*int get_aircraft_data(char **script_content, char **script_line,
    struct aircraft_data **aircrafts, int *aircrafts_index) {
    aircrafts[*aircrafts_index] = get_aircraft_data_struct(script_line);
    free_array(script_line, 2);
    if (aircrafts[*aircrafts_index] == NULL) {
        free_array(script_content, 2);
        free_array(aircrafts, 2);
        return EPITECH_ECHEC;
    }
    *aircrafts_index += 1;
    return EPITECH_SUCCESS;
}
*/
static char **check_item(char *line)
{
    char **splited_line;

    my_replace_in_str(line, '\t', ' ');
    splited_line = my_split_str(line, ' ');
    if (splited_line == NULL || !(my_strcmp(splited_line[0], "A") == 0 ||
        my_strcmp(splited_line[0], "T") == 0))
        return NULL;
    return splited_line;
}

static void add_line_to_array(char **line, char ***arr, int *index)
{
    arr[*index] = line;
    *index += 1;
}

static int line_traitment(char **line, char ***aircrafts_lines,
    char ***control_towers_lines, int *index)
{
    char **splited_line = check_item(line);

    if (splited_line == NULL)
        return EPITECH_ECHEC;
    if (my_strcmp(splited_line[0], "A") == 0)
        add_line_to_array(splited_line, aircrafts_lines, &index[0]);
    else {
        add_line_to_array(splited_line, control_towers_lines,
            &index[1]);
    }
    return EPITECH_SUCCESS;
}

unsigned int list_len(char ***arr)
{
    unsigned int l = 0;

    while (arr[l] != NULL) {
        l += 1;
    }
    return l;
}

static void **get_array_content(void **arr, int size, char ***lines,
    void *(*funct)(char ***))
{
    for (int i = 0; i < size; ++i) {
        arr[i] = funct(lines[i]);
        if (arr[i] == NULL) {
            free_array(arr, 2);
            return NULL;
        }
    }
    arr[size] = NULL;
    return arr;
}

void **get_structures_array(char ***aircrafts_lines, char ***control_towers_lines)
{
    int size1 = list_len(aircrafts_lines);
    int size2 = list_len(control_towers_lines);
    struct aircraft_data **crafts_arr = malloc(sizeof(struct aircraft_data) *
        (size1 + 1));
    struct control_tower_data **towers_arr = malloc(sizeof(struct control_tower_data) *
        (size2 + 1));

    if (crafts_arr == NULL || towers_arr == NULL) {
        nfree(2, crafts_arr, towers_arr);
        return NULL;
    }
    crafts_arr = get_array_content(crafts_arr, size1, aircrafts_lines,
        &get_aircraft_data_struct);
    if (crafts_arr == NULL) {
        nfree_array(3, 2, aircrafts_lines, control_towers_lines);
        free(towers_arr);
    }
    towers_arr = get_array_content(towers_arr, size2, control_towers_lines,
        &get_control_tower_data_struct);
    if (towers_arr == NULL) {
        nfree_array(3, 2, aircrafts_lines, control_towers_lines);
        free_array(crafts_arr, 2);
    }
    towers_arr[size2] = NULL;
}

char ***get_empty_arr(unsigned int size)
{
    char ***arr = malloc(sizeof(char **) * (size + 1));

    if (arr == NULL)
        return NULL;
    for (int i = 0; i <= size; ++i) {
        arr[i] = NULL;
    }
    return arr;
}

void **get_script_data(const char *file_name)
{
    char **script_content = get_file_content(file_name);
    int size = 0;
    char ***aircrafts_lines = NULL;
    char ***control_towers_lines = NULL;
    int index[2] = {0, 0};

    if (script_content == NULL)
        return NULL;
    size = my_word_array_len(script_content);
    aircrafts_lines = get_empty_arr(size);
    control_towers_lines = get_empty_arr(size);
    if (aircrafts_lines == NULL || control_towers_lines == NULL)
        return NULL;
    for (int i = 0; i < size; ++i) {
        if (line_traitment(script_content[i], aircrafts_lines,
            control_towers_lines, index) != EPITECH_SUCCESS)
            return NULL;
    }
    free_array(script_content, 2);
    return get_structures_array(aircrafts_lines, control_towers_lines);
}

/*void **get_script_data_old(char *file_name)
{
    char **script_content = get_file_content(file_name);
    int size = 0;
    char **splited_line = NULL;
    struct aircraft_data **aircrafts = NULL;
    struct control_tower_data **control_tower_data = NULL;
    char ***aircrafts_lines = NULL;
    int aircrafts_index = 0;
    int control_towers_index = 0;
    int r_val = EPITECH_ECHEC;
    int line_size = 0;

    if (script_content == NULL)
        return NULL;
    size = my_word_array_len(script_content);
    aircrafts = malloc(sizeof(struct aircraft_data) * (size + 1));
    control_tower_data = malloc(sizeof(struct aircraft_data) * (size + 1));
    if (aircrafts == NULL || control_tower_data == NULL) {
        nfree(2, aircrafts, control_tower_data);
    }
    for (int i = 0; script_content[i] != 0; ++i) {
        my_replace_in_str(script_content[i], '\t', ' ');
        splited_line = my_split_str(script_content[i], ' ');
        line_size = my_word_array_len(splited_line);
        if (my_strcmp(splited_line[0], "A") != 0 &&
            my_strcmp(splited_line[0], "T") != 0) {
            free_array(script_content, 2);
            return NULL;
        }
        if (my_strcmp())
    }
    for (int i = 0; script_content[i] != 0; ++i) {
        r_val = EPITECH_ECHEC;
        my_replace_in_str(script_content[i], '\t', ' ');
        splited_line = my_split_str(script_content[i], ' ');
        if (splited_line == NULL) {
            free_array(script_content, 2);
            return NULL;
        }
        if (my_strcmp(splited_line[0], "A") == 0) {
            get_aircraft_data(script_content, splited_line, aircrafts,
                aircrafts_index);
        }
        if (my_strcmp(splited_line[1], "T") == 0) {
            aircrafts
        }
    }
}
*/
