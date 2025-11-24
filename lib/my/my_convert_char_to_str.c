/*
** EPITECH PROJECT, 2025
** C_Pool - my_printf project
** File description:
** this file countains the my_convert_char_to_str function and the
** my_char_concat function
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char *convert_char_to_str(char c)
{
    char *str;

    str = malloc(sizeof(char) * 2);
    str[0] = c;
    str[1] = '\0';
    return str;
}

char *my_char_n_concat(unsigned int n, ...)
{
    va_list list;
    char *str;

    va_start(list, n);
    str = malloc(sizeof(char) * (n + 1));
    for (unsigned int i = 0; i < n; ++i) {
        str[i] = va_arg(list, int);
    }
    str[n] = '\0';
    return str;
}
