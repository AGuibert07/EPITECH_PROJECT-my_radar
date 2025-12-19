/*
** EPITECH PROJECT, 2025
** c_pool_day08
** File description:
** function my_word_array_len
*/

int my_word_array_len(char const **tab)
{
    int l = 0;

    while (tab[l] != 0)
        l += 1;
    return l;
}
