/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** main
*/

#include "my.h"

void print_prompt(char **env, t_infos *infos)
{
    char *path = my_revstr(getcwd(NULL, 0));
    char *dir = malloc(sizeof(char) * (my_strlen_char(path, '/')));
    dir = my_revstr(my_strcpy_slash(dir, path));
    char *home = get_env(env, "HOME=");
    if (home != NULL) {
        if (my_strcmp(home, dir) == 0) {
            dir[0] = '~'; dir[1] = '\0';
        }
    }
    if (!dir[0])
        dir[0] = '/';
    if (infos->return_val == 0)
        printf(ANSI_COLOR_GREEN"-> ");
    else
        printf(ANSI_COLOR_RED"-> ");
    printf(ANSI_COLOR_CYAN"%s:", dir);
    printf(ANSI_COLOR_RESET" ");
    free(path); free(dir); free(home);
}

int main(int argc, char **argv, char **env)
{
    t_infos *infos = malloc(sizeof(t_infos));
    infos->ac = argc;
    infos->av = argv;
    infos->env = env;
    infos->right_type = 0;
    infos->left_type = 0;
    infos->return_val = 0;
    infos->should_continue = true;
    if (argc == 1) {
        infos->save_stdin = dup(STDIN_FILENO);
        infos->save_stdout = dup(STDOUT_FILENO);
        return exec_shell(infos);
    }
    return 84;
}

void manage_exit(int size, int tty_val, int val)
{
    if (size == -1 && tty_val != 0) {
        my_putstr("exit\n");
        exit(0);
    }
    if (size == -1 && tty_val == 0)
        exit(val);
}
