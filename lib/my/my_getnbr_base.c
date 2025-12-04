/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 19
*/

#include "my.h"

static int my_str_index_of(const char c, const char *str, const int size)
{
    for (int i = 0; i < size; ++i) {
        if (str[i] == c) {
            return i;
        }
    }
    return (-1);
}

int my_getnbr_base(char const *str, char const *base)
{
    int nbr = 0;
    int base_val = my_strlen(base);
    int str_size = my_strlen(str);
    int j = 0;
    int sign = 1;

    if (str[0] == '-') {
        j = 1;
        sign = -1;
        str_size = str_size - 1;
    }
    for (int i = 0; i < str_size; ++i) {
        nbr = nbr + (my_str_index_of(str[i + j], base, base_val) *
            my_compute_power_rec(base_val, str_size - i - 1));
    }
    return nbr * sign;
}
