/*
** EPITECH PROJECT, 2019
** tool
** File description:
** tool
*/

#include "match.h"

int chek_num_only(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] > '9' || str[i] < '0') {
            my_printf("Error: invalid input (positive number expected)\n");
            return (-1);
        }
    }
    return (0);
}

int count_nchar(char *str, char to_find, int len)
{
    int count = 0;
    int ite = 0;

    while (ite < len) {
        if (str[ite] == to_find)
            count += 1;
        ite++;
    }
    return (count);
}

int check_end(char **map, int len)
{
    int sum = 0;

    for (int i = 0; map[i]; i++)
        sum += count_nchar(map[i], '|', len);
    return (sum);
}