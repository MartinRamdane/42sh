/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-minishell2-adam.elaoumari
** File description:
** trailing_spaces
*/

#include "my.h"

void remove_endspaces(char *str)
{
    if (contains_spaces(str) == 0)
        return;
    int i = 0;
    int k = 0;
    while (str[i] != '\0')
        i++;
    i--;
    while (str[i] == 32) {
        str[i] = '\0';
        i--;
    }
}

int contains_spaces(char *str)
{
    int i = 0;
    while (str[i]) {
        if (str[i] == ' ')
            return 1;
        i++;
    }
    return 0;
}
