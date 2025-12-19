/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 05
*/

#include "my.h"

static int check_correspondence(char *str, char const *to_find, int start_pos)
{
    int pattern_size = my_strlen(to_find);
    int is_find = 1;
    int i = 0;

    while (is_find == 1 && i < pattern_size) {
        if (str[i + start_pos] != to_find[i])
            return 0;
        i = i + 1;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    int chain_size = my_strlen(str);
    int pattern_size = my_strlen(to_find);
    int i = 0;
    char *ptr;

    while (i < (chain_size - pattern_size)) {
        if (check_correspondence(str, to_find, i) == 1) {
            ptr = &(str[i]);
            return ptr;
        }
        i = i + 1;
    }
    ptr = &str[chain_size];
    return ptr;
}
