/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-minishell2-adam.elaoumari
** File description:
** utils_pipes
*/

#include "my.h"

void utils_pipe(t_infos *infos, int run, int pipe_nb)
{
    if (run != pipe_nb) {
        write(2, "Invalid null command.\n", 22);
        infos->return_val = 1;
        return;
    }
    loop_pipe(infos);
    dup2(infos->save_stdin, 0);
    dup2(infos->save_stdout, 1);
    infos->right_type = 0;
    infos->left_type = 0;
}
