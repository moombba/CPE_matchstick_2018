/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** create_map
*/

#include "match.h"

int calc_len(int nb_lines)
{
    int len = 1;

    for (int i = 1; i != nb_lines; i++, len += 2);
    return (len + 2);
}

void fill_line(char *str, int stick, int len, int spaces)
{
    int run = 1;

    str[0] = '*';
    for (int i = 0; i < spaces; i++, run++)
        str[run] = ' ';
    for (int i = 0; i < stick; i++, run++)
        str[run] = '|';
    for (int i = 0; i < spaces; i++, run++)
        str[run] = ' ';
    str[len - 1] = '*';
}

void fill_map(char **map, int nb_lines)
{
    int len = calc_len(nb_lines);
    int stick = 1;
    int spaces = (len - 2) / 2;

    map[0] = malloc(len);
    for (int i = 0; i < len; i++)
        map[0][i] = '*';
    for (int count = 1; count < nb_lines + 1; count++, stick += 2) {
        map[count] = malloc(len);
        fill_line(map[count], stick, len, spaces);
        spaces -= 1;
    }
    map[nb_lines + 1] = malloc(len);
    for (int i = 0; i < len; i++)
        map[nb_lines + 1][i] = '*';
}

char **create_map(int nb_lines)
{
    char **map = malloc(sizeof(char *) * (nb_lines + 3));

    fill_map(map, nb_lines);
    map[nb_lines + 2] = NULL;
    return (map);
}