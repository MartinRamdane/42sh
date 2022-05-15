/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** utils
*/

#include "my.h"

char **malloc_arr(int words)
{
    int nb = 0;
    char **arr = malloc(sizeof(char *) * words + 1);
    for (int tmp = words; tmp != 0; tmp--) {
        arr[nb] = malloc(sizeof(char) * 1000);
        my_memset(arr[nb], '\0', 1000);
        nb++;
    }
    return arr;
}

int skip_words(int i, char *str)
{
    while (str[i] != '\0') {
        if (cond(str[i]))
            i++;
        else {
            return i;
        }
    }
    return i;
}

int cond(char c)
{
    if (c == ' ' || c == '\n' || c == 9 || c == 10)
        return 1;
    return 0;
}
