/*
** EPITECH PROJECT, 2025
** C_Pool - my_printf project - Alexis & Thomas
** File description:
** this file countains the my_int_to_str_convertion function;
*/

#include <stdlib.h>
#include "my.h"

static int get_nbr_digits(int nbr, int base)
{
    int nbr_digits = -1;

    if (nbr < 0) {
        nbr = -nbr;
    }
    while (my_compute_power_rec(base, nbr_digits + 1) <= nbr) {
        nbr_digits += 1;
    }
    return nbr_digits + 1;
}

static char *concat_nbr_digits(int nbr, const char *base,
    unsigned int nbr_digits)
{
    int power_val = 0;
    char *str_char = NULL;
    char *temp = NULL;
    char *str = NULL;

    if (nbr_digits == 0)
        return my_strdup("");
    power_val = my_compute_power_rec(my_strlen(base), nbr_digits - 1);
    str_char = convert_char_to_str(base[nbr / power_val]);
    temp = concat_nbr_digits(nbr % power_val, base, nbr_digits - 1);
    if (str_char == NULL || temp == NULL) {
        nfree(2, str_char, temp);
        return NULL;
    }
    str = my_str_concat(str_char, temp);
    nfree(2, temp, str_char);
    return str;
}

char *my_int_to_str_function(int nbr, const char *base)
{
    int nbr_digits = get_nbr_digits(nbr, my_strlen(base));
    int sign = 0;
    char *str = NULL;
    char *temp = NULL;

    if (nbr == 0)
        return convert_char_to_str(base[0]);
    sign = SIGN(nbr);
    nbr = ABS(nbr);
    if (nbr_digits <= 1)
        str = convert_char_to_str(base[nbr]);
    str = concat_nbr_digits(nbr, base, nbr_digits);
    if (str == NULL)
        return NULL;
    if (sign < 0) {
        temp = str;
        str = my_str_concat("-", temp);
        free(temp);
    }
    return str;
}

int get_integer_part(double variable)
{
    int i = -1;

    if (variable < 0) {
        return -get_integer_part(-variable);
    }
    while ((i + 1) <= variable) {
        i += 1;
    }
    return i;
}

static int round_decimal_part(int decimal_part)
{
    if (decimal_part % 10 >= 5) {
        decimal_part += 10;
    }
    return decimal_part / 10;
}

char *my_double_to_str_function(double nbr_float, unsigned int nbr_deci)
{
    int integer_part = get_integer_part(nbr_float);
    int deci_part;
    char *integer_str = my_int_to_str_function(integer_part, "0123456789");
    char *deci_str;
    char *str;

    str = my_str_concat(integer_str, ".");
    nbr_float -= integer_part;
    if (nbr_float < 0) {
        nbr_float = -nbr_float;
    }
    nbr_float *= my_compute_power_rec(10, nbr_deci + 1);
    deci_part = round_decimal_part(get_integer_part(nbr_float));
    deci_str = my_int_to_str_function(deci_part, "0123456789");
    for (int i = 0; i < (nbr_deci - my_strlen(deci_str)); ++i) {
        str = my_str_concat(str, "0");
    }
    str = my_str_concat(str, deci_str);
    return str;
}
