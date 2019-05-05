/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** match
*/

#ifndef MATCH_H_
#define MATCH_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

char **create_map(int nb_lines);
void disp_map(char **map, int);
int my_getnbr(char const *str);
int loop(char **map, int max, int nb_lines);
int my_printf(const char *, ...);
void remove_stk(char **map, int line, int matches);
int count_char(char *, char);
int calc_len(int nb_lines);
int count_nchar(char *str, char to_find, int len);
int chek_num_only(char *str);
int count_nchar(char *str, char to_find, int len);
int check_end(char **map, int len);
int ai_trn(char **map, int max, int nb_lines, int);
int game_master(char **, int, int);
void disp_empty_map(int max, int nb_line);
void too_much_matches(int max);

#endif /* !MATCH_H_ */
