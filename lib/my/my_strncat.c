/*
** EPITECH PROJECT, 2025
** c_pool_day07
** File description:
** main file for task 03
*/

#include "my.h"

static int my_strlength2(char const *str)
{
    int length = 0;

    while (str[length] != 0) {
        length += 1;
    }
    return (length);
}

char *my_strncat(char *dest, char const *src, int n)
{
    int size_dest = my_strlength2(dest);
    int size_src = my_strlength2(src);
    int nb_it = n;

    if (n > size_src) {
        nb_it = size_src;
    }
    for (int i = 0; i < nb_it; ++i) {
        dest[size_dest + i] = src[i];
    }
    dest[size_dest + nb_it] = '\0';
    return dest;
}
