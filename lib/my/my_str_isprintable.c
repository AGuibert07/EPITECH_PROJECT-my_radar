/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 16
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    for (int i = 0; i < my_strlen(str); ++i) {
        if ((str[i] <= 31 || str[i] == 127) == 1) {
            return 0;
        }
    }
    return 1;
}
