/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 15
*/

#include "my.h"

bool_t my_str_isupper(char const *str)
{
    int size = my_strlen(str);

    if (size == 0)
        return FALSE;
    for (int i = 0; i < size; ++i) {
        if (!my_is_in_str(str[i], UP_LETTERS))
            return FALSE;
    }
    return TRUE;
}
