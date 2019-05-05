/*
** EPITECH PROJECT, 2019
** remove
** File description:
** remove
*/

#include "match.h"

void remove_stk(char **map, int l, int matches)
{
    int lmark = 0;

    for (; map[l][lmark] != '|'; lmark++);
    for (; map[l][lmark + 1] != ' ' && map[l][lmark + 1] != '*'; lmark++);
    for (int count = 0; count != matches; lmark--) {
        map[l][lmark] = ' ';
        count++;
    }
}