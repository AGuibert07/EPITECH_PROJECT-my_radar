/*
** EPITECH PROJECT, 2025
** libmy.a library
** File description:
** this file countains string tools functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

static void init_word_arr(char **arr, int arr_len, int size)
{
    char *element;

    for (int i = 0; i < arr_len; ++i) {
        element = malloc(sizeof(char) * size);
        arr[i] = element;
    }
}

char *my_substring(char *str, int start_pos, unsigned int n)
{
    int size = my_strlen(str);
    int end_pos = start_pos + n;
    char *new_string;

    if (start_pos >= size) {
        my_putstr_error("IndexError : string index out of range\n");
        return "";
    }
    if (end_pos > size) {
        end_pos = size;
    }
    new_string = malloc(sizeof(char) * (n + 1));
    for (int i = start_pos; i < end_pos; ++i) {
        new_string[i - start_pos] = str[i];
    }
    new_string[end_pos - start_pos] = '\0';
    return new_string;
}

char **my_split_str(char *str, char sep)
{
    int size = my_strlen(str);
    int nbr_occ = my_nbr_occurences_in_str(sep, str);
    char **arr = malloc(sizeof(char *) * (nbr_occ + 2));
    int index = 0;
    int start = 0;

    for (int i = 0; i < size; ++i) {
        if (str[i] == sep) {
            arr[index] = my_substring(str, start, (i - start));
            start = i + 1;
            index += 1;
        }
    }
    if (start < size) {
        arr[index] = my_substring(str, start, (size - start));
    } else {
        arr[index] = my_substring(str, 0, 0);
    }
    arr[index + 1] = 0;
    return arr;
}

static void check_string_char(char str_i, char *chars, char *str_new,
    int *index)
{
    char c = chars[0];
    char c_new = chars[1];

    if (str_i != c) {
        str_new[*index] = str_i;
        index = index + 1;
    } else if (str_i == c && c_new != '\0') {
        str_new[*index] = c_new;
        index = index + 1;
    }
}

char *my_replace_in_str(char *str, char c, char c_new)
{
    int size = my_strlen(str);
    int size_new = size;
    char *str_new;
    int index = 0;
    char chars[3] = {c, c_new, '\0'};

    if (c_new == '\0') {
        size_new = size - my_nbr_occurences_in_str(c, str);
    }
    str_new = malloc(sizeof(char) * (size_new + 1));
    for (int i = 0; i < size; ++i) {
        check_string_char(str[i], chars, str_new, &index);
    }
    str_new[index] = '\0';
    return str_new;
}

char *my_str_concat(char *str1, char *str2)
{
    char *str_new;
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    int index = 0;

    str_new = malloc(sizeof(char) * (size1 + size2 + 1));
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
    char *str;

    va_start(list, n);
    str = malloc(sizeof(char));
    str[0] = '\0';
    for (unsigned int i = 0; i < n; ++i) {
        str = my_str_concat(str, va_arg(list, char *));
    }
    va_end(list);
    return str;
}
