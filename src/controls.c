/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** controls
*/

#include "my.h"

void manage_ctrl_c(int my_signal)
{
    signal(SIGINT, manage_ctrl_c);
    my_putchar('\n');
    my_putstr("$> ");
}

bool file_exists(char *filename)
{
    struct stat buffer;
    return (stat (filename, &buffer) == 0);
}
