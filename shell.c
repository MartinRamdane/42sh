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
            double_ampersand(infos, tmp2);
        }
        manage_exit(size, tty_val, infos->return_val);
    }
    my_putstr("exit\n");
}

void double_ampersand(t_infos *infos, char *line)
{
    char *arg;
    int i = 0;
    while (arg = strtok_r(line, "&&", &line)) {
        i++;
        if (i >= 2 && infos->return_val == 0) {
            get_double_pipes(infos, arg);
            i = 1;
        } else if (i < 2)
            get_double_pipes(infos, arg);
    }
}

void get_double_pipes(t_infos *infos, char *line)
{
    char *arg = malloc(sizeof(char) * my_strlen(line));
    int i = 0, j = 0, run = 1;
    while (line[i]) {
        while (line[i] && !check_double_pipes(line, i)) {
            arg[j] = line[i];
            j++;
            i++;
        }
        if (run >= 2 && infos->return_val != 0) {
           check_withoutpipe(infos, arg);
            run = 1;
        } else if (run < 2)
            check_withoutpipe(infos, arg);
        while (line[i] && check_double_pipes(line, i)) {
            i += 2;
        }
        free(arg);
        arg = malloc(sizeof(char) * my_strlen(line));
        j = 0;
        run++;
    }
}

int check_double_pipes(char *line, int i)
{
    if (line[i] == '|' && i + 1 <= my_strlen(line) &&line[i + 1] == '|')
        return 1;
    return 0;
}

char **parse_arr(char *line)
{
    char *test = remove_trailing_spaces(line);
    char **arr = arg_to_str(test);
    return arr;
}
