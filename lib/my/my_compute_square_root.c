/*
** EPITECH PROJECT, 2025
** c_pool_day05
** File description:
** main file for task 05
*/

int my_compute_square_root(int nb)
{
    int whole_square = 0;

    if (nb <= 0) {
        return (0);
    } else {
        while (whole_square * whole_square < nb) {
            whole_square = whole_square + 1;
        }
        if (whole_square * whole_square == nb) {
            return whole_square;
        } else {
            return (0);
        }
    }
}
