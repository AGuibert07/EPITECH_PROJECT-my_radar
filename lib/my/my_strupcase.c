/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 08
*/

#include "my.h"

char *my_strupcase(char *str)
{
    int size = my_strlen(str);
    char ninety_seven = 'a';
    char one_hundred_twenty_two = 'z';

    for (int i = 0; i < size; ++i) {
        if (str[i] >= ninety_seven && str[i] <= one_hundred_twenty_two)
            str[i] -= 32;
    }
    return str;
}
