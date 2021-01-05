/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** ai.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/structures.h"
#include "../include/my.h"
#include <unistd.h>

int case_nbr(position_t *pos, char **argv, int nbr)
{
    int limit = my_getnbr(argv[2]);
    int tempo = 0;

    if (nbr > limit)
        for (; nbr > limit; nbr--);
    else {
        for (; nbr - tempo > 1; tempo++);
        if (nbr != 1)
            nbr = tempo;
    }
    pos->match = nbr;
    my_printf("AI's turn...\nAI removed %d", pos->match);
    my_printf(" match(es) from line %d\n", pos->line);
    return (pos->match);
}

void ai(position_t **pos, char **argv)
{
    int tmp = 0;
    int nbr = 0;

    for (; nbr < 1 && (*pos)->map[tmp] != NULL; tmp++) {
        for (int count = 0; (*pos)->map[tmp][count] != '\0'; count++)
            if ((*pos)->map[tmp][count] == '|')
                nbr++;
        if (nbr <= 1)
        nbr = 0;
    }
    if ((*pos)->map[tmp] == NULL && nbr < 1) {
        tmp = 0;
        for (; nbr <= 0 && (*pos)->map[tmp] != NULL; tmp++) {
        for (int count = 0; (*pos)->map[tmp][count] != '\0'; count++)
            if ((*pos)->map[tmp][count] == '|')
                nbr = 1;
        }
    }
    (*pos)->line = tmp;
    (*pos)->match = case_nbr((*pos), argv, nbr);
}

position_t *after_player(position_t *pos)
{
    my_printf("Player removed %d ", pos->match);
    my_printf("match(es) from line %d\n", pos->line);
    remove_for_me(&pos);
    print_map(pos->map, pos->count, pos->size_line);
    return (pos);
}

int game(position_t *pos, char **argv)
{
    for (; is_there_a_winner(&pos) == 0;) {
        write(1, "\n", 1);
        my_putstr("Your turn:\n");
        if (case_of_player(argv, &pos) == -1)
            return (0);
        for (;check_if_it_is_possible(pos) == 0;) {
            my_putstr("Error: not enough matches on this line\n");
            if (case_of_player(argv, &pos) == -1)
                return (0);
        }
        pos = after_player(pos);
        if (is_there_a_winner(&pos) == 1)
            return (2);
        write(1, "\n", 1);
        ai(&pos, argv);
        remove_for_me(&pos);
        print_map(pos->map, pos->count, pos->size_line);
    }
    return (1);
}