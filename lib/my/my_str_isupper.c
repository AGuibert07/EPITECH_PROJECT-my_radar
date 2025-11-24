/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 15
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    int size = my_strlen(str);

    if (size == 0) {
        return 0;
    }
    for (int i = 0; i < size; ++i) {
        if (!(str[i] >= 'A' && str[i] <= 'Z')) {
            return 0;
        }
    }
    return 1;
}
