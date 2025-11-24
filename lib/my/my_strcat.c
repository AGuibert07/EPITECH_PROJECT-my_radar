/*
** EPITECH PROJECT, 2025
** c_pool_day07
** File description:
** main file for task 02
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int size_dest = my_strlen(dest);
    int size_src = my_strlen(src);

    for (int i = 0; i < size_src; ++i) {
        dest[size_dest + i] = src[i];
    }
    dest[size_dest + size_src] = '\0';
    return dest;
}
