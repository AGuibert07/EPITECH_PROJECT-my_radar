/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 09
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int size = my_strlen(str);
    char sixty_five = 'A';
    char ninety = 'Z';

    for (int i = 0; i < size; ++i) {
        if (str[i] >= sixty_five && str[i] <= ninety) {
            str[i] = str[i] + 32;
        }
    }
    return str;
}
