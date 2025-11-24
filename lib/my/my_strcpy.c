/*
** EPITECH PROJECT, 2025
** c_pool_day6
** File description:
** main file for task 01
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != 0) {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
    return dest;
}
