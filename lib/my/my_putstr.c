/*
** EPITECH PROJECT, 2025
** c_pool_day04
** File description:
** main file for task 02
*/

#include <unistd.h>
#include "my.h"

void my_putstr(char const *str)
{
    write(STD_OUT, str, my_strlen(str));
}
