/*
** EPITECH PROJECT, 2025
** G1 - Elementary Programming in C - Setting Up
** File description:
** this file countains all int arr tool functions
*/

#include "my.h"

void my_show_int_arr(int *arr, int size)
{
    my_putchar('{');
    for (int i = 0; i < size; ++i) {
        my_put_nbr(arr[i]);
        if ((i + 1) < size)
            my_putstr(", ");
    }
    my_putchar('}');
}

void my_show_two_d_int_arr(int **arr, int nbr_lines, int nbr_columns)
{
    my_putstr("[\n");
    for (int i = 0; i < nbr_lines; ++i) {
        my_putstr("    ");
        my_show_int_arr(arr[i], nbr_columns);
        if ((i + 1) < nbr_lines)
            my_putstr(",\n");
    }
    my_putstr("\n]\n");
}
