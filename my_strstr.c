/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-minishell2-adam.elaoumari
** File description:
** my_strstr
*/

#include "my.h"

char *my_strstr(char *str, const char *to_find)
{
    int i = 0, j = 0;
    if (!to_find)
        return (NULL);
    while (str[i]) {
        while (to_find[j] == str[i + j] && to_find[j])
            j++;
        if (!to_find[j])
            return (str);
        i++;
    }
    return NULL;
}
