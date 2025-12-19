/*
** EPITECH PROJECT, 2025
** libmy.a library
** File description:
** this file countains string tools functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

static void init_word_arr(char **arr, int arr_len, int size)
{
    char *element;

    for (int i = 0; i < arr_len; ++i) {
        element = malloc(sizeof(char) * size);
        arr[i] = element;
    }
}

char *my_substring(char *str, int start_pos, unsigned int n)
{
    int size = my_strlen(str);
    int end_pos = start_pos + n;
    char *new_string;

    if (start_pos >= size) {
        my_putstr_error("IndexError : string index out of range\n");
        return NULL;
    }
    if (end_pos > size)
        end_pos = size;
    new_string = malloc(sizeof(char) * (n + 1));
    for (int i = start_pos; i < end_pos; ++i) {
        new_string[i - start_pos] = str[i];
    }
    new_string[end_pos - start_pos] = '\0';
    return new_string;
}

static int set_array(char **arr, char *str, char sep, int size)
{
    int index = 0;
    int start = 0;

    for (int i = 0; i < size; ++i) {
        if (str[i] == sep) {
            arr[index] = my_substring(str, start, (i - start));
            start = i + 1;
            index += 1;
        }
    }
    if (start < size)
        arr[index] = my_substring(str, start, (size - start));
    else
        arr[index] = my_strdup("");
    if (arr[index] == NULL) {
        free_array((void **)(arr), 2);
        return EPITECH_ECHEC;
    }
    arr[index + 1] = 0;
    return EPITECH_SUCCESS;
}

char **my_split_str(char *str, char sep)
{
    const int size = my_strlen(str);
    int nbr_occ = my_nbr_occurences_in_str(sep, str);
    char **arr = malloc(sizeof(char *) * (nbr_occ + 2));
    int verif = 0;

    if (arr == NULL)
        return NULL;
    verif = set_array(arr, str, sep, size);
    if (verif != EPITECH_SUCCESS)
        return NULL;
    return arr;
}

static void check_string_char(char str_i, char *chars, char *str_new,
    int *index)
{
    char c = chars[0];
    char c_new = chars[1];

    if (str_i != c) {
        str_new[*index] = str_i;
        index = index + 1;
    } else if (str_i == c && c_new != '\0') {
        str_new[*index] = c_new;
        index = index + 1;
    }
}

void my_replace_in_str(char *str, char c, char c_new)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == c)
            str[i] = c_new;
    }
}
