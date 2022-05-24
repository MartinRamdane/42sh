/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-minishell2-adam.elaoumari
** File description:
** filesize
*/

#include "my.h"

int get_filesize(char *filename)
{
    struct stat buffer;
    stat (filename, &buffer);
    return (buffer.st_size);
}
