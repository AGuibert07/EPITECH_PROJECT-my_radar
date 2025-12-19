/*
** EPITECH PROJECT, 2025
** c_pool_day09
** File description:
** this header file countains all libmy function declarations
*/

#ifndef MY_
    #define MY_

    #include <stdio.h>

    #define SIGN(n) ((n < 0) ? (-1) : (1))
    #define ABS(n) ((n < 0) ? (-n) : (n))

    #define DIGITS "0123456789"
    #define BIN_DIGITS "01"
    #define UP_HEXA_DIGITS "0123456789ABCDEF"
    #define LOW_HEXA_DIGITS "0123456789abcdef"
    #define UP_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    #define LOW_LETTERS "abcdefghijklmnopqrstuvwxyz"
    #define LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int get_integer_part(double variable);

    #define FLOAT_EUCLIDIAN_DIV(a, b) (get_integer_part(a / b))
    #define FLOAT_MODULO(a, b) (a - (b * get_integer_part(a / b)))

enum epitech_output {
    EPITECH_SUCCESS = 0,
    EPITECH_ECHEC = 84
} typedef epitech_output_t;

enum std_fd {
    STD_IN = 0,
    STD_OUT = 1,
    STD_ERR = 2
} typedef std_fd_t;

enum bool {
    TRUE = (1 == 1),
    FALSE = (1 != 1)
} typedef bool_t;

    // bool_t operators
    #define AND(b1, b2) ((b1 == TRUE && b2 == TRUE) ? (TRUE) : (FALSE))
    #define OR(b1, b2) ((b1 == TRUE || b2 == TRUE) ? (TRUE) : (FALSE))
    #define NOT(b) ((b == TRUE) ? (FALSE) : (TRUE))

char *convert_char_to_str(char c);
char **fget_file_content(char *filename);
char **fread_file(FILE *file, int buffer_size);
void free_array(void **arr, unsigned int dim_nbr);
char **get_file_content(char *filename);
int get_file_size(char *filename);
char *my_char_n_concat(unsigned int n, ...);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
char *my_double_to_str_function(double nbr_float, unsigned int nbr_deci);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_getnbr_base(char const *str, char const *base);
int my_index_of_str(char c, char *str);
int my_index_of_word_array(char *str, char **arr);
char *my_int_to_str_function(int nbr, const char *base);
int my_isneg(int n);
bool_t my_is_in_str(char c, char *str);
bool_t my_is_prime(int nb);
int my_nbr_occurences_in_str(char c, char *str);
void my_putchar(char c);
void my_putchar_error(char c);
void my_put_float(float nbr, unsigned int nbr_deci);
void my_put_nbr(long long int nb);
void my_put_nbr_error(int nb);
void my_putnbr_base(int nbr, char const *base);
void my_putstr(char const *str);
void my_putstr_error(char const *str);
int my_randint(const int min_val, const int max_val);
void my_replace_in_str(char *str, char c, char c_new);
char *my_revstr(char *str);
void my_show_int_arr(int *arr, int size);
int my_showmem(char const *str, int size);
void my_show_two_d_int_arr(int **arr, int nbr_lines, int nbr_columns);
void my_show_word_array(char const **tab);
void my_show_word_array_error(char const **tab);
int my_showstr(char const *str);
void my_sort_int_in_array(int *array, int size);
char **my_split_str(char *str, char sep);
void my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_str_concat(char *str1, char *str2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *str);
bool_t my_str_isalpha(char const *str);
bool_t my_str_islower(char const *str);
bool_t my_str_isnbr(char const *str);
bool_t my_str_isnum(char const *str);
bool_t my_str_isprintable(char const *str);
bool_t my_str_isupper(char const *str);
char *my_str_join(const char *separator, const char **arr);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_str_n_concat(unsigned int n, ...);
char *my_strncpy(char *dest, char const *src, int n);
char **my_str_to_word_array(char const *str);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
char *my_substring(char *str, int start_pos, unsigned int n);
void my_swap(int *a, int *b);
int my_word_array_len(char const **tab);
void nfree(unsigned int n, ...);
void nfree_array(unsigned int dim_nbr, unsigned int n, ...);
char **read_file(int fd, int buffer_size);
void set_rand_start_stat(void);

#endif /* MY_ */
