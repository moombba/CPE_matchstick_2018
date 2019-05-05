/*
** EPITECH PROJECT, 2019
** in
** File description:
** gale
*/

#include "match.h"

int check_line(int n_l)
{
    int line = 0;
    char *str = 0;
    size_t len = 0;

    write(1, "Line: ", 6);
    if (getline(&str, &len, stdin) == -1)
        return (-2);
    line = my_getnbr(str);
    if (line > n_l || line < 1) {
        my_printf("Error: this line is out of range\n");
        return (-1);
    }
    return (line);
}

int check_matches(int max, int line, char **map, int m_len)
{
    int matches = 0;
    char *str;
    size_t len = 0;

    write(1, "Matches: ", 10);
    if (getline(&str, &len, stdin) == -1)
        return (-2);
    matches = my_getnbr(str);
    if (matches > max || matches < 1) {
        (void) too_much_matches(max);
        return (-1);
    }
    if (matches == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (-1);
    }
    if (count_nchar(map[line], '|', m_len) < matches) {
        my_printf("Error: not enough matches on this line\n");
        return (-1);
    }
    return (matches);
}

int p_trn(char **map, int max, int n_l)
{
    int matches = -1;
    int line = -1;
    int len = calc_len(n_l);

    my_printf("Your turn:\n");
    while (line == -1 || matches == -1) {
        matches = -1;
        line = -1;
        line = check_line(n_l);
        if (line > 0)
            matches = check_matches(max, line, map, len);
        if (line == -2 || matches == -2)
            return (-2);
    }
    remove_stk(map, line, matches);
    my_printf("Player removed %d match(es) from line %d\n", matches, line);
    return (0);
}

int game_master(char **map, int max, int n_l)
{
    int len = calc_len(n_l);
    int trn = 0;

    for (int chk = 0; check_end(map, len) != 0; trn++) {
        disp_map(map, len);
        chk = trn % 2 == 0 ? p_trn(map, max, n_l) : ai_trn(map, max, n_l, len);
        if (trn % 2 == 0 && chk == -2)
            return (0);
    }
    disp_empty_map(len, n_l);
    if (trn % 2 == 0)
        my_printf("I lost... snif... but I'll get you next time!!\n");
    else
        my_printf("You lost, too bad...\n");
    return (trn % 2 == 0 ? 1 : 2);
}
