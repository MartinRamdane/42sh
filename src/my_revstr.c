/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** reverse a str
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0, len = my_strlen(str) - 1;
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (len >= 0) {
        result[i] = str[len];
        len = len - 1;
        i = i + 1;
    }
    result[i] = '\0';
    return result;
}
