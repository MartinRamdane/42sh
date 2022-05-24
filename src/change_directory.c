/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** change_directory
*/

#include "my.h"

int check_special_cases(char **env, char **arg)
{
    int val = 0;
    char **env_cp = my_arrcpy(env);
    if (arg[2] != NULL)
        return 0;
    if (arg[1] == NULL)
        return 0;
    if (my_strncmp(arg[1], "~", my_strlen(arg[1])) == 0) {
        char *path = get_env(env_cp, "HOME=");
        update_pwd(env, path);
        return 1;
    }
    val = check_dir_utils(arg, env, env_cp);
    if (val != 0) {
        return val;
    }
    return 0;
}

bool folder_exists(char *path)
{
    DIR *fp;
    fp = opendir(path);
    if (fp == NULL)
        return false;
    if (fp != NULL)
        return true;
}

void update_pwd(char **env, char *new)
{
    char *old_pwd = getcwd(NULL, 0);
    char *new_pwd = new;
    if (new[my_strlen(new) - 1] == '/')
        new[my_strlen(new) - 1] = '\0';
    replace_env(env, "OLDPWD=", old_pwd);
    replace_env(env, "PWD=", new_pwd);
    chdir(new);
}

int change_directory(char **arg, char **env)
{
    int val = 0;
    if (arg[1] == NULL) {
        char *path = get_env(my_arrcpy(env), "HOME=");
        update_pwd(env, path);
        return 0;
    }
    if (arg[2] != NULL) {
        write(2, "cd: Too many arguments.\n", 24);
        return 1;
    }
    if ((val = check_special_cases(env, arg)) != 0)
        return val - 1;
    if (folder_exists(arg[1])) {
        update_pwd(env, arg[1]);
        return 0;
    }
    write_error_cd(arg[1]);
    return 1;
}
