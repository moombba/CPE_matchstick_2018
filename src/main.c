/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "match.h"

int main(int ac, char **av)
{
    char **map;
    int nb_lines = 0;
    int max = 0;
    int win = 0;

    if (ac != 3)
        return (84);
    nb_lines = my_getnbr(av[1]);
    max = my_getnbr(av[2]);
    if (max > 100 || max < 1)
        return (84);
    map = create_map(nb_lines);
    win = game_master(map, max, nb_lines);
    return (win);
}