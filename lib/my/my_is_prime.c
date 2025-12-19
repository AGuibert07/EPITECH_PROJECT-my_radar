/*
** EPITECH PROJECT, 2025
** c_pool_day05
** File description:
** main file for task 06
*/

#include "my.h"

bool_t my_is_prime(int nb)
{
    int i = nb / 2;

    if (nb < 0) {
        return my_is_prime(-nb);
    } else if (nb == 0 || nb == 1) {
        return FALSE;
    }
    while (i > 1) {
        if (nb % i == 0) {
            return FALSE;
        }
        i = i - 1;
    }
    return TRUE;
}
