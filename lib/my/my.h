/*
** EPITECH PROJECT, 2025
** c_pool_day09
** File description:
** this header file countains all libmy function declarations
*/

#define EPITECH_SUCCESS 0
#define EPITECH_ECHEC 84
#define SIGN(n) ((n < 0) ? (-1) : (1))
#define ABS(n) ((n < 0) ? (-n) : (n))
#define DIGITS "0123456789"
#define BIN_DIGITS "01"
#define UP_HEXA_DIGITS "0123456789ABCDEF"
#define LOW_HEXA_DIGITS "0123456789abcdef"
#define UP_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOW_LETTERS "abcdefghijklmnopqrstuvwxyz"
#define LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

char *convert_char_to_str(char c);
void my_putchar(char c);
int my_isneg(int n);
int my_put_nbr(long long int n);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(const char *str);
int my_getnbr(char const *str);
void my_sort_int_in_array(int *array, int size);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_chowmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int n);
void my_show_word_array(char const **tab);
void my_show_word_array_error(char const **tab);
char *my_strdup(char const *str);
char **my_str_to_word_array(char const *str);
int my_word_array_len(char const **tab);
void my_putchar_error(char c);
int my_put_nbr_error(int n);
int my_putstr_error(char const *str);
int my_is_in_str(char c, char *str);
int my_index_of_str(char c, char *str);
int my_index_of_word_array(char *str, char **arr);
int my_nbr_occurences_in_str(char c, char *str);
void my_put_float(float nbr, unsigned int nbr_deci);
char **my_split_str(char *str, char sep);
char *my_substring(char *str, int start_pos, unsigned int n);
char *my_replace_in_str(char *str, char c, char c_new);
char *my_str_concat(char *str1, char *str2);
char *my_str_n_concat(unsigned int n, ...);
char *my_char_n_concat(unsigned int n, ...);
char **my_word_array_concat(char **arr1, char **arr2);
char *my_int_to_str_function(int nbr, char *base);
int get_integer_part(double variable);
char *my_double_to_str_function(double nbr_float, unsigned int nbr_deci);
void my_show_int_arr(int *arr, int size);
void my_show_two_d_int_arr(int **arr, int nbr_lines, int nbr_columns);
char **read_file(int fd, int buffer_size);
int get_file_size(char *filename);
char **get_file_content(char *filename);
void set_rand_start_stat(void);
int my_randint(const int min_val, const int max_val);
