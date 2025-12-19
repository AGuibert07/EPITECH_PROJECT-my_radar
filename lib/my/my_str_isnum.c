/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 13
*/

#include "my.h"

bool_t my_str_isnum(char const *str)
{
    int size = my_strlen(str);

    if (size == 0)
        return FALSE;
    for (int i = 0; i < size; ++i) {
        if (!my_is_in_str(str[i], DIGITS))
            return FALSE;
    }
    return TRUE;
}

bool_t my_str_isnbr(char const *str)
{
    int size = my_strlen(str);
    int start_pos = 0;

    if (size == 0)
        return FALSE;
    if (str[0] == '-') {
        start_pos = 1;
        if (size == 1)
            return FALSE;
    }
    for (int i = start_pos; i < size; ++i) {
        if (!my_is_in_str(str[i], DIGITS))
            return FALSE;
    }
    return TRUE;
}
