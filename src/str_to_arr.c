/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-minishell2-adam.elaoumari
** File description:
** str_to_arr
*/

#include "my.h"

int get_words(char *arg)
{
    int words = 1;
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] == ' ')
            words++;
    }
    return words;
}

char **arg_to_str(char *arg)
{
    int words = get_words(arg), nb = 0, y = 0, z = 0;
    char **arr = malloc_arr(words);
    for (int i = 0; arg[i] != '\0';) {
        if (i > 1 && arg[i - 1] == 32 && arg[i] != 32) {
            arr[y][z] = '\0';
            y++;
            z = 0;
        }
        if (arg[i] == 32)
            i++;
        else {
            arr[y][z] = arg[i];
            z++;
            i++;
        }
    }
    return arr;
}
