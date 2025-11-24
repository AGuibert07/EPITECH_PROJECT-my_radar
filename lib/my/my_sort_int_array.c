/*
** EPITECH PROJECT, 2025
** c_pool_day4
** File description:
** main file for task 6
*/

static void element_traitment(int *array, int size, int i)
{
    int index_min = i;
    int val_min = array[index_min];
    int temp;

    for (int j = i + 1; j < size; ++j) {
        if (array[j] < val_min) {
            index_min = j;
            val_min = array[j];
        }
    }
    if (index_min > i) {
        temp = array[i];
        array[i] = val_min;
        array[index_min] = temp;
    }
}

void my_sort_int_in_array(int *array, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        element_traitment(array, size, i);
    }
}
