/*
** EPITECH PROJECT, 2025
** c_pool_day08
** File description:
** main file for task 01
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *str)
{
    int size = my_strlen(str);
    char *new_str = malloc(sizeof(char) * (size + 1));

    if (new_str == NULL)
        return NULL;
    for (int i = 0; i < size; ++i) {
        new_str[i] = str[i];
    }
    new_str[size] = '\0';
    return new_str;
}
