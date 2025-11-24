/*
** EPITECH PROJECT, 2025
** c_pool_day03
** File description:
** my_putchar function
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
