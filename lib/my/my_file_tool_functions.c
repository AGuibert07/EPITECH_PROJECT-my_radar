/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains all functions to get the content of a file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

static char **remove_blank_ending_lines(char **arr)
{
    if (arr == NULL)
        return NULL;
    for (int i = (my_word_array_len((const char **)(arr)) - 1);
        my_strlen(arr[i]) == 0; --i) {
        free(arr[i]);
        arr[i] = 0;
    }
    return arr;
}

static char *create_empty_buffer(int size)
{
    char *buffer = malloc(sizeof(char) * (size + 1));

    if (buffer == NULL)
        return NULL;
    for (int i = 0; i <= size; ++i) {
        buffer[i] = '\0';
    }
    return buffer;
}

char **read_file(int fd, int buffer_size)
{
    int size = buffer_size;
    int index = 0;
    char *buffer = NULL;
    char **arr = NULL;

    if (buffer_size <= 0)
        return NULL;
    buffer = create_empty_buffer(size);
    if (buffer == NULL)
        return NULL;
    size = read(fd, buffer, buffer_size);
    if (size < 0)
        return NULL;
    arr = my_split_str(buffer, '\n');
    if (arr == NULL)
        return NULL;
    free(buffer);
    return remove_blank_ending_lines(arr);
}

char **fread_file(FILE *file, int buffer_size)
{
    int size = buffer_size;
    int index = 0;
    char *buffer = NULL;
    char **arr = NULL;

    if (buffer_size <= 0)
        return NULL;
    buffer = create_empty_buffer(size);
    if (buffer == NULL)
        return NULL;
    size = fread(buffer, buffer_size, buffer_size, file);
    if (size < 0)
        return NULL;
    arr = my_split_str(buffer, '\n');
    if (arr == NULL)
        return NULL;
    free(buffer);
    return remove_blank_ending_lines(arr);
}

int get_file_size(char *filename)
{
    struct stat *sb = malloc(sizeof(struct stat));
    int file_size = 0;

    if (sb == NULL)
        return -1;
    file_size = stat(filename, sb);
    if (file_size < 0)
        return -1;
    file_size = (*sb).st_size;
    free(sb);
    return file_size;
}

char **get_file_content(char *filename)
{
    int file_size = get_file_size(filename);
    int fd = open(filename, O_RDONLY);
    char **content = NULL;

    if (fd < 0)
        return NULL;
    else if (file_size <= 0) {
        close(fd);
        return NULL;
    }
    content = read_file(fd, file_size);
    close(fd);
    return content;
}

char **fget_file_content(char *filename)
{
    int file_size = get_file_size(filename);
    FILE *file = fopen(filename, "r");
    char **content = NULL;

    if (file == NULL)
        return NULL;
    else if (file_size <= 0) {
        fclose(file);
        return NULL;
    }
    content = fread_file(file, file_size);
    fclose(file);
    return content;
}
