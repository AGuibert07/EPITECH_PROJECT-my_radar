/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 03
*/

#include "my.h"

char *my_revstr(char *str)
{
    int length = my_strlen(str);
    char temp = '\0';

    for (int i = 0; i < (length / 2); ++i) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return str;
}
