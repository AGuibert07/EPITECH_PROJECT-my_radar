/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 13
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int size = my_strlen(str);

    if (size == 0) {
        return 0;
    }
    for (int i = 0; i < size; ++i) {
        if (str[i] < '0' || str[i] > '9') {
            return 1;
        }
    }
    return 0;
}
