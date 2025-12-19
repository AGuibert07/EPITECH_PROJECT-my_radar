/*
** EPITECH PROJECT, 2025
** c_pool_day06
** File description:
** main file for task 18
*/

#include "my.h"

void my_putnbr_base(int nbr, char const *base)
{
    int base_val = my_strlen(base);
    int abs_val = ABS(nbr);
    int n = -1;
    int pow_val = 0;

    if (nbr < 0)
        my_putchar('-');
    while (my_compute_power_rec(base_val, n + 1) <= abs_val) {
        n += 1;
    }
    while (n >= 0) {
        pow_val = my_compute_power_rec(base_val, n);
        my_putchar(base[abs_val / pow_val]);
        abs_val = abs_val % pow_val;
        n -= 1;
    }
}
