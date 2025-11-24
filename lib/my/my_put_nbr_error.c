/*
** EPITECH PROJECT, 2025
** c_pool_day10
** File description:
** my_put_nbr_error function
*/

#include "my.h"

int my_put_nbr_error(int nb)
{
    int abs_val = nb;
    int nb_digits = 0;
    int ten_pow = 1;

    if (nb < 0) {
        my_putchar_error('-');
        abs_val = -nb;
    }
    while (my_compute_power_rec(10, (nb_digits + 1)) <= abs_val) {
        nb_digits = nb_digits + 1;
    }
    while (nb_digits >= 0) {
        ten_pow = my_compute_power_rec(10, nb_digits);
        my_putchar_error(48 + (abs_val / ten_pow));
        abs_val = (abs_val % ten_pow);
        nb_digits = nb_digits - 1;
    }
    return (0);
}
