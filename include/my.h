/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** my.h
*/

#include "structures.h"

int error_init(int , char **);
int my_getnbr(char *);
int my_putstr(char *);
int my_put_nbr(int);
int my_printf(char *, ...);
void ai(position_t **, char **);
int game(position_t *, char **);
int case_of_player(char **, position_t **);
void print_map(char **, int, int);
void remove_for_me(position_t **);
int is_there_a_winner(position_t **);
int check_if_it_is_possible(position_t *);
int error_line(char *, ssize_t, char **);
int error_match(char *, ssize_t, char **);