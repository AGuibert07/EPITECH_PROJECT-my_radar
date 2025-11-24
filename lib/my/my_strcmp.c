/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 06
*/

#include "my.h"

static int comparison(const char *s1, const char *s2, int *sizes, int i)
{
    int size1 = sizes[0];
    int size2 = sizes[1];
    char c1;
    char c2;

    if (i < size1) {
        c1 = s1[i];
    } else {
        c1 = '\0';
    }
    if (i < size2) {
        c2 = s2[i];
    } else {
        c2 = '\0';
    }
    return (c1 - c2);
}

int my_strcmp(char const *s1, char const *s2)
{
    int size1 = my_strlen(s1);
    int size2 = my_strlen(s2);
    int sizes[2];
    int nb_it;
    int i = 0;

    sizes[0] = size1;
    sizes[1] = size2;
    if (size1 >= size2) {
        nb_it = size1;
    } else {
        nb_it = size2;
    }
    while (i < nb_it) {
        if (comparison(s1, s2, sizes, i) != 0) {
            return comparison(s1, s2, sizes, i);
        }
        i = i + 1;
    }
    return 0;
}
