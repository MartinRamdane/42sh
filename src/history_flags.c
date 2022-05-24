/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** history_flags
*/

#include "my.h"

void history_h(void)
{
    FILE *fd = fopen("/tmp/.42sh_history.txt", "r+");
    char *history = NULL;
    size_t size_len = 0;
    while (getline(&history, &size_len, fd) != -1)
        printf("%s", history);
    fclose(fd);
    free(history);
}