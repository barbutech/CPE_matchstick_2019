/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** errors.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/structures.h"

int is_there_a_winner(position_t **pos)
{
    for (int line = 0; (*pos)->map[line] != NULL; line++)
        for (int column = 0; (*pos)->map[line][column] != '\0';column++)
            if ((*pos)->map[line][column] == '|')
                return (0);
    return (1);
}

int check_if_it_is_possible(position_t *pos)
{
    int count = 0;
    int number = 0;

    for (; pos->map[pos->line - 1][count] != '\0'; count++)
        if (pos->map[pos->line - 1][count] == '|')
            number++;
    if (number >= pos->match)
        return (1);
    else
        return (0);
}

int error_line(char *answer, ssize_t len, char **argv)
{
    int line = my_getnbr(answer);

    for (int verify = my_getnbr(argv[1]); verify < line || line <= 0;) {
        if (line == -1) {
            my_putstr("Error: invalid input ");
            my_putstr("(positive number expected)\nLine: ");
        }
        else
            my_putstr("Error: this line is out of range\nLine: ");
        if (getline(&answer, &len, stdin) == EOF) {
            write(1, "\n", 1);
            return (-1);
        }
        line = my_getnbr(answer);
    }
    return (line);
}

int error_match(char *answer, ssize_t len, char **argv)
{
    int match = my_getnbr(answer);

    if (answer == NULL)
        return (-1);
    for (int verify = my_getnbr(argv[2]); verify < match || match <= 0;) {
        if (verify < match) {
            my_printf("Error: you cannot remove more than %d", verify);
            my_putstr(" matches per turn\nMatches: ");
        }
        else if (match <= 0) {
            my_putstr("Error: invalid input ");
            my_putstr("(positive number expected)\nMatches: ");
        }
        if (getline(&answer, &len, stdin) == EOF) {
            write(1, "\n", 1);
            return (-1);
        }
        match = my_getnbr(answer);
    }
    return (match);
}

int error_init(int argc, char **argv)
{
    int limit;

    if (argc != 3)
        return (84);
    limit = my_getnbr(argv[1]);
    if (limit >= 100 || limit <= 1)
        return (84);
    if (argv[1][0] == '-' || argv[2][0] == '-') {
        write(2, "this is not available, enter a positive number please\n", 54);
        return (84);
    }
    if (my_getnbr(argv[2]) == 0)
        return (84);
    for (int nbr = 1; nbr < 3; nbr++)
        for (int count = 0; argv[nbr][count] != '\0'; count++)
            if (argv[nbr][count] < '0' || argv[nbr][count] > '9')
                return (84);
}