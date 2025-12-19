/*
** EPITECH PROJECT, 2025
** c_pool_day5
** File description:
** main file for task 4
*/

#include "my.h"

/*float my_compute_power_signed_rec(float nb, int p)
{
    float r = 1.0;

    if (p < 0) {
        return (1 / my_compute_power_signed_rec(nb, -p));
    } else if (p == 0) {
        return 1.0;
    } else {
        return nb * my_compute_power_signed_rec(nb, p - 1);
    }
}
*/

static int compute_power(int nb, int p)
{
    int r = 1;

    r = my_compute_power_rec(nb, p - 1);
    if (ABS(r) >= 2147483647 / ABS(nb)) {
        return (0);
    } else {
        return r * nb;
    }
}

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return 1;
    } else if (p < 0 || nb == 0) {
        return 0;
    } else {
        return compute_power(nb, p);
    }
}
