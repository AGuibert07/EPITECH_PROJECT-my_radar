/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 12
*/

#include "my.h"

bool_t my_str_isalpha(char const *str)
{
    int size = my_strlen(str);

    if (size == 0)
        return FALSE;
    for (int i = 0; i < size; ++i) {
        if (!(my_is_in_str(str[i], LETTERS)))
            return FALSE;
    }
    return TRUE;
}
