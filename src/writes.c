/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** writes
*/

#include "my.h"

void write_error_cd(char *path)
{
    write(2, path, my_strlen(path));
    write(2, ": ", 2);
    write(2, strerror(errno), my_strlen(strerror(errno)));
    write(2, ".\n", 2);
}
