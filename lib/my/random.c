/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_hunter
** File description:
** this file countains all functions to render an aleatory int
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"

void set_rand_start_stat(void)
{
    unsigned long t = time(NULL);
    unsigned long seed = (((t * 745437) % 324) * 24765873) / 564643;

    srand(seed);
}

int my_randint(const int min_val, const int max_val)
{
    const int amplitude = ABS(max_val - min_val);
    double random_val = 0;
    int randint_val = 0;

    if (min_val > max_val)
        my_swap((int *)(&min_val), (int *)(&max_val));
    if (min_val == max_val)
        return min_val;
    randint_val = (rand() % amplitude) + min_val;
    return randint_val;
}
