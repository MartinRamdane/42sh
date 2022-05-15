/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** parser
*/

#include "my.h"

int my_checker(char *exec)
{
    if (exec[0] == '\0')
        return 1;
    if (exec[0] == '/')
        return 1;
    if (exec[0] == '.')
        return 1;
    if (my_strncmp(exec, "exit", my_strlen(exec)) == 0)
        return 1;
    if (my_strncmp(exec, "env", my_strlen(exec)) == 0)
        return 1;
    return 0;
}

char *check_path(char **path, char *exec, char **arr)
{
    int fd;
    int i = 0;
    char *tmp = malloc(sizeof(char) * 10000);
    if (my_checker(exec) == 1) {
        return exec;
    }
    while (path[i] != NULL) {
        my_strcpy(tmp, path[i]);
        my_strcat(tmp, "/");
        my_strcat(tmp, arr[0]);
        if (file_exists(tmp)) {
            return tmp;
        }
        i++;
    }
    my_strcpy(tmp, exec);
    return tmp;
}

char **parse_path(char *path, char *delim, char **old)
{
    if (path == NULL)
        return old;
    char *tmp;
    int i = 0;
    char *tmp2 = path;
    char **parsed = malloc(sizeof(char *) * 10000);
    while ((tmp = strtok_r(tmp2, delim, &tmp2))) {
        parsed[i] = malloc(sizeof(char) * 10000);
        parsed[i] = tmp;
        i++;
    }
    parsed[i] = NULL;
    return parsed;
}

char **get_var_env(char **env, char *delim)
{
    char *tmp;
    int i = 0;
    int j = 0;
    char **parsed = malloc(sizeof(char *) * 10000);
    while (env[j] != NULL) {
        char *tmp2 = env[j];
        if (tmp = strtok(tmp2, delim)) {
            parsed[i] = tmp;
            i++;
            j++;
        }
    }
    parsed[i + 1] = NULL;
    return parsed;
}
