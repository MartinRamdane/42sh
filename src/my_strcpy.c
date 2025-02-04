/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    if (src == NULL || dest == NULL)
        return NULL;
    int run;
    run = 0;
    while (src[run] != '\0') {
        dest[run] = src[run];
        run = run + 1;
    }
    dest[run] = '\0';
    return (dest);
}

char *my_strcpy_n(char *dest, char *src)
{
    int run = 0;
    while (src[run] != '\n') {
        dest[run] = src[run];
        run = run + 1;
    }
    dest[run] = '\0';
    return (dest);
}

char *my_strcpy_slash(char *dest, char *src)
{
    int run = 0;
    while (src[run] != '/' && src[run] != '\0') {
        dest[run] = src[run];
        run = run + 1;
    }
    dest[run] = '\0';
    return (dest);
}
