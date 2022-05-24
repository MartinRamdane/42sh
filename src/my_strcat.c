/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** my_strcat
*/
#include "my.h"

char *my_strcat (char *dest, char const *src)
{
    int run = 0;
    int run2 = 0;
    while (dest[run] != '\0') {
        run = run + 1;
    }
    while (src[run2] != '\0') {
        dest[run] = src[run2];
        run2 = run2 + 1;
        run = run + 1;
    }
    dest[run] = '\0';
    return (dest);
}
