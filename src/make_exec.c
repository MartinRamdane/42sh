/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** make_exec
*/

#include "my.h"

int make_built(char **arg, char **env, t_infos *infos)
{
    if (my_strncmp(arg[0], "exit", my_strlen(arg[0])) == 0) {
        exit_values(arg);
        return 1;
    }
    if (my_strncmp(arg[0], "env", my_strlen(arg[0])) == 0) {
        print_arg(env);
        return 0;
    }
    if (my_strncmp(arg[0], "unsetenv", my_strlen(arg[0])) == 0) {
        return my_unsetenv(env, arg);
    }
    return make_built_sec(arg, env, infos);
}

int make_built_sec(char **arg, char **env, t_infos *infos)
{
    if (my_strncmp(arg[0], "setenv", my_strlen(arg[0])) == 0) {
        return (my_setenv(env, arg));
    }
    if (my_strncmp(arg[0], "cd", my_strlen(arg[0])) == 0) {
        return change_directory(arg, env);
    }
    return -1;
}

void make_exec(t_infos *infos)
{
    int j = 0;
    if (infos->args[0][0] == '\0') {
        return;
    }
    handle_redirections(infos);
    j = make_built(infos->args, infos->env, infos);
    if (j >= 0) {
        infos->return_val = j;
    } else
        infos->return_val = exec(infos);
}
