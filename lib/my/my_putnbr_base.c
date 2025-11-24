/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 18
*/

#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int base_val = my_strlen(base);
    int abs_val = nbr;
    int n;
    int pow_val;

    if (nbr < 0) {
        abs_val = -nbr;
        my_putchar('-');
    }
    n = -1;
    while (my_compute_power_rec(base_val, n + 1) <= abs_val) {
        n = n + 1;
    }
    while (n >= 0) {
        pow_val = my_compute_power_rec(base_val, n);
        my_putchar(base[abs_val / pow_val]);
        abs_val = abs_val % pow_val;
        n = n - 1;
    }
    return base_val;
}
