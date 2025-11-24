/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 02
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len_src = my_strlen(src);

    while (i < n && len_src > i) {
        dest[i] = src[i];
        i = i + 1;
    }
    if (len_src < n) {
        dest[len_src] = '\0';
    }
    return dest;
}
