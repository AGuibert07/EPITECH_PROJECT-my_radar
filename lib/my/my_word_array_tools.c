/*
** EPITECH PROJECT, 2025
** C_Pool - my_printf project
** File description:
** this file countains word array tool functions
*/

#include <stdlib.h>
#include "my.h"

int my_index_of_word_array(char *str, char **arr)
{
    int size = my_word_array_len((const char **)(arr));
    int i = 0;

    while (my_strcmp(str, arr[i]) != 0 && i < size) {
        i += 1;
    }
    if (i == size) {
        return -1;
    } else {
        return i;
    }
}

char **my_word_array_concat(char **arr1, char **arr2)
{
    int size1 = my_word_array_len((const char **)(arr1));
    int size2 = my_word_array_len((const char **)(arr2));
    char **arr;
    int index = 0;

    arr = malloc(sizeof(char *) * (size1 + size2 + 1));
    for (int i = 0; i < size1; ++i) {
        arr[index] = my_strdup(arr1[i]);
        index += 1;
    }
    for (int i = 0; i < size2; ++i) {
        arr[index] = my_strdup(arr2[i]);
        index += 1;
    }
    arr[index] = 0;
    return arr;
}

int my_is_in_word_array(char *str, char **arr)
{
    for (int i = 0; i < my_word_array_len((const char **)(arr)); ++i) {
        if (my_strcmp(str, arr[i]) == 0)
            return 1;
    }
    return -1;
}
