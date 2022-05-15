/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** catch_errors
*/

#include "my.h"

int check_errors(int status, pid_t p)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV)
            my_putstr("Segmentation fault");
        if (WTERMSIG(status) == SIGFPE)
            my_putstr("Floating exception");
        if (WCOREDUMP(status))
            my_putstr(" (core dumped)\n");
        else
            write(1, "\n", 1);
        return return_value(status);
    }
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
}

int return_value(int sign)
{
    if (sign == 11)
        return 139;
    if (sign == 8)
        return 136;
}
