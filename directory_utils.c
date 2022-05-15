/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** directory_utils
*/

#include "my.h"

int check_dir_utils(char **arg, char **env, char **env_cp)
{
    if (my_strncmp(arg[1], "-", my_strlen(arg[1])) == 0) {
        char *path = get_env(env_cp, "OLDPWD=");
        char *path2 = get_env(env_cp, "PWD=");
        if (path == NULL || my_strncmp(path, path2, my_strlen(path)) == 0) {
            path = ":";
            write(2, ": ", 2);
            write(2, "No such file or directory\n", 26);
            return 2;
        }
        update_pwd(env, path);
        return 1;
    }
    if (my_strncmp(arg[1], "--", my_strlen(arg[1])) == 0) {
        char *path = get_env(env_cp, "HOME=");
        update_pwd(env, path);
        return 1;
    }
    return 0;
}
