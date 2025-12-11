/*
** EPITECH PROJECT, 2025
** c_pool_day04
** File description:
** main file for the task 03
*/

#include <stdio.h>

int my_strlen(char const *str)
{
    int length = 0;

    if (str == NULL)
        return -1;
    while (str[length] != 0) {
        length += 1;
    }
    return (length);
}
