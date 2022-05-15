/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-minishell2-adam.elaoumari
** File description:
** redirection
*/

#include "my.h"

void handle_redirections(t_infos *infos)
{
    if (infos->left_type == 3)
        do_redirect(0, infos->left_redir, 3, infos);
    if (infos->right_type == 1)
        do_redirect(1, infos->right_redir, 1, infos);
    if (infos->right_type == 2) {
        do_redirect(1, infos->right_redir, 2, infos);
    }
}

void do_redirect(int fd, char *path, int val, t_infos *infos)
{
    int my_fd;
    if (val == 1) {
        my_fd = open(infos->right_redir, O_CREAT | O_WRONLY | O_TRUNC,
        S_IRUSR | S_IWUSR);
    }
    if (val == 2)
        my_fd = open(infos->right_redir, O_CREAT | O_RDWR | O_APPEND,
        S_IRUSR | S_IWUSR | O_APPEND);
    if (val == 3)
        my_fd = open(infos->left_redir, O_RDONLY);
    dup2(my_fd, fd);
    close(my_fd);
}
