/*
** EPITECH PROJECT, 2022
** echo.c
** File description:
** echo.c
*/

#include "../include/my.h"
#include "../include/script.h"

void echo_dont_interpret(char *str)
{
    int i = 0;
    while (str[i]) {
        print_char_simple(str[i]);
        i = i + 1;
    }
}

void echo_interpret(char *str)
{
    int i = 0;
    while (str[i]) {
        echo_char_simple(str[i]);
        i = i + 1;
    }
}

void echo_args(char *str, t_infos *infos, int flag)
{
    if (str[0] == '$' && str[1] == '?' && str[2] == '\0') {
        my_put_nbr(infos->return_val);
        return;
    }
    if (flag == 2) {
        echo_dont_interpret(str);
        return;
    }
    my_putstr_echo(str);
    return;
}

int check_echo_flag(char *str, int *i)
{
    if (str[0] == '-' && str[1] == 'n' && str[2] == '\0') {
        *i = *i + 1;
        return 1;
    }
    if (str[0] == '-' && str[1] == 'E' && str[2] == '\0') {
        *i = *i + 1;
        return 2;
    }
    if (str[0] == '-' && str[1] == 'e' && str[2] == '\0') {
        *i = *i + 1;
        return 3;
    }
    return 0;
}

int my_echo(char **str, t_infos *infos)
{
    int i = 1; int flag = check_echo_flag(str[1], &i);
    while (str[i]) {
        echo_args(str[i], infos, i);
        if (str[i + 1])
            my_putstr_echo(" ");
        else if (str[i + 1] == NULL && flag != 1) {
            my_putchar('\n');
        }
        i = i + 1;
    }
    return 0;
}
