/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-minishell2-adam.elaoumari
** File description:
** my_memset
*/

#include "my.h"

void my_memset(char *pointer, int nb, int size)
{
    int i = 0;
    while (i != size) {
        pointer[i] = nb;
        i++;
    }
}
