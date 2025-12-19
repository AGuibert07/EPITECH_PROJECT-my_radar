/*
** EPITECH PROJECT, 2025
** c_pool_day08
** File description:
** main file for task 03
*/

#include "my.h"

void my_show_word_array(char const **tab)
{
    for (int i = 0; tab[i] != 0; ++i) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}

void my_show_word_array_error(char const **tab)
{
    for (int i = 0; tab[i] != 0; ++i) {
        my_putstr_error(tab[i]);
        my_putchar_error('\n');
    }
}
