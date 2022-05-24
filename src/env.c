/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** env
*/

#include "my.h"

int my_unsetenv(char **env, char **arg)
{
    int i = 0;
    int j = 1;
    if (arg[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 1;
    }
    if (arg[1][0] == 42) {
        for (; env[i] != NULL; i++) {
            env[i] = NULL;
        }
        return 0;
    }
    for (; arg[j] != NULL; j++) {
        check_env(env, arg[j]);
    }
    return 0;
}

int my_setenv(char **env, char **arg)
{
    int i = my_arrlen(env);
    int j = my_arrlen(arg);
    if (j == 1) {
        print_arg(env);
        return 0;
    }
    if (j == 2) {
        char *var = parse_env_var(env, arg[1]);
        return (replace_env(env, var, NULL));
    }
    if (j == 3) {
        char *var = parse_env_var(env, arg[1]);
        char *val = arg[2];
        return (replace_env(env, var, val));
    }
    if (j > 3)
        my_putstr("setenv: Too many arguments.\n");
    return 1;
}

int replace_env(char **env, char *var, char *val)
{
    int i = 0;
    if (var == NULL)
        return 1;
    char *full_val = malloc(sizeof(char) * 10000);
    if (val == NULL) {
        my_strcpy(full_val, var);
    } else {
        my_strcpy(full_val, var);
        my_strcat(full_val, val);
    }
    for (; env[i] != NULL; i++) {
        if (my_strncmp(env[i], var, my_strlen(var)) == 0) {
            env[i] = full_val;
            return 0;
        }
    }
    env[i] = malloc(sizeof(char) * 10000);
    my_strcpy(env[i], full_val);
    env[i + 1] = NULL;
    return 0;
}

char *parse_env_var(char **env, char *arg)
{
    char *tmp_var = malloc(sizeof(char) * 10000);
    if (arg[0] == '_');
    else if (arg[0] < 65 || arg[0] > 90 && arg[0] < 97 || arg[0] > 122) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        tmp_var = NULL;
        return tmp_var;
    }
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] == '_');
        else if (arg[i] < 48 || arg[i] > 57 && arg[i] < 65
        || arg[i] > 90 && arg[i] < 97 || arg[i] > 122) {
            my_putstr("setenv: Variable name must");
            my_putstr(" contain alphanumeric characters.\n");
            tmp_var = NULL;
            return tmp_var;
        }
    }
    my_strcpy(tmp_var, arg);
    my_strcat(tmp_var, "=");
    return tmp_var;
}
