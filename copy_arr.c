/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** copy_arr
*/

#include "my.h"

char **my_arrcpy(char **src)
{
    int i = 0;
    char **arr = malloc(sizeof(char *) * 1000);
    for (; src[i] != NULL; i++) {
        arr[i] = malloc(sizeof(char) * 10000);
        my_strcpy(arr[i], src[i]);
    }
    arr[i] = NULL;
    return arr;
}
