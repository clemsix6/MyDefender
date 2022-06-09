/*
** EPITECH PROJECT, 2022
** My Sokoban
** File description:
** load_map
*/

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int map_count_columns(char *buffer)
{
    int i = 0;
    int columns = 0;

    for (; buffer[i] != '\n'; i++) {
        columns += 1;
    }
    return columns;
}

int map_count_lines(char *buffer)
{
    int i = 0;
    int lines = 0;

    for (;buffer[i] != '\0';i++) {
        if (buffer[i] == '\n') {
            lines += 1;
        }
    }
    return lines + 1;
}

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **arr = malloc(sizeof(char *) * nb_rows);

    for (int i = 0; i < nb_rows; i++) {
        arr[i] = malloc(sizeof(char) * nb_cols + 1);
    }
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols + 1; j++) {
            arr[i][j] = '\0';
        }
    }
    return arr;
}

char **map_to_array(char *buffer)
{
    int a = 0;
    int columns = map_count_columns(buffer);
    int lines = map_count_lines(buffer);
    char **array = mem_alloc_2d_array(lines, columns);

    for (int i = 0; i < lines;i++) {
        for (int j = 0; j < columns;j++) {
            if (buffer[a] == '\n') {
                a += 1;
            }
            array[i][j] = buffer[a];
            a += 1;
        }
    }
    free(buffer);
    return array;
}

char *map_buffer(const char *filepath)
{
    struct stat file;
    stat(filepath, &file);
    char *buffer = malloc(sizeof(char) * file.st_size + 1);
    int fd = STDOUT_FILENO;

    fd = open(filepath, O_RDONLY);
    ssize_t n = read(fd, buffer, file.st_size);
    buffer[n] = '\0';
    close(fd);
    return buffer;
}
