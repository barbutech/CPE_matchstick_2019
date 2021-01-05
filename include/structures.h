/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** structures.h
*/

#ifndef position_h
#define position_h

struct position
{
    int winner;
    char **map;
    int line;
    int match;
    int size_line;
    int size_column;
    int count;
};
typedef struct position position_t;

#endif