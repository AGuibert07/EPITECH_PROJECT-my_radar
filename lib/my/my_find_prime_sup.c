/*
** EPITECH PROJECT, 2025
** c_pool_day05
** File description:
** main file for task 07
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int r = nb;

    while (!my_is_prime(r)) {
        r += 1;
    }
    return r;
}
