/*
** EPITECH PROJECT, 2025
** c_pool_day04
** File description:
** main file for task 02
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    write(STD_OUT, str, my_strlen(str));
    return 0;
}
