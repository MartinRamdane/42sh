/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-minishell2-adam.elaoumari
** File description:
** get_nb_of_pipes
*/

#include "my.h"

int get_nbofpipes(char *str)
{
    int i = 0;
    int pipes = 0;
    while (str[i]) {
        if (str[i] == '|')
            pipes++;
        i++;
    }
    return pipes;
}
