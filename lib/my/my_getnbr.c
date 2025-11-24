/*
** EPITECH PROJECT, 2025
** c_pool_day04
** File description:
** main file for task 05
*/

#include <stdio.h>
#include "my.h"

static int is_int_over(char const *str, int length)
{
    char *max_int = "32767";
    int max_int_nb_digits = 5;

    if (length > max_int_nb_digits)
        return 0;
    for (int i = 0; i < length; ++i) {
        if (length == max_int_nb_digits && str[i] > max_int[i])
            return 0;
    }
    return 1;
}

static int get_nbr_abs_val(char *str, int length)
{
    int nbr = 0;
    int index = 0;

    for (int i = (length - 1); i >= 0; i--) {
        nbr += (my_compute_power_rec(10, i) * (str[index] - 48));
        index += 1;
    }
    return nbr;
}

static char *get_nbr_part(char *str, int start_pos, int *length)
{
    int size = 0;

    for (int i = 0; (i < *length && my_is_in_str(str[i], "0123456789") == 1);
        ++i) {
        size += 1;
    }
    *length = size;
    return my_substring(str, start_pos, size);
}

int my_getnbr(char const *str)
{
    int length = my_strlen(str);
    int sign = 1;
    int i = -1;
    char *nbr_part = NULL;

    while (!(48 <= str[i + 1] && 58 > str[i + 1])) {
        i = i + 1;
    }
    if (str[i] == '-') {
        sign = -1;
    }
    i = i + 1;
    length = length - i;
    nbr_part = get_nbr_part(str, i, &length);
    if (length >= 5) {
        if (is_int_over(nbr_part, length) == 0) {
            return 0;
        }
    }
    return (get_nbr_abs_val(nbr_part, length) * sign);
}
