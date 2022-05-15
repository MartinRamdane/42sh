/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** shell
*/

#include "my.h"

int exec_shell(t_infos *infos)
{
    char *line = NULL;
    char *tmp2 = NULL;
    size_t len = 0;
    ssize_t size = 0;
    int tty_val = isatty(STDIN_FILENO), val = 0;
    pid_t pid;
    int status;
    while (1) {
        if (tty_val != 0)
            print_prompt(infos->env);
        size = getline(&line, &len, stdin);
        line[my_strlen(line) - 1] = '\0';
        while ((tmp2 = strtok_r(line, ";", &line))) {
            check_withoutpipe(infos, tmp2);
        }
        manage_exit(size, tty_val, infos->return_val);
    }
    my_putstr("exit\n");
}

char **parse_arr(char *line)
{
    char *test = remove_trailing_spaces(line);
    char **arr = arg_to_str(test);
    return arr;
}
