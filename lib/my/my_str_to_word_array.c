/*
** EPITECH PROJECT, 2025
** c_pool_day08
** File description:
** main file for task 04
*/

#include <stdlib.h>
#include "my.h"

static bool_t is_alphanum_char(char c)
{
    return (my_is_in_str(c, LETTERS) || my_is_in_str(c, DIGITS));
}

static int get_nb_word(char const *str, int size)
{
    int nb_words = 0;
    bool_t is_word = FALSE;

    for (int i = 0; i < size; ++i) {
        if (is_alphanum_char(str[i]) && !is_word) {
            is_word = TRUE;
            nb_words = nb_words + 1;
        }
        if (!is_alphanum_char(str[i]) && is_word)
            is_word = FALSE;
    }
    return nb_words;
}

static int get_word_length(char const *str, int start_pos)
{
    int length = 1;
    int i = start_pos + 1;

    for (int i = (start_pos + 1); i < my_strlen(str) &&
        is_alphabetic_char(str[i]); ++i) {
        length += 1;
    }
    return length;
}

char *cpy_word_content(char const *str, int start_pos, int length)
{
    char *word = malloc(sizeof(char) * (length + 1));

    if (word == NULL)
        return NULL;
    for (int i = 0; i < length; ++i) {
        word[i] = str[i + start_pos];
    }
    word[length] = '\0';
    return word;
}

char **my_str_to_word_array(char const *str)
{
    int nb_words = get_nb_word(str, my_strlen(str));
    char **tab = malloc(sizeof(char *) * (nb_words + 1));
    int int_val[2] = {0, 0};

    if (tab == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_alphabetic_char(str[i])) {
            int_val[1] = get_word_length(str, i);
            tab[int_val[0]] = cpy_word_content(str, i, int_val[1]);
            if (tab[int_val[0]] == NULL) {
                free_array(tab, 2);
                return NULL;
            }
            i += int_val[1] - 1;
            int_val[0] += 1;
        }
    }
    tab[nb_words] = 0;
    return tab;
}
