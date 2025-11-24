/*
** EPITECH PROJECT, 2025
** c_pool_day08
** File description:
** main file for task 04
*/

#include <stdlib.h>
#include "my.h"

static int is_alphabetic_char(char c)
{
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

static int get_nb_word(char const *str, int size)
{
    int nb_words = 0;
    int is_word = 0;

    for (int i = 0; i < size; ++i) {
        if (is_alphabetic_char(str[i]) == 1 && is_word == 0) {
            is_word = 1;
            nb_words = nb_words + 1;
        }
        if (is_alphabetic_char(str[i]) == 0 && is_word == 1) {
            is_word = 0;
        }
    }
    return nb_words;
}

static int get_word_length(char const *str, int size_str, int start_pos)
{
    int length = 1;
    int i = start_pos + 1;

    while (i < size_str && is_alphabetic_char(str[i]) == 1) {
        length = length + 1;
        i = i + 1;
    }
    return length;
}

char *cpy_word_content(char const *str, int start_pos, int length)
{
    char *word;

    word = malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; ++i) {
        word[i] = str[i + start_pos];
    }
    word[length] = '\0';
    return word;
}

char **my_str_to_word_array(char const *str)
{
    int size_str = my_strlen(str);
    int nb_words = get_nb_word(str, size_str);
    char **tab;
    int index = 0;
    int length;

    tab = malloc(sizeof(char *) * (nb_words + 1));
    for (int i = 0; i < size_str; ++i) {
        if (is_alphabetic_char(str[i]) == 1) {
            length = get_word_length(str, size_str, i);
            tab[index] = cpy_word_content(str, i, length);
            i = i + length - 1;
            index = index + 1;
        }
    }
    tab[nb_words] = 0;
    return tab;
}
