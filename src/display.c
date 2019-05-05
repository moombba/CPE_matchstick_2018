/*
** EPITECH PROJECT, 2019
** display
** File description:
** disp map
*/

#include "match.h"

void too_much_matches(int max)
{
    my_printf("Error: you cannot remove more than %d", max);
    my_printf(" matches per turn\n");
}

void disp_map(char **map, int len)
{
    for (int i = 0; map[i]; i++) {
        write(1, map[i], len);
        write(1, "\n", 1);
    }
}

void disp_empty_map(int max, int nb_line)
{
    for (int i = 0; i < max; i++)
        my_printf("*");
    write(1, "\n", 1);
    for (int u = 0; u < nb_line; u++) {
        write(1, "*", 1);
        for (int i = 0; i < max - 2; i++)
            write(1, " ", 1);
        write(1, "*\n", 2);
    }
    for (int i = 0; i < max; i++)
        my_printf("*");
    write(1, "\n", 1);
}