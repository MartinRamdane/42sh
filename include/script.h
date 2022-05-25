/*
** EPITECH PROJECT, 2022
** script.h
** File description:
** script.h
*/

#include "my.h"

#pragma once

typedef struct l_var {
    char *value;
    char *name;
    struct l_var *next;
} l_var;

int recup_var(char *str, l_var *list_var);
void add_variable(l_var **list, l_var *maillon);
int my_echo(char **str, t_infos *infos);
void echo_args(char *str, t_infos *infos, int flag);
void echo_char_simple(char c);
void echo_char_simple2(char c);
void print_char_simple(char c);
void print_char_simple2(char c);
int my_putstr_echo(char const *str);
void change_end_str(char *str);
int recup_var(char *str, l_var *list_var);
