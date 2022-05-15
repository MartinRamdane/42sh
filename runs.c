/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-minishell2-adam.elaoumari
** File description:
** runs
*/

#include "my.h"

void check_withoutpipe(t_infos *infos, char *line)
{
    int i = 0;
    int pipe = 0;
    while (line[i]) {
        if (line[i] == '|')
            pipe++;
        i++;
    }
    if (pipe == 0)
        run_withoutpipe(infos, line);
    if (pipe)
        run_withpipe(infos, line);
}

void run_withoutpipe(t_infos *infos, char *line)
{
    get_redirection(infos, line);
    char **env_cp = my_arrcpy(infos->env);
    char *path = get_path(env_cp, "PATH=", path);
    char **parsed = parse_path(path, ":", parsed);
    infos->args = parse_arr(line);
    infos->command = check_path(parsed, infos->args[0], infos->args);
    make_exec(infos);
    dup2(infos->save_stdin, 0);
    dup2(infos->save_stdout, 1);
    infos->right_type = 0;
    infos->left_type = 0;
}

void check_withpipe(t_infos *infos, char *line)
{
    for (int i = 0; line[i]; i++) {
        if (line[i] == '|')
            run_withpipe(infos, line);
        i++;
    }
    return;

}

void run_withpipe(t_infos *infos, char *line)
{
    char *tmp2 = NULL;
    infos->fd_in = 0;
    infos->list = NULL;
    char *tmp3 = NULL;
    int run = 0, pipe_nb = get_nbofpipes(line) + 1;
    while ((tmp2 = strtok_r(line, "|", &line))) {
        if (!is_viable(tmp2))
            continue;
        get_redirection(infos, tmp2);
        char **env_cp = my_arrcpy(infos->env);
        char *path = get_path(env_cp, "PATH=", path);
        char **parsed = parse_path(path, ":", parsed);
        infos->args = parse_arr(tmp2);
        infos->command = check_path(parsed, infos->args[0], infos->args);
        append(&infos->list, infos->args, infos->command);
        tmp3 = tmp2;
        run++;
    }
    utils_pipe(infos, run, pipe_nb);
}

int is_viable(char *tmp2)
{
    int i = 0;
    while (tmp2[i]) {
        if (tmp2[i] == ' ' || tmp2[i] == 9)
            i++;
        else
            return 1;
    }
    return 0;
}
