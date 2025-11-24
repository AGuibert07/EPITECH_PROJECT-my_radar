/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 14
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int size = my_strlen(str);

    if (size == 0) {
        return 0;
    }
    for (int i = 0; i < size; ++i) {
        if (!(str[i] >= 'a' && str[i] <= 'z')) {
            return 0;
        }
    }
    return 1;
}
