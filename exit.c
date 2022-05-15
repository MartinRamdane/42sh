/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** exit
*/

#include "my.h"

int exit_values(char **arg)
{
    if (arg[2] != NULL) {
        my_putstr("exit: Expression Syntax.\n");
        return 1;
    }
    if (arg[1] == NULL) {
        my_putstr("exit\n");
        exit(0);
    }
    if (check_exit_val(arg[1]) != 1) {
        my_putstr("exit: Expression Syntax.\n");
        return 1;
    }
    int exit_val = my_get_nbr(arg[1]);
    my_putstr("exit\n");
    exit(exit_val);
}

int check_exit_val(char *val)
{
    int i = 1;
    int first_nb = 0;
    int my_val = 0;
    if (val[0] >= '0' && val[0] <= '9') {
        first_nb++;
    } else
        return 0;
    while (val[i] != '\0' && my_val == 0) {
        if (val[i] >= '0' && val[i] <= '9')
            my_val = check_exit_utils(val[i]);
        else
            return 0;
        i++;
    }
    if (my_val == 0) {
        return 1;
    }
    return 0;
}

int check_exit_utils(char val)
{
    if (val <= '0' && val >= '9')
        return 1;
    return 0;
}
