/*
** EPITECH PROJECT, 2025
** c_pool_day10
** File description:
** my_putstr_error function
*/

#include <unistd.h>
#include "my.h"

int my_putstr_error(char const *str)
{
    int i = 0;

    write(STD_ERR, str, my_strlen(str));
    return 0;
}
