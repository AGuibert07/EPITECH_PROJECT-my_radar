/*
** EPITECH PROJECT, 2025
** c_pool_day10
** File description:
** my_putchar_error function
*/

#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}
