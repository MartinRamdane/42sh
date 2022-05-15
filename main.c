/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** main
*/

#include "include/my.h"

/*void hide_ctrl(char **env, int tty_val)
{
    if (tty_val == 0)
        return;
    int val = 0;
    char **env_cp = my_arrcpy(env);
    char *path = get_env(env_cp, "PATH=");
    char **parsed = parse_path(path, ":", parsed);
    char *test = remove_trailing_spaces("stty -echoctl");
    char **arr = arg_to_str(test);
    char *tmp = check_path(parsed, arr[0], arr);
    val = make_exec(arr, env, tmp, val);
    signal(SIGINT, manage_ctrl_c);
}*/

void print_prompt(char **env)
{
    my_putstr("$> ");
}

int main(int argc, char **argv, char **env)
{
    t_infos *infos = malloc(sizeof(t_infos));
    infos->ac = argc;
    infos->av = argv;
    infos->env = env;
    infos->right_type = 0;
    infos->left_type = 0;
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
