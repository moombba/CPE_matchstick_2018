/*
** EPITECH PROJECT, 2019
** ai
** File description:
** computer playing
*/

#include "match.h"

int rand_line(char **map, int nb_lines, int m_len)
{
    int line = 0;
    int check = -1;

    my_printf("len = %d\n", m_len);
    while (check == -1) {
        srandom(time(NULL));
        line = random();
        my_printf("rand = %d", line);
        if (line > nb_lines || line < 1)
            check = -1;
        if (line <= nb_lines && count_nchar(map[line], '|', m_len) == 0)
            check = -1;
    }
    return (line);
}

int rand_matches(int max, int line, char **map, int m_len)
{
    int matches = -1;

    while (matches == -1) {
        srandom(time(NULL));
        matches = random();
        if (matches > max || matches < 1)
            matches = -1;
        if (matches == 0)
            matches = -1;
        if (count_nchar(map[line], '|', m_len) < matches)
            matches = -1;
    }
    return (matches);
}

int ai_trn(char **map, int max, int nb_lines, int len)
{
    int line = 1;
    int matches = 0;

    for (; count_nchar(map[line], '|', len) == 0; line++);
    matches = count_nchar(map[line], '|', len);
    for (; matches > max; matches--);
    my_printf("AI's turn...\n");
    my_printf("AI removed %d match(es) from line %d\n", matches, line);
    remove_stk(map, line, 1);
    return (0);
}