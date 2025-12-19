/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 09
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (my_is_in_str(str[i], UP_LETTERS))
            str[i] = str[i] + 32;
    }
    return str;
}
