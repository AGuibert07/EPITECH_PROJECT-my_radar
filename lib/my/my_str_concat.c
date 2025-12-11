/*
** EPITECH PROJECT, 2025
** libmy.a library
** File description:
** this file countains string concatanation functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

char *my_str_concat(char *str1, char *str2)
{
    char *str_new;
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    int index = 0;

    str_new = malloc(sizeof(char) * (size1 + size2 + 1));
    if (str_new == NULL)
        return NULL;
    for (int i = 0; i < size1; ++i) {
        str_new[index] = str1[i];
        index += 1;
    }
    for (int i = 0; i < size2; ++i) {
        str_new[index] = str2[i];
        index += 1;
    }
    str_new[index] = '\0';
    return str_new;
}

char *my_str_n_concat(unsigned int n, ...)
{
    va_list list;
    char *str = NULL;
    char *temp = NULL;

    va_start(list, n);
    str = my_strdup("");
    if (str == NULL)
        return NULL;
    for (unsigned int i = 0; i < n; ++i) {
        temp = my_str_concat(str, va_arg(list, char *));
        free(str);
        if (temp == NULL)
            return NULL;
        str = temp;
    }
    va_end(list);
    return str;
}

static char *append_separator(char *str, const char *separator, const int n,
    const int i)
{
    char *new_str = NULL;

    if (i + 1 < n) {
        new_str = my_str_concat(str, (char *)(separator));
        free(str);
        if (new_str == NULL)
            return NULL;
        return new_str;
    }
    return str;
}

char *my_str_join(const char *separator, const char **arr)
{
    int n = my_word_array_len(arr);
    char *new_str = my_strdup("");
    char *temp = NULL;

    my_show_word_array(arr);
    if (new_str == NULL)
        return NULL;
    for (int i = 0; i < n; ++i) {
        temp = my_str_concat(new_str, (char *)(arr[i]));
        free(new_str);
        if (temp == NULL)
            return NULL;
        new_str = temp;
        new_str = append_separator(new_str, separator, n, i);
    }
    return new_str;
}
