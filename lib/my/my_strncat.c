/*
** EPITECH PROJECT, 2025
** c_pool_day07
** File description:
** main file for task 03
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int size_dest = my_strlen(dest);
    int size_src = my_strlen(src);
    int nb_it = n;

    if (n > size_src)
        nb_it = size_src;
    for (int i = 0; i < nb_it; ++i) {
        dest[size_dest + i] = src[i];
    }
    dest[size_dest + nb_it] = '\0';
    return dest;
}
