/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** main file of the project
*/

#include <stdlib.h>
#include "my.h"
#include "script_data.h"

static void string_arr_tab_append(char ***string_tab, int *index, char **value)
{
    string_tab[*index] = value;
    *index += 1;
}

static void free_string_tab_arr(char ***aircrafts,
    const unsigned int index_aircrafts, char ***control_towers,
    const unsigned int index_control_towers)
{
    free(aircrafts[index_aircrafts]);
    free(control_towers[index_control_towers]);
}

static int check_data_element(char ****lists, unsigned int *index, char **element)
{
    if (!(my_strcmp(element[0], "A") == 0 || my_strcmp(element[0], "T") == 0)) {
        free_string_tab_arr(lists[0], 0, lists[1], 0);
        free(lists);
        return EPITECH_ECHEC;
    }
    if (my_strcmp(element[0], "A") == 0)
        string_arr_tab_append(lists[0], &index[0], element);
    else {
        string_arr_tab_append(lists[1], &index[1], element);
    }
    return EPITECH_SUCCESS;
}

char ****filter_script_data(const char **data, const unsigned int size)
{
    char ****lists = malloc(sizeof(char **) * 2);
    unsigned int index[2] = {0, 0};

    if (lists == NULL)
        return NULL;
    lists[0] = malloc(sizeof(char **) * 2);
    lists[1] = malloc(sizeof(char *) * (size + 1));
    if (lists[0] == NULL || lists[1] == NULL) {
        free(lists);
        return NULL;
    }
    for (int i = 0; i < size; ++i) {
        if (check_data_element(lists, index, data[i]) != EPITECH_SUCCESS)
            return NULL;
    }
    lists[0][index[0]] = 0;
    lists[1][index[1]] = 0;
    free_string_tab_arr(lists[0], index[0] + 1, lists[1], index[1] + 1);
    return lists;
}

static char **remove_empty_strings(char **element)
{
    unsigned int size = my_word_array_len(element);
    char **element_new = malloc(sizeof(char *) * (size + 1));
    int index = 0;

    if (element_new == NULL)
        return NULL;
    for (int i = 0; i < size; ++i) {
        if (my_strlen(element[i]) > 0) {
            element_new[index] = element[i];
            index += 1;
        }
    }
    element_new[index] = 0;
    free(element_new[index + 1]);
    return element_new;
}

char ***split_string_tab_lines(char **data, const unsigned int size)
{
    char ***data_splited = malloc(sizeof(char **) * (size + 1));

    if (data_splited == NULL)
        return NULL;
    for (int i = 0; i < size; ++i) {
        data_splited[i] = my_split_str(data[i], " ");
    }
}
