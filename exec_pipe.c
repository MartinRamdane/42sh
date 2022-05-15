/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-minishell2-adam.elaoumari
** File description:
** exec_pipe
*/

#include "my.h"

void loop_pipe(t_infos *infos)
{
    pid_t p, w;
    int my_pipe[2], status, waitstatus, i = 1, fd_in = 0, return_val = 0;
    int built = -1;
    while (infos->list) {
        if ((built = check_builtin_pipe(infos, infos->list)) != -1)
            return;
        handle_redirections(infos);
        pipe(my_pipe);
        p = fork();
        if (p == 0) {
            my_execpipe(infos, fd_in, my_pipe);
        } else {
            close(my_pipe[1]);
            fd_in = my_pipe[0];
            infos->list = infos->list->next;
        }
    }
    w = waitpid(p, &status, WUNTRACED | WCONTINUED);
    infos->return_val = check_errors(status, p);
}

void my_execpipe(t_infos *infos, int fd_in, int *my_pipe)
{
    int return_val = -3;
    return_val = my_execve_pipe(infos, infos->list, fd_in, my_pipe);
    if (return_val != -1)
        exit (return_val);
    if (handling_folder_files_pipe(infos->list, infos) == 0 &&
    return_val == -1) {
        write(1, infos->list->arg[0], my_strlen(infos->list->arg[0]));
        my_putstr(": Command not found.\n");
        exit(1);
    }
    exit (0);
}

int check_builtin_pipe(t_infos *infos, t_list *node)
{
    int built_return = -1;
    if (node->next == NULL) {
        built_return = make_built(infos->list->arg, infos->env, infos);
        infos->return_val = built_return;
    }
    return built_return;
}
