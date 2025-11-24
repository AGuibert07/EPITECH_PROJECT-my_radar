/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** this file countains the my_put_float function
*/

#include "my.h"

static int get_float_part(float nbr, unsigned int nbr_deci)
{
    float temp;
    int float_part;

    if (nbr < 0) {
        nbr = -nbr;
    }
    temp = nbr * my_compute_power_rec(10, nbr_deci);
    float_part = get_integer_part(temp);
    if (get_integer_part(temp * 10) % 10 >= 5) {
        float_part = float_part + 1;
    }
    return float_part;
}

void my_put_float(float nbr, unsigned int nbr_deci)
{
    int int_part = get_integer_part(nbr);
    float temp;
    int float_part = get_float_part(nbr - int_part, nbr_deci);
    int i = 0;

    if (float_part == 0) {
        i = 1;
    } else {
        while (my_compute_power_rec(10, i) <= float_part) {
            i += 1;
        }
    }
    my_put_nbr(int_part);
    my_putchar('.');
    for (int j = 0; j < (nbr_deci - i); ++j) {
        my_putchar('0');
    }
    my_put_nbr(float_part);
}
