/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** err_handling
*/

#include "my.h"

int handling_folder_files(t_infos *infos)
{
    if (access(infos->command, F_OK) == -1 && infos->command[0] == '/') {
        my_putstr(infos->command);
        my_putstr(": Command not found.\n");
        exit(1);
    }
    if (infos->command[0] == '.' || infos->command[0] == '/'
    && file_exists(infos->command) || check_slash(infos->command)) {
        if (execve(infos->command, infos->args, infos->env) == -1) {
            write_error_message(infos->command);
            exit(1);
        }
    }
    if (my_strncmp(infos->command, infos->args[0],
    my_strlen(infos->command)) == 0 && check_slash(infos->command) == 0) {
        my_putstr(infos->command);
        my_putstr(": Command not found.\n");
        exit(1);
    }
    return 0;
}

void write_error_message(char *path)
{
    if (errno == 8) {
        write(1, path, my_strlen(path));
        write(1, ": Exec format error. Wrong Architecture.\n", 41);
    } else {
        write(1, path, my_strlen(path));
        my_putstr(": Command not found.\n");
    }
}

int check_slash(char *arg)
{
    int i = 0;
    while (arg[i] != '\0') {
        if (arg[i] == '/')
            return 1;
        i++;
    }
    return 0;
}

int handling_folder_files_pipe(t_list *list, t_infos *infos)
{
    if (access(infos->list->command, F_OK) == -1
    && infos->list->command[0] == '/') {
        write(2, infos->list->command, my_strlen(infos->list->command));
        write(2, ": Command not found.\n", 21);
        exit(1);
    }
    if (infos->list->command[0] == '.' || infos->list->command[0] == '/'
    && file_exists(infos->list->command) ||
    check_slash(infos->list->command)) {
        if (execve(infos->list->command, infos->list->arg, infos->env) == -1) {
            write_error_message(infos->list->command);
            exit(1);
        }
    }
    return (handling_folder_files_pipe2(list, infos));
}

int handling_folder_files_pipe2(t_list *list, t_infos *infos)
{
    if (my_strncmp(infos->list->command, infos->list->arg[0],
    my_strlen(infos->list->command)) == 0 &&
    check_slash(infos->list->command) == 0) {
        write(2, infos->list->command, my_strlen(infos->list->command));
        write(2, ": Command not found.\n", 21);
        exit(1);
        }
    return 0;
}
