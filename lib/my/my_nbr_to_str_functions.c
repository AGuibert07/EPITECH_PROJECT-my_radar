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
    return nbr_digits;
}

static void set_start_values_with_sign(int *nbr, int *sign, int *index)
{
    if (nbr < 0) {
        *sign = 1;
        *nbr = -(*nbr);
        *index = 1;
    }
}

char *my_int_to_str_function(int nbr, char *base)
{
    int base_val = my_strlen(base);
    int nbr_digits = get_nbr_digits(nbr, base_val);
    char *str;
    int sign = 0;
    int index = 0;
    int power_val;

    set_start_values_with_sign(&nbr, &sign, &index);
    str = malloc(sizeof(char) * (nbr_digits + sign + 1));
    if (sign == 1) {
        str[0] = '-';
    }
    for (int i = nbr_digits; i >= 0; --i) {
        power_val = my_compute_power_rec(base_val, i);
        str[index] = base[nbr / power_val];
        nbr = nbr % power_val;
        index += 1;
    }
    str[index] = '\0';
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
