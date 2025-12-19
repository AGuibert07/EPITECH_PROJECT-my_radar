/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 10
*/

#include "my.h"

void my_strcapitalize(char *str)
{
    int size = my_strlen(str);

    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
    for (int i = 0; i < (size - 1); ++i) {
        if (str[i] == ' ' && str[i + 1] >= 'a' && str[i + 1] <= 'z')
            str[i + 1] = str[i + 1] - 32;
        if (str[i] != ' ' && str[i + 1] >= 'A' && str[i + 1] <= 'Z')
            str[i + 1] = str[i + 1] + 32;
    }
}
