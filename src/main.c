/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** main.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/structures.h"

void remove_for_me(position_t **pos)
{
    int count = 0;

    for (; (*pos)->map[(*pos)->line - 1][count] != '\0'; count++);
    count--;
    for (; (*pos)->map[(*pos)->line - 1][count] == ' '; count-- );
    for (int tmp = (*pos)->match; tmp > 0; count--, tmp--)
        (*pos)->map[(*pos)->line - 1][count] = ' ';
}

int case_of_player(char **argv, position_t **pos)
{
    char *answer = NULL;
    ssize_t len = 0;
    (*pos)->line = 0;
    (*pos)->match = 0;

    my_putstr("Line: ");
    if (getline(&answer, &len, stdin) == EOF)
        return (-1);
    (*pos)->line = error_line(answer, len, argv);
    if ((*pos)->line == -1)
        return (-1);
    my_putstr("Matches: ");
    if (getline(&answer, &len, stdin) == EOF)
        return (-1);
    (*pos)->match = error_match(answer, len, argv);
    if ((*pos)->match == -1)
        return (-1);
    return (0);
}

void print_map(char **map, int count, int size_line)
{
    int nbr_spaces = size_line / 2 - 1;

    for (int tmp = size_line; tmp > 0 ;tmp--)
        write(1, "*", 1);
    write(1, "\n", 1);
    for (int count = 0; map[count] != NULL; count++) {
        write(1, "*", 1);
        for (int tmp = nbr_spaces; tmp > 0; tmp--)
            write(1, " ", 1);
        my_putstr(map[count]);
        for (int tmp = nbr_spaces; tmp > 0; tmp--)
            write(1, " ", 1);
        write(1, "*\n", 2);
        nbr_spaces--;
    }
    for (int tmp = size_line; tmp > 0 ;tmp--)
        write(1, "*", 1);
    write(1, "\n", 1);
}

char **fill_map(char **argv, position_t **pos)
{
    (*pos)->size_line = 1;
    char **map;
    (*pos)->count = 0;

    (*pos)->size_column = my_getnbr(argv[1]);
    map = malloc(sizeof(char *) * ((*pos)->size_column + 1));
    if (map == NULL)
        return (NULL);
    map[(*pos)->size_column] = NULL;
    for (int tmp = 0; tmp < (*pos)->size_column; tmp++) {
        map[tmp] = malloc(sizeof(char) * ((*pos)->size_line + 1));
        if (map[tmp] == NULL)
            return (NULL);
        for (int count = 0; count < (*pos)->size_line; count++)
            map[tmp][count] = '|';
        map[tmp][(*pos)->size_line] = '\0';
        (*pos)->size_line += 2;
    }
    print_map(map, (*pos)->count, (*pos)->size_line);
    return (map);
}

int main(int argc, char *argv[])
{
    position_t *pos = malloc(sizeof(position_t));
    if (error_init(argc, argv) == 84)
        return (84);
    pos->map = fill_map(argv, &pos);
    if (pos->map == NULL)
        return (84);
    pos->winner = game(pos, argv);
    if (pos->winner == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    if (pos->winner == 2) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    return (pos->winner);
}
