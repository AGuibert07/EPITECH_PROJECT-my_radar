/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 12
*/

#include "my.h"

static int is_alphabetic(char c)
{
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

int my_str_isalpha(char const *str)
{
    int size = my_strlen(str);

    if (size == 0) {
        return 0;
    }
    for (int i = 0; i < size; ++i) {
        if (!(is_alphabetic(str[i]))) {
            return 0;
        }
    }
    return 1;
}
