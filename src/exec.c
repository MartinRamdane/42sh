/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** exec
*/

#include "my.h"

void print_arg(char **arg)
{
    while (*arg) {
        my_putstr(*arg);
        my_putchar('\n');
        arg++;
    }
}

int exec(t_infos *infos)
{
    pid_t p, w;
    int status;
    int waitstatus;
    int i = 1;
    p = fork();
    if (p != 0) {
        w = waitpid(p, &status, WUNTRACED | WCONTINUED);
        return (check_errors(status, p));
    } else {
        if (handling_folder_files(infos) == 0 &&
        my_execve(infos) == -1) {
            write(1, infos->args[0], my_strlen(infos->args[0]));
            my_putstr(": Command not found.\n");
            exit(1);
        }
    }
}

int my_execve(t_infos *infos)
{
    int return_val = execve(infos->command, infos->args, infos->env);
    return return_val;
}

int my_execve_pipe(t_infos *infos, t_list *node, int fd_in, int *p)
{
    t_list *temp = node;
    dup2(fd_in, 0);
    if (temp->next != NULL)
        dup2(p[1], 1);
    close(p[0]);
    int return_val = -3;
    return_val = make_built(infos->list->arg, infos->env, infos);
    if (return_val >= 0)
        exit(return_val);
    return_val = execve(node->command, node->arg, infos->env);
    if (return_val == -1)
        return (-1);
}
